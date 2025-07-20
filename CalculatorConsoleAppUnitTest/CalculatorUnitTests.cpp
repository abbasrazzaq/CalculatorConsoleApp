#include "pch.h"
#include "CppUnitTest.h"
#include "../CalculatorConsoleApp/Calculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HellloWorldUnitTest
{
	TEST_CLASS(CalculatorUnitTests)
	{
	public:
		TEST_METHOD(CalculatorAddTest)
		{
			Calculator calc = Calculator();

			ECalculatorOperation op = calc.ConvertCalculatorOperation('*');

			Assert::AreEqual((int)op, (int)ECalculatorOperation::MULTIPLY);
		}

		TEST_METHOD(CalculatorMinusTest)
		{
			Calculator calc = Calculator();

			calc.digit1 = 4;
			calc.digit2 = 5;

			Assert::AreEqual(20, calc.Calculate(ECalculatorOperation::MULTIPLY));
		}
	};
}
