/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:48:58 by pnolte            #+#    #+#             */
/*   Updated: 2023/07/12 18:11:33 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BASE_H__
#define __BASE_H__

class Base {
    public:
     virtual ~Base();
};

class A : public Base{};

class B : public Base{};

class C : public Base{};

Base    *genrate(void);
void    identify(Base *p);
void    identify(Base &p);

#endif // __BASE_H__
/* ************************************************************************** */
