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
	try
	{
		Bureaucrat b("Too high", 1);
		std::cout << b;
		std::cout << "Incrementing:\n";
		b.incrementGrade();
		std::cout << b;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	
	try
	{
		Bureaucrat b("Too low", 150);
		std::cout << b;
		std::cout << "Decrementing:\n";
		b.decrementGrade();
		std::cout << b;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}

	try
	{
		Bureaucrat b("Increment to highest", 2);
		std::cout << b;
		b.incrementGrade();
		std::cout << b;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	
	try
	{
		Bureaucrat b("Decrement to lowest", 149);
		std::cout << b;
		b.decrementGrade();
		std::cout << b;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}

	try
	{
		Bureaucrat b("Invalid Low Grade", 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	
	try
	{
		Bureaucrat b("Invalid High Grade", 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	return (0);
}