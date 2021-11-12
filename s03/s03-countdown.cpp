#include <iostream>
#include <string>
#include <cstdlib>


auto main(int argc, char* argv[]) -> int
{

	if(argc < 2)
	{
		std::cout << "Proszę podać argument z cyfrą i spróbować ponownie.\n";
		return 1;

	}	
	
	auto number = strtof(argv[1],NULL);
	
	if (number == 0) 
	{
		std::cout << "koniec.\n";
		return 0;
	}	

	for (int i = number; i >= 0; i--)
	{
		std::cout << i << "...\n";
	}	

	std::cout << "koniec.\n";


	return 0;
}
