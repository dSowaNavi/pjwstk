#include <iostream>
#include <string>

auto main(int argc, char* argv[]) -> int
{

	if(argc < 2)
	{
		std::cout << "Proszę podać argument z hasłem i spróbować ponownie.\n";
		return 1;
	}
	
	std::string password;
	std::cout << "Proszę Podać hasło: ";

	if (!std::getline(std::cin, password)) 
	{
		std::cout << "wystąpił bład" ;
		return 1;
	}

	while(password != argv[1])
	{
		std::cout << "Proszę podać poprawne hasło: ";
		if (!std::getline(std::cin, password)) 
		{
			std::cout << "wystąpił bład" ;
			return 1;
		}
	}	

	std::cout << "Witaj.\n";
	return 0;
}
