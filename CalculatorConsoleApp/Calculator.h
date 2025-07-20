#pragma once

enum ECalculatorOperation
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
	ECalculatorOperation ConvertCalculatorOperation(char op) const;
	int Calculate(ECalculatorOperation op);

	 int digit1;
	 int digit2;
};

