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
#include "Intern.hpp"

int main(void)
{
	std::cout << "\n\t\t Good request 1:\n";
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	delete rrf;

	std::cout << "\n\t\t Good request 2:\n";
	Intern someRandomIntern1;
	AForm* ppf;
	ppf = someRandomIntern1.makeForm("shrubbery creation", "Fry");
	delete ppf;

	std::cout << "\n\t\t Good request 3:\n";
	Intern someRandomIntern2;
	AForm* scf;
	scf = someRandomIntern2.makeForm("presidential pardon", "Professor Farnsworth");
	delete scf;

	std::cout << "\n\t\t Good request 4:\n";
	Intern someRandomIntern3;
	AForm* random;
	random = someRandomIntern2.makeForm("Confused form", "BRo");
	delete random;

	return (0);
}