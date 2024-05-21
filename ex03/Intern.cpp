/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:16:05 by fvieira           #+#    #+#             */
/*   Updated: 2023/07/03 19:16:10 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Default Intern Constructor called\n";
}

Intern::Intern(const Intern& copy)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = copy;
}

AForm	Intern::*makeForm(std::string &name, const std::string &target)
{
	AForm*		(Intern::*fptr[3])(std::string&) const = {&Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm, &Intern::makePresidentialPardonForm};
	std::string	formList[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm*		form = 0;
	std::string trans = std::transform(name.begin(), name.end(), name.begin(), ::tolower);

	for (int i = 0; i < 3; i++)
	{
		if (formList[i] == trans)
		{
			form = (this->*fptr[i])(target);
	  		std::cout << "Intern creates " << name << "." << std::endl;
			return form;
		}
	}
	throw Intern::InvalidFormCreation();
	return form;
}

AForm	Intern::*makeShrubberyCreationForm(std::string const &target) const
{
	return new ShrubberyCreationForm(target);
}

AForm	Intern::*makeRobotomyRequestForm(std::string const &target) const
{
	return new RobotomyRequestForm(target);
}

AForm	Intern::*makePresidentialPardonForm(std::string const &target) const
{
	return new PresidentialPardonForm(target);
}

const char *Intern::BadFormException::what() const throw()
{
	return ("Couldn't create the appropriate form like that.\n");
}

Intern::~Intern()
{
	std::cout << "Default Intern Destructor called\n";
}	
