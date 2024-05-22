/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:16:05 by fvieira           #+#    #+#             */
/*   Updated: 2023/07/03 19:16:10 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name(""), grade(75)
{
	std::cout << "Default Constructor called\n";
}

void	Bureaucrat::incrementGrade(void)
{
	try
	{
		if (this->grade == 1)
			throw Bureaucrat::GradeTooHighException();
		else
			this->grade -= 1;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
}

void	Bureaucrat::decrementGrade(void)
{
	try
	{
		if (this->grade == 150)
			throw Bureaucrat::GradeTooLowException();
		else
			this->grade += 1;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy): name(copy.name), grade(copy.grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

int	Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

std::string	Bureaucrat::getName(void) const
{
	return (this->name);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The grade is too high.\n");
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The grade is too low.\n");
}

Bureaucrat::Bureaucrat(const std::string name, int grade): name(name)
{
	try
	{
		if (grade >= 1 && grade <= 150)
			this->grade = grade;
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			throw Bureaucrat::GradeTooHighException();
	}
	catch (std::exception& e)
	{
		std::cerr << "Cant create this bureaucrat: " << e.what();
	}
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& other)
{
	std::cout << "Bureaucrat Copy Assignment operator.\n";
	if (this != &other)
	{
		this->grade = other.grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Default Destructor called\n";
}	

std::ostream& operator<<(std::ostream& os, const Bureaucrat &other)
{
	os << other.getName() << ", bureaucrat grade " << other.getGrade() << ".\n";
	return (os);
}

