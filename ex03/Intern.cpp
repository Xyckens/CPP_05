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

Intern& Intern::operator=(Intern const& other)
{
	std::cout << "Intern copy constructor called" << std::endl;
	if (this != &other)
	{
		return (*this);
	}
	return (*this);
}

AForm*	Intern::makeForm(std::string const &name, std::string const &target)
{
	AForm*		(Intern::*fptr[3])(const std::string&)  = {&Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm, &Intern::makePresidentialPardonForm};
	std::string	formList[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm*		form = 0;

	try
	{
			for (int i = 0; i < 3; i++)
		{
			if (formList[i] == name)
			{
				form = (this->*fptr[i])(target);
		  		std::cout << "Intern creates " << name << "." << std::endl;
				return form;
			}
		}
		throw Intern::BadFormException();
	}
	catch(std::exception &e)
	{
		std::cerr << e.what();
	}
	return form;
}

AForm*	Intern::makeShrubberyCreationForm(std::string const &target)
{
	return new ShrubberyCreationForm(target);
}

AForm*	Intern::makeRobotomyRequestForm(std::string const &target)
{
	return new RobotomyRequestForm(target);
}

AForm*	Intern::makePresidentialPardonForm(std::string const &target)
{
	return new PresidentialPardonForm(target);
}

const char *Intern::BadFormException::what() const throw()
{
	return ("Couldn't create the appropriate Form like that.\n");
}

Intern::~Intern()
{
	std::cout << "Default Intern Destructor called\n";
}	
