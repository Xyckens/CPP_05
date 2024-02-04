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

Bureaucrat::Bureaucrat() : name("Bob"), grade(75)
{
	std::cout << "Default Bureaucrat Constructor called\n";
}

void	Bureaucrat::incrementGrade(void)
{
	if (this->grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade -= 1;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade += 1;
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

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = copy;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): name(name)
{
	if (grade >= 1 && grade <= 150)
		this->grade = grade;
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::signForm(Form form)
{
	if (form.getSignGrade() >= this->grade)
		std::cout << this->name << " signed " << form.getName() << " form.\n";
	else
		std::cout << this->name << " couldn't sign " << form.getName()
		<< " because the grade is too low.\n";
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& other)
{
	std::cout << "Bureaucrat Copy Assignment operator.\n";
	if (this == &other)
		return (*this);
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Default Bureaucrat Destructor called\n";
}	

std::ostream& operator<<(std::ostream& os, const Bureaucrat &other)
{
	os << other.getName() << ", bureaucrat grade " << other.getGrade() << ".\n";
	return (os);
}
