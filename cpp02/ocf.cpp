/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:02:28 by pnolte            #+#    #+#             */
/*   Updated: 2023/04/26 19:36:44 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

  class bad
  {
  public:
    bad(void);                  // default constructor
    bad(const bad&);            // copy constructor
    ~bad(void);                 // destructor
    bad& operator=(const bad&); // copy assignment
  private:
    int* pi;
  };

  bad::bad(void)
   : pi(new int(5)) // allocate new int on heap and
                    // give it the value 5.
  {
  }

  bad::~bad(void)
  {
    delete pi;
  }

  // class declaration, default constructor and
  // destructor are identical and because of that not
  // shown here.

  bad::bad(const bad& b)
   : pi(new int(*b.pi)) // initialize pi as a new int
                        // with the value of b's pi
  { // This guarantees that both the new object and the
  } // original are destructible.

 bad& bad::operator=(const bad& b)
  {
    if (this != &b)
    {
      delete pi;
      pi = new int(*b.pi);
    }
    return *this;
  }
  int main(void)
  {
    bad b1;
    {
      bad b2(b1); // b2.pi now points to its own area.
    } // Here b2 is destroyed, and b2's destructor is
      // called. This means that the memory area
      // pointed to by b2.pi is no longer valid
      // b1.pi is still valid, though.

    bad b3; // Allocate new memory
    b3=b1;  // Deallocate, and allocate new again

    b3=b3; // Whoa!! b3.pi is first deallocated, then
           // b3.pi is allocated again and initialised
           // with the value no longer available!!!
    return 0; // all OK, all objects refer to their own
              // memory, so deallocation is not a
              // problem.
  }
