/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:17:42 by fvieira           #+#    #+#             */
/*   Updated: 2023/12/07 17:17:44 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

# include <iostream>
# include <memory>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{

private:
	std::string const	name;
	bool				signature;
	int	const			signGrade;
	int	const			execGrade;

public:
	AForm();
	AForm(std::string const name, int const signGrade, int const execGrade);
	AForm(const AForm& copy);
	AForm& operator=(AForm const& other);
	~AForm();

	std::string	getName(void) const;
	int			getSignGrade(void) const;
	int			getExecGrade(void) const;
	bool		getSignature(void) const;

	void	beSigned(Bureaucrat b);
	virtual void	executeForm(AForm const & form) = 0;
	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw();
	};
};

#endif

