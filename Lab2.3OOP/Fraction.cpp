// Fraction.cpp

#pragma once

#include "Fraction.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Fraction::Fraction()
	: i(0), f(0)
{}

Fraction::Fraction(long int i, unsigned short f) {
	SetI(i);
	SetF(f);
}

Fraction::Fraction(const Fraction& F) {
	*this = F;
}

Fraction::~Fraction(){}

void Fraction::SetI(long int value) {
	i = value;
}

void Fraction::SetF(unsigned short value) {
	f = value;
}

string FormatFractional(unsigned short f) {
	stringstream s;

	if (f < 10) {
		s << "00" << f;
	}
	else if (f > 9 && f < 100) {
		s << "0" << f;
	}
	else
		s << f;
	return s.str();
}

Fraction::operator std::string() const {
	stringstream sout;
	string s = FormatFractional(f);
	sout << i << "," << s << endl;
	return sout.str();
}

Fraction& Fraction::operator ++() {
	++i;
	return *this;
}

Fraction& Fraction::operator --() {
	--i;
	return *this;
}

Fraction Fraction::operator ++(int) {
	Fraction F = *this;
	i++;
	return F;
}

Fraction Fraction::operator --(int) {
	Fraction F = *this;
	i--;
	return F;
}

ostream& operator <<(ostream& out, const Fraction& Fout) {
	out << string(Fout);
	return out;
}

istream& operator >>(istream& in, Fraction& Fin) {
	cout << " Enter the integer part of the number: "; cin >> Fin.i;
	cout << " Enter the fractional part of the number: "; cin >> Fin.f;
	return in;
}

void Compare(Fraction f1, Fraction f2) {
	if (f1.i > f2.i) { // якщо ц≥ла частина 1 б≥льше ц≥лоњ частини 2
		cout << " First number is bigger!" << endl;
	}
	else if (f1.i > f2.i) { // якщо ц≥ла частина 2 б≥льше ц≥лоњ частини 1
		cout << " Second number is bigger!" << endl;
	}
	else { // якщо ц≥л≥ частини р≥вн≥
		if (f1.f > f2.f) { // якщо дробова частина 1 б≥льше н≥ж 2
			cout << " First number is bigger!" << endl;
		}
		else if (f2.f > f1.f) { // якщо дробова частина 2 б≥льше н≥ж 1
			cout << " Second number is bigger!" << endl;
		}
		else // якщо дробов≥ частини р≥вн≥
			cout << " Numbers are equal!" << endl;
	}
	cout << endl;
}

Fraction Substract(Fraction f1, Fraction f2) {
	Fraction result;

	result.i = f1.i - f2.i; // ÷≥ла частина

	// ƒробова частина

	if (f1.i > 0 && f2.i >= 0) {
		result.f = f1.f - f2.f;
		if (result.f < 0) {
			result.i--;
			result.f = 1000 + result.f;
		}
	}
	else if (f1.i > 0 && f2.i < 0) {
		result.f = f1.f + f2.f;
		if (result.f > 1000) {
			result.i++;
			result.f = result.f - 1000;
		}
		else if (result.f == 1000) {
			result.i++;
			result.f = 0;
		}
	}
	else if (f1.i < 0 && f2.i >= 0) {
		result.f = f1.f - f2.f;
		if (result.f < 0) {
			result.i--;
			result.f = 1000 + result.f;
		}
	}
	else if (f1.i < 0 && f2.i < 0) {
		result.f = f1.f + f2.f;
		if (result.f > 1000) {
			result.i++;
			result.f = result.f - 1000;
		}
		else if (result.f == 1000) {
			result.i;
			result.f = 0;
		}
	}
	else if (f1.i == 0 && f2.i > 0) {
		result.f = f1.f - f2.f;
		if (result.f < 0) {
			result.i--;
			result.f = 1000 + result.f;
		}
	}
	else if (f1.i == 0 && f2.i < 0) {
		result.f = f1.f + f2.f;
		if (result.f > 1000) {
			result.i++;
			result.f = result.f - 1000;
		}
		else if (result.f == 1000) {
			result.i++;
			result.f = 0;
		}
	}
	else if (f1.i == 0 && f2.i == 0) {
		result.f = f1.f - f2.f;
		if (result.f < 0) {
			result.i--;
			result.f = 1000 - result.f;
		}
	}
	return result;
}
