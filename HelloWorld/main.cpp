#include <stdio.h>
#include "Calculator.h"
#include "ErrorCodes.h"

/*
* TODO:
*	- Use stl
*	- Unit testing
*	- Logging
*/



static void readDigitFromConsole(int &digit)
{
	bool success = false;

	do
	{
		int readResult = scanf_s("%i", &digit);
		if (readResult != 1)
		{
			clearerr(stdin);
			// TODO: This is a hack to clear stdin (fflush doesn't seem to work)
			char fGetsBuffer[256];
			fgets(fGetsBuffer, sizeof(fGetsBuffer) / sizeof(fGetsBuffer[0]), stdin);

			printf("Invalid number. Please try again: ");
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
		printf("Operation:");
		scanf_s(" %c", &op, 1);

		result = calculator->ConvertCalculatorOperation(op);

		if (result == ECalculatorOperation::INVALID)
		{
			operationCompleted = false;

			printf("Unrecognized operation. Please try again: ");
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

			printf("Enter the first number: ");
			readDigitFromConsole(calculator->digit1);

			printf("Enter the second number: ");
			readDigitFromConsole(calculator->digit2);

			ECalculatorOperation calculatorOperation = readCalculatorOperationFromConsole(calculator);

			int result = calculator->Calculate(calculatorOperation);

			printf("Here is the result: %d\n", result);
		}
		
	}
	catch (EErrorCodes e)
	{
		printf(ErrorCodes::ConvertErrorToMessage(e));
	}
	

}