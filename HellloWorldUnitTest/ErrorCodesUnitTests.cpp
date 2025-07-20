#include "pch.h"
#include "CppUnitTest.h"
#include "../HelloWorld/ErrorCodes.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HellloWorldUnitTest
{
	TEST_CLASS(ErrorCodesUnitTests)
	{
	public:
		TEST_METHOD(ErrorCodeMessageTest)
		{
			for (int errorCodeInt = 0; errorCodeInt < EErrorCodes::COUNT; errorCodeInt++)
			{
				EErrorCodes errorCode = (EErrorCodes)errorCodeInt;
				std::string errorMessage = ErrorCodes::ConvertErrorToMessage(errorCode);

				std::wstring assertMessage = L"An error code is missing a message: Error number: " + std::to_wstring(errorCodeInt);
				Assert::IsTrue(errorMessage.length(), assertMessage.c_str());
			}

		}
	};
}