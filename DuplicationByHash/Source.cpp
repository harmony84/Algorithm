#include <iostream>
#include <map>
#include <unordered_map>

int main()
{
	const char* str = "teeter";
	//const char* str = "totagwegewal";

	using my_map_count = std::unordered_map<char, int>;
	using my_map_index = std::map<int, char>;
	
	my_map_count count_data;
	my_map_index index_data;


	const char* string_pointer = str;
	int string_index = 0;

	while ( *string_pointer != '\0' )
	{
		my_map_count::iterator iter = count_data.find( *string_pointer );

		if ( iter != count_data.cend() )
		{
			iter->second += 1;
		}
		else
		{
			count_data.emplace( *string_pointer, 1 );
			index_data.emplace( string_index, *string_pointer );
		}

		string_index++;
		*string_pointer++;
	}

	for ( const auto& val : index_data )
	{
		my_map_count::const_iterator const_iter = count_data.find( val.second );

		if ( const_iter->second == 1 )
		{
			std::cout << const_iter->first << std::endl;
			break;
		}
	}

	return 0;
}
