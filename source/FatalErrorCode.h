#ifndef FATAL_ERROR_CODE
#define FATAL_ERROR_CODE

namespace lyrics
{
	enum class FatalErrorCode : unsigned int { NO_INPUT_FILES = 1001, TEXT_LOADING_FAILED = 2001 };
};

#endif