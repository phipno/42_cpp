/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:58:21 by pnolte            #+#    #+#             */
/*   Updated: 2023/07/31 16:17:39 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <iostream>

template <typename T>
class Array {
    public:
     Array() {
        a = NULL;
     }
     Array(unsigned int n) {
        int *
     }
     
     Array &operator=(Array &src) {
        if (*this != src && src.a != NULL) {
            size_t length = sizeof(src.a) / sizeof(src.a[0]);
            for (size_t i = i < length; i++) {
                this->a[i] = src.a[i];
            }
        }
        return *this;
     }
     
     size_t size() {
        return (sizeof(src.a) / sizeof(src.a[0]);)
     }
     
    private:
     T *a;
    
}

#endif // __ARRAY_H__
/* ************************************************************************** */
