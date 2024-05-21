/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:52:59 by fvieira           #+#    #+#             */
/*   Updated: 2023/12/10 18:53:01 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) :
	AForm(copy)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
		this->target = other.target;
	return (*this);
}

void	ShrubberyCreationForm::executeForm() const
{
	std::ofstream file;
	std::string fileName = this->target + "_shrubbery";

	file.open(fileName.c_str(), std::ios::out);
	if (!file.is_open())
	{
		std::cout << fileName << " opening failed.\n";
		return ;
	}

	file << "             /\\ \n"
			"            <  >\n"
			"             /\\ \n"
			"            /  \\ \n"
			"           /++++\\ \n"
			"          /  ()  \\ \n"
			"          /      \\ \n"
			"         /~`~`~`~`\\ \n"
			"        /  ()  ()  \\ \n"
			"        /          \\ \n"
			"       /*&*&*&*&*&*&\\ \n"
			"      /  ()  ()  ()  \\ \n"
			"      /              \\ \n"
			"     /++++++++++++++++\\ \n"
			"    /  ()  ()  ()  ()  \\ \n"
			"    /                  \\ \n"
			"   /~`~`~`~`~`~`~`~`~`~`\\ \n"
			"  /  ()  ()  ()  ()  ()  \\ \n"
			"  /*&*&*&*&*&*&*&*&*&*&*&\\ \n"
			" /                        \\ \n"
			"/,.,.,.,.,.,.,.,.,.,.,.,.,.\\ \n"
			"           |   | \n"
			"          |`````| \n"
			"          \\_____/ \n";
	file.close();
	std::cout << fileName << " has been created\n";
}
