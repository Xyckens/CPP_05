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
#include "Form.hpp"

int main(void)
{
	try
	{
		Bureaucrat tester("Jebediah", 10);
		std::cout << tester;
		Form form("Standard", 10, 15);

		form.beSigned(tester);
		tester.signForm(form);
	}
	catch(std::exception &e)
	{
		std::cout << std::endl << e.what() << std::endl;
	}
	try
	{
		std::cout << "\nInvalid grade form:\n";
		Form form("Too high", 0, 15);
	}
	catch(std::exception &e)
	{
		std::cout << std::endl << e.what() << std::endl;
	}
	try
	{
		Form form1("Too low", 200, 15);
	}
	catch(std::exception &e)
	{
		std::cout << std::endl << e.what() << std::endl;
	}
	try
	{
		Form form2("Too high 2", 15, 0);
	}
	catch(std::exception &e)
	{
		std::cout << std::endl << e.what() << std::endl;
	}
	try
	{
		Form form3("Too low 2", 15, 200);
	}
	catch(std::exception &e)
	{
		std::cout << std::endl << e.what() << std::endl;
	}
	try
	{
		std::cout << "\nCant sign this form:\n";
		Bureaucrat tester("Jebediah", 20);
		Form form("Standard", 15, 15);
		std::cout << tester;

		form.beSigned(tester);
		tester.signForm(form);
	}
	catch(std::exception &e)
	{
		std::cout << std::endl << e.what() << std::endl;
	}
	try
	{
		Bureaucrat tester("Jebediah", 20);
		Form form("Standard", tester.getGrade(), 15);
		std::cout << tester;

		form.beSigned(tester);
		tester.signForm(form);
	}
	catch(std::exception &e)
	{
		std::cout << std::endl << e.what() << std::endl;
	}
	return (0);
}