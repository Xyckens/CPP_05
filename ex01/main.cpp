/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:15:38 by fvieira           #+#    #+#             */
/*   Updated: 2023/07/03 19:15:40 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
		Bureaucrat tester("Jebediah", 10);
		std::cout << tester;
		Form jeb("Standard", 10, 15);

		jeb.beSigned(tester);
		tester.signForm(jeb);
	
		std::cout << "\n\t\tInvalid grade form:\n";
		Form form("Too high", 0, 15);
	
		Form form1("Too low", 200, 15);
	
		Form form2("Too high 2", 15, 0);
	
		Form form3("Too low 2", 15, 200);
	
		std::cout << "\n\t\tCant sign this form:\n";
		Bureaucrat tester2("Carl", 20);
		Form stan("Standard", 15, 15);
		std::cout << tester2;

		tester2.signForm(stan);
	
		Bureaucrat tester3("George", 20);
		Form ai("Standard", tester3.getGrade(), 15);
		std::cout << tester3;

		tester3.signForm(ai);
	
	return (0);
}