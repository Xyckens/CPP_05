/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:15:59 by fvieira           #+#    #+#             */
/*   Updated: 2023/07/03 19:16:00 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

# include "AForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern& copy);
	Intern& operator=(Intern const& other);
	~Intern();
	
	AForm	*makeForm(std::string const &name, std::string const &target);
	AForm	*makeShrubberyCreationForm(std::string const &target) const;
	AForm	*makeRobotomyRequestForm(std::string const &target) const;
	AForm	*makePresidentialPardonForm(std::string const &target) const;

	class	BadFormException: public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

}

#endif
