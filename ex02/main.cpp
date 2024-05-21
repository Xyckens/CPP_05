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
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	
	std::cout << "\n....................................................\n";
	std::cout << "PresidentialPardonForm" << std::endl;
	std::cout << "....................................................\n";
	Bureaucrat Frank("Frank", 5);
	std::cout << Frank;
	AForm *PresForm = new PresidentialPardonForm("target");
	{
		try
		{
			std::cout << "\n\t\tTest: Execute form but Not signed\n\n";
			Frank.executeForm(*PresForm);
			
			std::cout << "\n\t\tTest: Execute form but Grade lower\n\n";
			Frank.signForm(*PresForm);
			Frank.executeForm(*PresForm);
			
			std::cout << "\n\t\tTest: Execute Form\n\n";
			Frank.incrementGrade();
			Frank.executeForm(*PresForm);
		}
		catch (std::exception &e)
		{
			std::cout << "Error!" << e.what() << std::endl;
		}
	}
	std::cout << "\n....................................................\n\n";
	std::cout << "RobotomyRequestForm" << std::endl;
	std::cout << "....................................................\n\n";
	Bureaucrat Paul("Paul", 46);
	std::cout << Paul;
	AForm *B = new RobotomyRequestForm();
	{
		try
		{
			std::cout << "\n\t\tTest: Execute form but Not signed\n\n";
			Paul.executeForm(*B);
			
			std::cout << "\n\t\tTest: Execute form but Grade lower\n\n";
			Paul.signForm(*B);
			Paul.executeForm(*B);
			
			std::cout << "\n\t\tTest: Execute Form\n\n";
			Paul.incrementGrade();
			Paul.executeForm(*B);
		}
		catch (std::exception &e)
		{
			std::cout << "Error!" << e.what() << std::endl;
		}
	}
	std::cout << "\n....................................................\n\n";
	std::cout << "ShrubberyCreationForm" << std::endl;
	std::cout << "....................................................\n\n";
	Bureaucrat John("John", 138);
	std::cout << John;
	AForm *C = new ShrubberyCreationForm("Christmas");
	{
		try
		{
			std::cout << "\n\t\tTest: Execute form but Not signed\n\n";
			John.executeForm(*C);
			
			std::cout << "\n\t\tTest: Execute form but Grade lower\n\n";
			John.signForm(*C);
			John.executeForm(*C);
			
			std::cout << "\n\t\tTest: Execute Form\n\n";
			John.incrementGrade();
			John.executeForm(*C);
		}
		catch (std::exception &e)
		{
			std::cout << "Error!" << e.what() << std::endl;
		}
	}
	delete PresForm;
	delete B;
	delete C;
	return (0);
}