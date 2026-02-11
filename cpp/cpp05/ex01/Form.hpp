#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <stdexcept>
#include <iostream>

class Bureaucrat;

class Form {
	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;

	public:
		Form();
		Form(const std::string name, int gradeToSign, int gradeToExecute);
		Form(const Form& src);
		Form& operator=(const Form& src);
		virtual ~Form();

		std::string getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		bool getIsSigned() const;

		void beSigned(const Bureaucrat& b);


	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Grade is too high!";
			}
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Grade is too low!";
			}
	};
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif