#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
	
	private:
		int value;
		static const int bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &src);
		Fixed &operator = (const Fixed &src);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
};


#endif