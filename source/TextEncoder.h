#include <cstring>

#ifndef TEXT_ENCODER
#define TEXT_ENCODER

namespace lyrics
{
	class TextEncoder
	{
	public:
		char16_t *EncodeToUTF_16( const unsigned char * const data, const unsigned int size, unsigned int &length )
		{
			using std::size_t;
			using std::memcpy;

			if ( data == nullptr )
			{
				return nullptr;
			}

			switch ( data[0] )
			{
			case 0xEF:
				if ( data[1] == 0xBB && data[2] == 0xBF )
				{
					return UTF8ToUTF16( data + TextEncoder::SIZE_UTF_8_BOM, size - TextEncoder::SIZE_UTF_8_BOM, length );
				}
				else
				{
					return UTF8ToUTF16( data, size, length );
				}
				break;

			case 0xFE:
				if ( data[1] == 0xFF )
				{
					// TODO: UTF-16 big endian
				}
				else
				{
					return UTF8ToUTF16( data, size, length );
				}
				break;

			case 0xFF:
				if ( data[1] == 0xFE )
				{
					if ( data[2] != 0x00 || data[3] != 0x00 )
					{
						char16_t *tStr;
						const unsigned int sizeWithoutBOM = size - TextEncoder::SIZE_UTF_16_BOM;

						length = sizeWithoutBOM >> 1;
						tStr = new char16_t [length];
						memcpy( tStr, data + TextEncoder::SIZE_UTF_16_BOM, sizeWithoutBOM );

						return tStr;
					}
					else
					{
						return UTF32ToUTF16( ( char32_t * )( data + TextEncoder::SIZE_UTF_32_BOM ), ( size - TextEncoder::SIZE_UTF_32_BOM ) >> 2, length );
					}
				}
				else
				{
					return UTF8ToUTF16( data, size, length );
				}
				break;

			case 0x00:
				if ( data[1] == 0x00 && data[2] == 0xFE && data[3] == 0xFF )
				{
					// TODO: UTF-32 big endian
				}
				else
				{
					return UTF8ToUTF16( data, size, length );
				}
				break;
			
			default:
				return UTF8ToUTF16( data, size, length );
			}

			return nullptr;
		}

		char16_t *UTF8ToUTF16( const unsigned char * const str, const unsigned int length, unsigned int &convertedStrLength )
		{
			if ( str == nullptr )
			{
				return nullptr;
			}

			char16_t *tStr;

			convertedStrLength = 0;
			for ( unsigned int i = 0; i < length; i++ )
			{
				if ( str[i] < 192u )
				{
					convertedStrLength++;
				}
				else if ( str[i] < 224u )
				{
					convertedStrLength++;
					i++;
				}
				else if ( str[i] < 240u )
				{
					convertedStrLength++;
					i += 2;
				}
				else
				{
					convertedStrLength += 2;
					i += 3;
				}
			}

			tStr = new char16_t [convertedStrLength];

			for ( unsigned int i = 0, j = 0; i < length; i++ )
			{
				if ( str[i] < 192u )
				{
					tStr[j++] = str[i];
				}
				else if ( str[i] < 224u )	// && ( str[i + 1] & 192u ) == 128u
				{
					tStr[j++] = ( str[i] & 31u ) << 6 | ( str[i + 1] & 63u );
					i++;
				}
				else if ( str[i] < 240u )
				{
					tStr[j++] = ( str[i] & 15u ) << 12 | ( str[i + 1] & 63u ) << 6 | ( str[i + 2] & 63u );
					i += 2;
				}
				else
				{
					tStr[j++] = 55296u | ( ( ( str[i] & 7u ) << 2 | ( str[i + 1] & 48u ) >> 4 ) - 1 ) << 6 | ( str[i + 1] & 15u ) << 2 | ( str[i + 2] & 3u );
					tStr[j++] = 56320u | ( str[i + 2] & 15u ) << 6 | ( str[i + 3] & 63u );
					i += 3;
				}
			}

			return tStr;
		}

		char16_t *UTF32ToUTF16( const char32_t * const str, const unsigned int length, unsigned int &convertedStrLength )
		{
			if ( str == nullptr )
			{
				return nullptr;
			}

			char16_t *tStr;

			convertedStrLength = 0;
			for ( unsigned int i = 0; i < length; i++ )
			{
				if ( *( ( char16_t * )&str[i] + 1 ) == 0 )
				{
					convertedStrLength++;
				}
				else
				{
					convertedStrLength += 2;
				}
			}

			tStr = new char16_t [convertedStrLength];

			for ( unsigned int i = 0, j = 0; i < length; i++ )
			{
				if ( *( ( char16_t * )&str[i] + 1 ) == 0 )
				{
					tStr[j++] = *( char16_t * )&str[i];
				}
				else
				{
					tStr[j++] = 55296u | ( *( ( char16_t * )&str[i] + 1 ) - 1 ) << 6 | *( char16_t * )&str[i] >> 10;
					tStr[j++] = 56320u | ( *( char16_t * )&str[i] & 1023u );
				}
			}

			return tStr;
		}

	private:
		static const unsigned int SIZE_UTF_8_BOM = 3;
		static const unsigned int SIZE_UTF_16_BOM = 2;
		static const unsigned int SIZE_UTF_32_BOM = 4;
	};
}

#endif
