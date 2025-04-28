#include <stdio.h>
#include "Calculator.h"
#include "ErrorCodes.h"
#include <iostream>
#define FMT_UNICODE 0

#include "../../spdlog/include/spdlog/sinks/basic_file_sink.h"
//
////
//#include "../../spdlog/include/spdlog/spdlog.h"
//#include "../../spdlog/include/spdlog/cfg/env.h"   // support for loading levels from the environment variable
//#include "../../spdlog/include/spdlog/fmt/ostr.h"  // support for user defined types

/*
* TODO:
*	- Logging (nuget?)
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

	auto logger = spdlog::basic_logger_mt("basic_logger", "logs/basic-log.txt");

	logger->error("Message from spdlog");

	logger->flush();

	/*spdlog::cfg::load_env_levels();

	spdlog::info("Welcome to spdlog version {}.{}.{}  !", SPDLOG_VER_MAJOR, SPDLOG_VER_MINOR,
		SPDLOG_VER_PATCH);

	spdlog::critical("A critical error");*/

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