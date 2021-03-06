#include "ErrorLogger.h"

#include "Logger.h"

namespace lyrics
{
	constexpr char ErrorLogger::WARNING[];
	constexpr char ErrorLogger::ERROR[];
	constexpr char ErrorLogger::FATAL_ERROR[];

	void ErrorLogger::Warning(const Location location, const WarningCode warningCode)
	{
		switch (warningCode)
		{
		case WarningCode::UNKNOWN_ESCAPE_SEQUENCE:
			Logger::Log(location, ErrorLogger::WARNING, static_cast<unsigned int>(warningCode), "Unknown escape sequence.");
			break;

		default:
			Logger::StandardErrorLog(location, ErrorLogger::WARNING, static_cast<unsigned int>(warningCode));
			break;
		}
	}

	void ErrorLogger::Error(const Location location, const ErrorCode errorCode)
	{
		switch (errorCode)
		{
		case ErrorCode::WRONG_CHARACTER:
			Logger::Log(location, ErrorLogger::ERROR, static_cast<unsigned int>(errorCode), "Wrong character.");
			break;

		case ErrorCode::STRING_NOT_TERMINATED:
			Logger::Log(location, ErrorLogger::ERROR, static_cast<unsigned int>(errorCode), "String not terminated.");
			break;

		case ErrorCode::EXPECTED_RIGHT_PARENTHESIS:
			Logger::Log(location, ErrorLogger::ERROR, static_cast<unsigned int>(errorCode), "Expected ).");
			break;

		case ErrorCode::INCOMPLETE_ARRAY_LITERAL:
			Logger::Log(location, ErrorLogger::ERROR, static_cast<unsigned int>(errorCode), "Incomplete array literal.");
			break;

		case ErrorCode::EXPECTED_HASH:
			Logger::Log(location, ErrorLogger::ERROR, static_cast<unsigned int>(errorCode), "Expected hash.");
			break;

		case ErrorCode::INCOMPLETE_HASH_LITERAL:
			Logger::Log(location, ErrorLogger::ERROR, static_cast<unsigned int>(errorCode), "Incomplete hash literal.");
			break;

		case ErrorCode::EXPECTED_PARAMETER_NAME:
			Logger::Log(location, ErrorLogger::ERROR, static_cast<unsigned int>(errorCode), "Expected parameter name.");
			break;

		case ErrorCode::OUTPUT_PARAMETER_DEFAULT_ARGUMENT:
			Logger::Log(location, ErrorLogger::ERROR, static_cast<unsigned int>(errorCode), "Output parameter cannot have default argument.");
			break;

		case ErrorCode::INCOMPLETE_FUNCTION:
			Logger::Log(location, ErrorLogger::ERROR, static_cast<unsigned int>(errorCode), "Incomplete function.");
			break;

		case ErrorCode::EXPECTED_PARAMETER:
			Logger::Log(location, ErrorLogger::ERROR, static_cast<unsigned int>(errorCode), "Expected parameter.");
			break;

		case ErrorCode::EXPECTED_PRIMARY_EXPRESSION:
			Logger::Log(location, ErrorLogger::ERROR, static_cast<unsigned int>(errorCode), "Expected primary expression.");
			break;

		case ErrorCode::EXPECTED_INDEX:
			Logger::Log(location, ErrorLogger::ERROR, static_cast<unsigned int>(errorCode), "Expected index.");
			break;

		case ErrorCode::EXPECTED_FUNCTION_CALL:
			Logger::Log(location, ErrorLogger::ERROR, static_cast<unsigned int>(errorCode), "Expected function call.");
			break;

		case ErrorCode::EXPECTED_MEMBER:
			Logger::Log(location, ErrorLogger::ERROR, static_cast<unsigned int>(errorCode), "Expected member.");
			break;

		case ErrorCode::INCOMPLETE_EXPRESSION:
			Logger::Log(location, ErrorLogger::ERROR, static_cast<unsigned int>(errorCode), "Incomplete expression.");
			break;

		case ErrorCode::EXPECTED_LHS:
			Logger::Log(location, ErrorLogger::ERROR, static_cast<unsigned int>(errorCode), "Expected lhs.");
			break;

		case ErrorCode::INCOMPLETE_CLASS_DEFINITION:
			Logger::Log(location, ErrorLogger::ERROR, static_cast<unsigned int>(errorCode), "Expected class definition.");
			break;

		case ErrorCode::EXPECTED_CLASS_NAME:
			Logger::Log(location, ErrorLogger::ERROR, static_cast<unsigned int>(errorCode), "Expected class name.");
			break;

		case ErrorCode::EXPECTED_BASE_CLASS:
			Logger::Log(location, ErrorLogger::ERROR, static_cast<unsigned int>(errorCode), "Expected base class.");
			break;

		case ErrorCode::EXPECTED_PACKAGE_NAME:
			Logger::Log(location, ErrorLogger::ERROR, static_cast<unsigned int>(errorCode), "Expected package name.");
			break;

		case ErrorCode::EXPECTED_PACKAGE:
			Logger::Log(location, ErrorLogger::ERROR, static_cast<unsigned int>(errorCode), "Expected package.");
			break;

		case ErrorCode::EXPECTED_IDENTIFIER:
			Logger::Log(location, ErrorLogger::ERROR, static_cast<unsigned int>(errorCode), "Expected identifier.");
			break;

		case ErrorCode::EXPECTED_END:
			Logger::Log(location, ErrorLogger::ERROR, static_cast<unsigned int>(errorCode), "Expected end.");
			break;

		case ErrorCode::INCOMPLETE_IF_STATEMENT:
			Logger::Log(location, ErrorLogger::ERROR, static_cast<unsigned int>(errorCode), "Incomplete if statement.");
			break;

		case ErrorCode::EXPECTED_END_ELSE_ELSEIF:
			Logger::Log(location, ErrorLogger::ERROR, static_cast<unsigned int>(errorCode), "Expected end or else or elseif.");
			break;

		case ErrorCode::INCOMPLETE_CASE_STATEMENT:
			Logger::Log(location, ErrorLogger::ERROR, static_cast<unsigned int>(errorCode), "Incomplete case statement.");
			break;

		case ErrorCode::EXPECTED_WHEN_ELSE_ELSEIF:
			Logger::Log(location, ErrorLogger::ERROR, static_cast<unsigned int>(errorCode), "Expected when or else or elseif.");
			break;

		case ErrorCode::EXPECTED_WHEN:
			Logger::Log(location, ErrorLogger::ERROR, static_cast<unsigned int>(errorCode), "Expected when.");
			break;

		case ErrorCode::INCOMPLETE_WHILE_STATEMENT:
			Logger::Log(location, ErrorLogger::ERROR, static_cast<unsigned int>(errorCode), "Incomplete while statement.");
			break;

		case ErrorCode::INCOMPLETE_FOR_STATEMENT:
			Logger::Log(location, ErrorLogger::ERROR, static_cast<unsigned int>(errorCode), "Incomplete for statement.");
			break;

		case ErrorCode::INCOMPLETE_FOREACH_STATEMENT:
			Logger::Log(location, ErrorLogger::ERROR, static_cast<unsigned int>(errorCode), "Incomplete foreach statement.");
			break;

		case ErrorCode::USE_OF_UNDECLARED_IDENTIFIER:
			Logger::Log(location, ErrorLogger::ERROR, static_cast<unsigned int>(errorCode), "Use of undeclared identifier.");
			break;

		case ErrorCode::DUPLICATED_IDENTIFIER:	// TODO: Unused yet.
			Logger::Log(location, ErrorLogger::ERROR, static_cast<unsigned int>(errorCode), "Duplicated identifier.");
			break;

		default:
			Logger::StandardErrorLog(location, ErrorLogger::ERROR, static_cast<unsigned int>(errorCode));
			break;
		}
	}

