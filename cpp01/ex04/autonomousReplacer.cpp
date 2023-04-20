/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autonomousReplacer.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:18:18 by pnolte            #+#    #+#             */
/*   Updated: 2023/04/20 16:47:08 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

#include "autonomousReplacer.hpp"

Foo::Foo(char *input[]) : filename_(input[1]), s1_(input[2]), s2_(input[3]) {}

Foo::~Foo(void) {}

bool    OpenCopyFile() {
    ofstream file;

    file.open(this->filename_);
}

bool    AutonomousReplacer(char *input[]) {
    Foo f = Foo(input);

    f.OpenCopyFile();
    return EXIT_SUCCESS;
}
