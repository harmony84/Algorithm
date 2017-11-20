#include <iostream>

int StringToNumber(const char* str)
{
	int positive = 1;

	if ( str == nullptr ) 
	{
		return 0;
	}

	if ( *str == '-' )
	{
		positive = -1;
	}

	int value = 0;

	while (*str)
	{
		if ( (*str) >= '0' && (*str) <= '9' )
		{
			value = (value * 10) + (*str) - '0';
		}

		str++;
	}

	return value * positive;
}

char* NumberToString(int val, char* buf, int radix)
{
	char* p = buf;

	while(val)
	{
		if (radix <= 10)
		{
			*p = ( val % radix ) + '0';
			*p++;
		}
		else
		{
			int t = val % radix;
			if ( t <= 9 )
			{
				*p = t + '0';
				*p++;
			}
			else
			{
				*p = t + 'a';
				*p++;
			}
		}

		val /= radix;
	}

	*p = '\0';

	size_t max_count = strlen( buf ) - 1;
	size_t loop_count = static_cast< size_t >( strlen( buf ) * 0.5f );

	for ( size_t index = 0; index < loop_count; ++index )
	{
		char temp = buf[ index ];
		buf[ index ] = buf[ max_count - index ];
		buf[ max_count - index ] = temp;
	}

	return buf;
}

int main()
{
	const char* str = "-1342";

	int val = StringToNumber(str);

	char str_2[CHAR_MAX] = {};
	NumberToString(13452, str_2, 10);

	return 0;
}