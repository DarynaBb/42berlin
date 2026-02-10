#include "Bureaucrat.hpp"

int main() {
	try {
		std::cout << "== Grade to high ==" << std::endl;
		Bureaucrat bob("Bob", 2);
		std::cout << bob << std::endl;
		bob.incrementGrade();
		std::cout << bob << std::endl;
		bob.incrementGrade();
	}
	catch (std::exception &e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "== Grade to low ==" << std::endl;
		Bureaucrat jenny("Jenny", 148);
		std::cout << jenny << std::endl;
		jenny.decrementGrade();
		jenny.decrementGrade();
		std::cout << jenny << std::endl;
		jenny.decrementGrade();
	}
	catch (std::exception &e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "== Error in parameters ==" << std::endl;
		Bureaucrat j("J", 167);
		std::cout << j << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "== Error in parameters ==" << std::endl;
		Bureaucrat j("J", 167);
		std::cout << j << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	return 0;
}