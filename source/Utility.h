#ifndef UTILITY
#define UTILITY

namespace lyrics
{
	class Utility
	{
	private:
		Utility() = delete;

	public:
		template <typename T>
		static void SafeDelete( T *&ptr )
		{
			delete ptr;
			ptr = nullptr;
		}

		template <typename T>
		static void SafeDeleteArray( T *&ptr )
		{
			delete [] ptr;
			ptr = nullptr;
		}
	};
}

#endif