#include "Harl.hpp"

int main()
{
	Harl h;
	h.complain("INFO");
	h.complain("DEBUG");
	h.complain("WARNING");
	h.complain("ERROR");
	h.complain("INVALID");
	return 0;
}