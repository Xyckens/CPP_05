/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:15:59 by fvieira           #+#    #+#             */
/*   Updated: 2023/07/03 19:16:00 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>
# include <memory>
# include "Form.hpp"

class Form;

class Bureaucrat
{

private:
	std::string const	name;
	int					grade;

public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat& operator=(Bureaucrat const& other);
	~Bureaucrat();

	std::string	getName(void) const;
	
	int	getGrade(void) const;

	void	incrementGrade(void);
	void	decrementGrade(void);

	void	signForm(Form form);
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

std::ostream& operator<<(std::ostream& os, Bureaucrat const& other);

#endif
