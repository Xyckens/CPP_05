/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:15:38 by fvieira           #+#    #+#             */
/*   Updated: 2023/07/03 19:15:40 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{

	Bureaucrat a1;
	std::cout << a1;
	
	Bureaucrat a("Too high", 1);
	std::cout << a;
	std::cout << "Incrementing:\n";
	a.incrementGrade();
	std::cout << a << std::endl;

	Bureaucrat b("Too low", 150);
	std::cout << b;
	std::cout << "Decrementing:\n";
	b.decrementGrade();
	std::cout << b << std::endl;
	
	Bureaucrat c("Increment to highest", 2);
	std::cout << c;
	c.incrementGrade();
	std::cout << c << std::endl;
	
	Bureaucrat e("Decrement to lowest", 149);
	std::cout << e;
	e.decrementGrade();
	std::cout << e << std::endl;

	Bureaucrat f("Invalid Low Grade", 0);

	Bureaucrat g("Invalid High Grade", 151);

	Bureaucrat h("Original", 54);
	std::cout << h;
	Bureaucrat i("To copy", 43);
	std::cout << i;
	h = i;
	std::cout << h;
	return (0);
}