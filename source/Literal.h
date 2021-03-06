#ifndef STRUCT_LITERAL
#define STRUCT_LITERAL

#include <string>
#include <vector>
#include <unordered_map>

namespace lyrics
{
	using std::u32string;
	using std::vector;
	using std::unordered_map;

	struct Literal
	{
		enum struct Type : unsigned int { NULL_LITERAL, BOOLEAN, INTEGER, REAL, STRING, ARRAY, HASH, FUNCTION, IMAGE, TEXT, SOUND, VIDEO, OBJECT, REFERENCE };

		union Value
		{
			bool boolean;
			long long integer;
			double real;
			u32string *string;
			vector<Literal> *array;
			unordered_map<u32string, Literal> *hash;
			char *function;
			char *object;
			u32string *reference;
		};

		Literal() : type(Type::NULL_LITERAL)
		{
		}

		Literal(const bool boolean) : type(Type::BOOLEAN)
		{
			value.boolean = boolean;
		}

		Literal(const long long integer) : type(Type::INTEGER)
		{
			value.integer = integer;
		}

		Literal(const double real) : type(Type::REAL)
		{
			value.real = real;
		}

		Literal(vector<Literal> * const array) : type(Type::ARRAY)
		{
			value.array = array;
		}

		Literal(unordered_map<u32string, Literal> * const hash) : type(Type::HASH)
		{
			value.hash = hash;
		}

		Literal(const Type type, u32string * const string) : type(type)
		{
			value.string = string;
		}

		Literal(const Type type, char * const object) : type(type)
		{
			value.object = object;
		}

		const Type type;
		Value value;
	};
}

#endif