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
		Fixed(const int input_num);
		Fixed(const float input_num);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
};


#endif