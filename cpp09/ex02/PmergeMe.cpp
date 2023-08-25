/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phipno <phipno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:59:59 by pnolte            #+#    #+#             */
/*   Updated: 2023/08/26 01:03:16 by phipno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <iostream>
#include <vector>
#include <list>

Sort::Sort() {
  
}

Sort::Sort(const Sort &Src) {
  *this = Src;
}

Sort::~Sort() {
  
}

Sort& Sort::operator=(const Sort &Src) {
  if (this != &Src) {
    this->_VecNbr = Src._VecNbr;
    this->_vec_time_sort = Src._vec_time_sort;
    this->_list_time_sort = Src._list_time_sort;
    this->_ListNbr = Src._ListNbr;
  }
  return *this;
}

void  Sort::printThatShit() {
  std::cout << "Before: ";
  std::cout << "After: ";
  std::cout << "Time to process a range of " << this->_VecNbr.size()
            << "with std::vector : " << this->_vec_time_sort << " us" << std::endl;
  std::cout << "Time to process a range of " << this->_ListNbr.size()
            << "with std::ist : " << this->_list_time_sort << " us" << std::endl;            
}

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>

using namespace std;

// Split into pairs
vector<vector<int> > createPairs(vector<int> &a) {
    vector<vector<int> > splitArray;
    vector<int> tempArray;

    for (size_t i = 0; i < a.size(); ++i) {
        if (tempArray.size() == 1) {
            tempArray.push_back(a[i]);
            splitArray.push_back(tempArray);
            tempArray.clear();
        } else if (splitArray.size() * 2 == a.size() - 1) {
            splitArray.push_back(vector<int>{a[i]});
        } else if (tempArray.empty()) {
            tempArray.push_back(a[i]);
        }
    }

    return splitArray;
}

// Sort all the pairs
vector<vector<int> > sortEachPair(vector<vector<int> > &splitArray) {
    for (vector<int> &pair : splitArray) {
        if (pair.size() != 1 && pair[0] > pair[1]) {
            swap(pair[0], pair[1]);
        }
    }
    return splitArray;
}

// Recursive function to generate nth Jacobsthal number
int jacobsthal(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

// Recursively sort the larger set of elements into sorted set
void sortByLargerValue(vector<vector<int> > &sortedSplitArray) {
    for (vector<int> &pair : sortedSplitArray) {
        sort(pair.begin(), pair.end(), greater<int>());
    }
}

// Build the sequence of valid Jacobsthal numbers
vector<int> buildJacobInsertionSequence(vector<int> &array) {
    vector<int> jacobInsertionSequence;
    int jacobIndex = 3;

    while (jacobsthal(jacobIndex) < static_cast<int>(array.size()) - 1) {
        jacobInsertionSequence.push_back(jacobsthal(jacobIndex));
        ++jacobIndex;
    }

    return jacobInsertionSequence;
}

// Entry function to recursively sort pairs by their higher value
void insertionSortPairs(vector<vector<int> > &A, int n) {
    if (n < 1) return;
    insertionSortPairs(A, n - 1);
    vector<int> element = A[n];
    int i = n - 1;
    while (i >= 0 && element[1] >= A[i][1]) {
        A[i + 1] = A[i];
        --i;
    }
    A[i + 1] = element;
}

// Create Sequence
vector<int> createS(vector<vector<int> > &sortedSplitArray, int straggler, bool printComparisonEstimation) {
    vector<int> S, pend;
    int comparisonsMade = 0;

    for (const vector<int> &pair : sortedSplitArray) {
        S.push_back(pair[1]);
        pend.push_back(pair[0]);
    }

    S.insert(S.begin(), pend[0]);

    int iterator = 0;
    int jacobIndex = 3;
    vector<int> indexSequence = {1};
    string last = "default";

    vector<int> jacobInsertionSequence = buildJacobInsertionSequence(pend);

    while (iterator <= static_cast<int>(pend.size())) {
        int item;
        if (!jacobInsertionSequence.empty() && last != "jacob") {
            item = pend[jacobInsertionSequence[0] - 1];
            jacobInsertionSequence.erase(jacobInsertionSequence.begin());
            last = "jacob";
        } else {
            if (iterator >= 1 && find(indexSequence.begin(), indexSequence.end(), iterator) != indexSequence.end()) {
                ++iterator;
            }
            item = pend[iterator - 1];
            indexSequence.push_back(iterator);
            last = "not-jacob";
        }

        int insertionPoint = lower_bound(S.begin(), S.end(), item, greater<int>()) - S.begin();

        S.insert(S.begin() + insertionPoint, item);

        ++iterator;
        ++jacobIndex;
        comparisonsMade += 2;
    }

    if (straggler) {
        int insertionPoint = lower_bound(S.begin(), S.end(), straggler, greater<int>()) - S.begin();
        S.insert(S.begin() + insertionPoint, straggler);
        comparisonsMade += 2;
    }

    if (printComparisonEstimation) {
        cout << "Approximate Comparisons Made:" << endl;
        cout << comparisonsMade << endl;
    }

    return S;
}

vector<int> mergeInsertionSort(vector<int> &A) {
    cout << "Starting Array:" << endl;
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;

    bool hasStraggler = A.size() % 2 != 0;
    int straggler = 0;

    if (hasStraggler) {
        straggler = A[A.size() - 1];
        A.pop_back();
    }

    vector<vector<int> > splitArray = createPairs(A);
    vector<vector<int> > sortedSplitArray = sortEachPair(splitArray);
    sortByLargerValue(sortedSplitArray);
    insertionSortPairs(sortedSplitArray, sortedSplitArray.size() - 1);

    vector<int> S = createS(sortedSplitArray, straggler, true);

    cout << "Sorted Array:" << endl;
    for (int num : S) {
        cout << num << " ";
    }
    cout << endl;

    return S;
}


/* ************************************************************************** */

