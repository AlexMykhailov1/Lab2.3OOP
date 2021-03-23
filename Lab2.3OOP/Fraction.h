// Fraction.h

#pragma once
#include <sstream>
#include <string>

using namespace std;

class Fraction
{
private:
	long int i;
	unsigned short f;
public:
	long int GetI() const { return i; };
	unsigned short GetF() const { return f; };
	void SetI(long int);
	void SetF(unsigned short);

	Fraction();
	Fraction(long int, unsigned short);
	Fraction(const Fraction&);
	~Fraction();

	operator std::string() const;

	Fraction& operator ++();
	Fraction& operator --();
	Fraction operator ++(int);
	Fraction operator --(int);

	friend ostream& operator <<(ostream&, const Fraction&);
	friend istream& operator >>(istream&, Fraction&);

	friend void Compare(Fraction, Fraction);
	friend Fraction Substract(Fraction, Fraction);
};

