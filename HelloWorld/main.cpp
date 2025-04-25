#include <stdio.h>
#include "Calculator.h"
#include "ErrorCodes.h"

/*
* TODO:
* * - Use git
*	- Refactor
*	- Use stl
*	- Unit testing
*	- Logging
*/

Calculator *calculator = new Calculator();

static void readDigitFromConsole(int &digit)
{
	bool success = false;

	do
	{
		printf("Enter number: ");
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

void main()
{
	try
	{
		printf("Hello World!\n");

		readDigitFromConsole(calculator->digit1);

		readDigitFromConsole(calculator->digit2);

		bool operationCompleted = true;
		int result = 0;

		do
		{
			operationCompleted = true;

			char op = ' ';
			printf("Operation:");
			scanf_s(" %c", &op, 1);

			auto opEnum = calculator->ConvertCalculatorOperation(op);

			if (opEnum == INVALID)
			{
				operationCompleted = false;
			}
			else
			{
				operationCompleted = true;

				result = calculator->Calculate(opEnum);
			}
		} while (!operationCompleted);

		printf("Here is the result: %d", result);
		getchar();
		getchar();
	}
	catch (EErrorCodes e)
	{
		printf(ErrorCodes::ConvertErrorToMessage(e));
	}
	

}