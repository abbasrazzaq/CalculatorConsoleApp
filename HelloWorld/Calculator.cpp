#include "Calculator.h"
#include "ErrorCodes.h"

int Calculator::Calculate(CalculatorOperation op)
{
	int result = 0;

	switch (op)
	{
	case ADD:
		result = digit1 + digit2;
		break;
	case SUBTRACT:
		result = digit1 - digit2;
		break;
	case MULTIPLY:
		result = digit1 * digit2;
		break;
	case DIVIDE:
		result = digit1 / digit2;
		break;
	default:
		throw  EErrorCodes::INVALID_CALCULATOR_OPERATION;
	};

	return result;
}

CalculatorOperation Calculator::ConvertCalculatorOperation(char op)
{
	CalculatorOperation result = INVALID;

	switch (op)
	{
	case '+':
		result = ADD;
		break;

	case '-':
		result = SUBTRACT;
		break;

	case '/':
		result = DIVIDE;
		break;

	case '*':
		result = MULTIPLY;
		break;

	default:
		result = INVALID;
		break;
	}

	return result;
}