/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:17:36 by fvieira           #+#    #+#             */
/*   Updated: 2023/12/07 17:17:38 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("standard"), signature(false), signGrade(75), execGrade(75)
{
	std::cout << "Default Constructor called\n";
}

Form::Form(const Form& copy): name(copy.name), signature(copy.signature), 
							  signGrade(copy.signGrade), execGrade(copy.execGrade)
{
	std::cout << "Form copy constructor called" << std::endl;
}

int	Form::getSignGrade(void) const
{
	return (this->signGrade);
}

int	Form::getExecGrade(void) const
{
	return (this->execGrade);
}

bool	Form::getSignature(void) const
{
	return (this->signature);
}

std::string	Form::getName(void) const
{
	return (this->name);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("The grade is too high.\n");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("The grade is too low.\n");
}

const char *Form::FormNotSignedException::what() const throw()
{
	return ("The form hasn't been signed.\n");
}

Form::Form(std::string const name, int const signGrade, int const execGrade): 
	name(name), signature(false), signGrade(signGrade), execGrade(execGrade)
{
	try
	{
		if (signGrade > 150)
			throw Form::GradeTooLowException();
		else if (signGrade < 1)
			throw Form::GradeTooHighException();
		if (execGrade > 150)
			throw Form::GradeTooLowException();
		else if (execGrade < 1)
			throw Form::GradeTooHighException();
		std::cout << "Form constructor with input variables.\n";
	}
	catch(std::exception &e)
	{
		std::cerr << "Error creating Form " << e.what();
	}
}

void	Form::beSigned(Bureaucrat b)
{
	try
	{	
		if (b.getGrade() <= this->signGrade)
		{
			this->signature = true;
			std::cout << this->name << " was signed by " << b.getName() << std::endl;
		}
		else
		{
			this->signature = false;
			throw Form::GradeTooLowException();
		}
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
	}
}

Form& Form::operator=(Form const& other)
{
	std::cout << "Form Copy Assignment operator.\n";
	if (this == &other)
		return (*this);
	return (*this);
}

Form::~Form()
{
	std::cout << "Default Form Destructor called\n";
}	
