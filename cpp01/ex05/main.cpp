/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:07:21 by pnolte            #+#    #+#             */
/*   Updated: 2023/04/26 17:07:27 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main( void ) {
    Harl Foo;

    Foo.complain("INFO");
    Foo.complain("DEBUG");
    Foo.complain("WARNING");
    Foo.complain("ERROR");
    return EXIT_SUCCESS;
}

/* ************************************************************************** */
