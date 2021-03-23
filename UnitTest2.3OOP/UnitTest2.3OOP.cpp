#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab2.3OOP/Fraction.h"
#include "../Lab2.3OOP/Fraction.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest23OOP
{
	TEST_CLASS(UnitTest23OOP)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			unsigned short f = 1;
			string a = "001";
			Assert::AreEqual(a, FormatFractional(f));
		}
	};
}
