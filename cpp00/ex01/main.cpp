/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:15:09 by pnolte            #+#    #+#             */
/*   Updated: 2023/04/13 17:38:34 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	bool		exit = false;
	std::string	line;

	while (exit != true)
	{
		std::getline(std::cin, line);
		if (line.empty() == false)
		{
			if (line )

			std::cout << line << std::endl;
		}
	}
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
