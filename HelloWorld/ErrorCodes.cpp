#include "ErrorCodes.h"

const char* ErrorCodes::ConvertErrorToMessage(EErrorCodes e)
{
	switch (e)
	{
	case EErrorCodes::INVALID_CALCULATOR_OPERATION:
		return "Calculator operation was not recognized.";
		break;
	case EErrorCodes::GENERIC_ERROR:
		return "An error occurred.";
		break;
	};
}