#include <stdio.h>
#include "Calculator.h"
#include "ErrorCodes.h"
#include <iostream>

/*
* TODO:
*	- Use stl
*	- Unit testing
*	- Logging
*/

using namespace std;

static void readDigitFromConsole(int &digit)
{
	bool success = false;

	do
	{
		cin >> digit;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid number. Please try again: ";
		}
		else
		{
			success = true;
		}

	} while (!success);
}

static ECalculatorOperation readCalculatorOperationFromConsole(const Calculator *calculator)
{
	ECalculatorOperation result = ECalculatorOperation::INVALID;

	bool operationCompleted = true;

	do
	{
		operationCompleted = true;

		char op = ' ';

		cout << "Operation: ";
		cin >> op;

		result = calculator->ConvertCalculatorOperation(op);

		if (result == ECalculatorOperation::INVALID)
		{
			operationCompleted = false;

			cout << "Unrecognized operation. Please try again: ";
		}
		else
		{
			operationCompleted = true;
		}
	} while (!operationCompleted);

	return result;
}

void main()
{
	try
	{
		while (1)
		{
			Calculator* calculator = new Calculator();

			cout << "Enter the first number: ";
			readDigitFromConsole(calculator->digit1);

			cout << "Enter the second number: ";
			readDigitFromConsole(calculator->digit2);

			ECalculatorOperation calculatorOperation = readCalculatorOperationFromConsole(calculator);

			int result = calculator->Calculate(calculatorOperation);

			cout << "Here is the result: " << result << endl;
		}
		
	}
	catch (EErrorCodes e)
	{
		cout << ErrorCodes::ConvertErrorToMessage(e) << endl;
	}
	

}