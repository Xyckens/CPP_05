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
	Intern someRandomIntern;
	Form* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");

	Intern someRandomIntern1;
	Form* ppf;
	ppf = someRandomIntern1.makeForm("robotomy request", "Bender");

	Intern someRandomIntern2;
	Form* scf;
	scf = someRandomIntern2.makeForm("robotomy request", "Bender");
	return (0);
}