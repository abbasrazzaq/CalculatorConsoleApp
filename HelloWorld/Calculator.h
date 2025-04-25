#pragma once

enum CalculatorOperation
{
	ADD,
	SUBTRACT,
	MULTIPLY,
	DIVIDE,
	INVALID
};


class Calculator
{
public:
	CalculatorOperation ConvertCalculatorOperation(char op);
	int Calculate(CalculatorOperation op);

	 int digit1;
	 int digit2;
};

