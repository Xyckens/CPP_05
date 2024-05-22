/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:17:42 by fvieira           #+#    #+#             */
/*   Updated: 2023/12/07 17:17:44 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

# include <iostream>
# include <memory>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

private:
	std::string const	name;
	bool				signature;
	int	const			signGrade;
	int	const			execGrade;

public:
	Form();
	Form(std::string const name, int const signGrade, int const execGrade);
	Form(Form const& copy);
	Form& operator=(Form const& other);
	~Form();

	std::string	getName(void) const;
	int			getSignGrade(void) const;
	int			getExecGrade(void) const;
	bool		getSignature(void) const;

	void	beSigned(Bureaucrat b);

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
	
	class FormNotSignedException : public std::exception
	{
	public:
		const char* what() const throw();
	};
};

#endif

