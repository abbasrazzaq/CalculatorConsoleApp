#include <stdio.h>
#include "Calculator.h"
#include "ErrorCodes.h"
#include <iostream>
#define FMT_UNICODE 0

#include "../../spdlog/include/spdlog/sinks/basic_file_sink.h"

/* TODO:
*	-
*/
//
////
//#include "../../spdlog/include/spdlog/spdlog.h"
//#include "../../spdlog/include/spdlog/cfg/env.h"   // support for loading levels from the environment variable
//#include "../../spdlog/include/spdlog/fmt/ostr.h"  // support for user defined types

using namespace std;

typedef std::shared_ptr<spdlog::logger> LoggerPtr;

static void readDigitFromConsole(int& digit, LoggerPtr logger);
static ECalculatorOperation readCalculatorOperationFromConsole(const Calculator* calculator, LoggerPtr logger);

int main()
{
	auto logger = spdlog::basic_logger_mt("basic_logger", "logs/basic-log.txt");
	logger->set_level(spdlog::level::level_enum::debug);

	logger->debug("Calculator starting");
	
	try
	{
		while (1)
		{
			Calculator *calculator = new Calculator();

			cout << "Enter the first number: ";
			readDigitFromConsole(calculator->digit1, logger);

			cout << "Enter the second number: ";
			readDigitFromConsole(calculator->digit2, logger);

			ECalculatorOperation calculatorOperation = readCalculatorOperationFromConsole(calculator, logger);

			int result = calculator->Calculate(calculatorOperation);

			cout << "Here is the result: " << result << endl;
			logger->flush();
		}
		
	}
	catch (EErrorCodes e)
	{
		logger->error(ErrorCodes::ConvertErrorToMessage(e));
		cout << ErrorCodes::ConvertErrorToMessage(e) << endl;
	}
	
	logger->flush();

	return 0;
}


static void readDigitFromConsole(int& digit, LoggerPtr logger)
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
			logger->debug("Invalid number entered");
		}
		else
		{
			success = true;
		}

	} while (!success);
}

static ECalculatorOperation readCalculatorOperationFromConsole(const Calculator* calculator, LoggerPtr logger)
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
			logger->debug(std::string("Unrecognized operation entered: ") + std::to_string(op));
		}
		else
		{
			operationCompleted = true;
		}
	} while (!operationCompleted);

	return result;
}