	void ErrorLogger::FatalError(const FatalErrorCode &fatalErrorCode)
	{
		switch (fatalErrorCode)
		{
		case FatalErrorCode::NO_INPUT_FILE:
			Logger::Log(ErrorLogger::FATAL_ERROR, static_cast<unsigned int>(fatalErrorCode), "No input file.");
			break;

		case FatalErrorCode::CANNOT_OPEN_FILE:
			Logger::Log(ErrorLogger::FATAL_ERROR, static_cast<unsigned int>(fatalErrorCode), "Cannot open file.");
			break;

		case FatalErrorCode::CANNOT_READ_FILE:
			Logger::Log(ErrorLogger::FATAL_ERROR, static_cast<unsigned int>(fatalErrorCode), "Cannot read file.");
			break;

		case FatalErrorCode::CANNOT_CLOSE_FILE:
			Logger::Log(ErrorLogger::FATAL_ERROR, static_cast<unsigned int>(fatalErrorCode), "Cannot close file.");
			break;

		case FatalErrorCode::NOT_ENOUGH_MEMORY:
			Logger::Log(ErrorLogger::FATAL_ERROR, static_cast<unsigned int>(fatalErrorCode), "Not enough memory.");
			break;

		default:
			Logger::StandardErrorLog(ErrorLogger::FATAL_ERROR, static_cast<unsigned int>(fatalErrorCode));
			break;
		}
	}
}