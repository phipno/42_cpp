/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autonomousReplacer.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:18:18 by pnolte            #+#    #+#             */
/*   Updated: 2023/04/20 19:29:23 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "autonomousReplacer.hpp"

Foo::Foo(char *input[]) : filename_(input[1]), s1_(input[2]), s2_(input[3]) {}

Foo::~Foo(void) {}

int    Foo::OpenCopyData() {
    std::ifstream       in_file;
    std::stringstream   str_stream;

    in_file.open(this->filename_);
    // if ( )
    //     std::cerr << "File cant be read from!" << std::endl;
    //     return EXIT_FAILURE;
    str_stream << in_file.rdbuf();
    this->str_ = str_stream.str();
    return EXIT_SUCCESS;
}

std::string Foo::get_str() { return this->str_; }

bool    AutonomousReplacer(char *input[]) {
    Foo f = Foo(input);

    f.OpenCopyData();
    std::cout << f.get_str();
    return EXIT_SUCCESS;
}
