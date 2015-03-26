#ifndef ERROR_CODE
#define ERROR_CODE

namespace lyrics
{
	enum class ErrorCode: unsigned int
	{
		WRONG_CHARACTER = 2001,
		STRING_NOT_TERMINATED,

		EXPECTED_RIGHT_PARENTHESIS = 3001,
		INCOMPLETE_ARRAY_LITERAL,
		EXPECTED_HASH,
		INCOMPLETE_HASH_LITERAL,
		EXPECTED_PARAMETER_NAME,
		OUTPUT_PARAMETER_DEFAULT_ARGUMENT,
		INCOMPLETE_ROUTINE,
		EXPECTED_PARAMETER,
		EXPECTED_PRIMARY_EXPRESSION,
		EXPECTED_INDEX,
		EXPECTED_ROUTINE_CALL,
		EXPECTED_MEMBER,
		INCOMPLETE_EXPRESSION,
		EXPECTED_LHS,
		INCOMPLETE_CLASS_DEFINITION,
		EXPECTED_CLASS_NAME,
		EXPECTED_BASE_CLASS,
		EXPECTED_PACKAGE_NAME,
		EXPECTED_PACKAGE,
		EXPECTED_IDENTIFIER,
		EXPECTED_END,
		INCOMPLETE_IF_STATEMENT,
		EXPECTED_END_ELSE_ELSEIF,
		INCOMPLETE_CASE_STATEMENT,
		EXPECTED_WHEN_ELSE_ELSEIF,
		EXPECTED_WHEN,
		INCOMPLETE_WHILE_STATEMENT,
		INCOMPLETE_FOR_STATEMENT,
		INCOMPLETE_FOREACH_STATEMENT,

		DUPLICATED_IDENTIFIER = 4001,
	};
}

#endif
