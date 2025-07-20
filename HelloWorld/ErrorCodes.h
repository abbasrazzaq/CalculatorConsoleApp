#pragma once

enum EErrorCodes
{
	GENERIC_ERROR = 0,
	INVALID_CALCULATOR_OPERATION,
	COUNT
};

class ErrorCodes
{
public:
	static const char* ConvertErrorToMessage(EErrorCodes e);
};