/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:17:36 by fvieira           #+#    #+#             */
/*   Updated: 2023/12/07 17:17:38 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("standard"), signature(false), signGrade(75), execGrade(75)
{
	std::cout << "Default Constructor called\n";
}

AForm::AForm(const AForm& copy)
{
	std::cout << "AForm copy constructor called" << std::endl;
	*this = copy;
}

int	AForm::getSignGrade(void) const
{
	return (this->signGrade);
}

int	AForm::getExecGrade(void) const
{
	return (this->execGrade);
}

bool	AForm::getSignature(void) const
{
	return (this->signature);
}

std::string	AForm::getName(void) const
{
	return (this->name);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("The grade is too high.\n");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("The grade is too low.\n");
}

AForm::AForm(std::string const name, int const signGrade, int const execGrade): 
	name(name), signature(false), signGrade(signGrade), execGrade(execGrade)
{
	if (signGrade > 150)
		throw AForm::GradeTooLowException();
	else if (signGrade < 1)
		throw AForm::GradeTooHighException();

	if (execGrade > 150)
		throw AForm::GradeTooLowException();
	else if (execGrade < 1)
		throw AForm::GradeTooHighException();
}

void	AForm::beSigned(Bureaucrat b)
{
	if (b.getGrade() <= this->signGrade)
		this->signature = true;
	else
		throw AForm::GradeTooLowException();
}
void	AForm::executeForm(AForm const & form)
{

}

AForm& AForm::operator=(AForm const& other)
{
	std::cout << "AForm Copy Assignment operator.\n";
	if (this == &other)
		return (*this);
	return (*this);
}

AForm::~AForm()
{
	std::cout << "Default AForm Destructor called\n";
}	
