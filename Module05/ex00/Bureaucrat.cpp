/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:32:45 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/26 20:31:01 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Mr. Nobody"), _grade(150) {
	std::cout << "====default constructor " << _name << "====" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "====destructor " << _name << "====" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs) : \
			_name(rhs._name), _grade(rhs._grade) {
	std::cout << "====copy constructor " << _name << "====" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	std::cout <<  "====constructor " << _name << "====" << std::endl;
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	else
		this->_grade = grade;
}
Bureaucrat& 	Bureaucrat::operator=(const Bureaucrat& rhs) {
	if (this != &rhs)
		this->_grade = rhs._grade;
	return *this;
}

std::string Bureaucrat::getName() const {
	return this->_name;
}

int	Bureaucrat::getGrade() const {
	return this->_grade;
}

void	Bureaucrat::incrementGrade() {
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade() {
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}

void	signForm() {
	
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("grade is too low");
}

std::ostream & operator<<(std::ostream & out, const Bureaucrat& rhs) {
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return out;
}