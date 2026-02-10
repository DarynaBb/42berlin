#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default Bureaucrat"), grade(1)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
};

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Bureaucrat " << this->getName() << " constructor called" << std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat& src) : name(src.name), grade(src.grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
	if (this != &src)
		this->grade = src.grade;
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::decrementGrade()
{
	if (grade + 1 <= 150)
		grade++;
	else
		throw Bureaucrat::GradeTooLowException();
}
void Bureaucrat::incrementGrade()
{
	if(grade - 1 >= 1)
		grade--;
	else
		throw Bureaucrat::GradeTooHighException();
}


std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureacrat) {
	out << bureacrat.getName() << ", bureaucrat grade " << bureacrat.getGrade() << ".";
	return out;
}