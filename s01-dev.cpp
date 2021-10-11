/*
 * Reading command line arguments.
 */

#include <iostream>
#include <string>

auto main(int argc, char* argv[]) -> int
{
	if (argc < 3 || std::stoi(argv[2]) == 0) 
	{
		std::cout << "Prosze podać liczby poprawne do dzielenia \n";
		return 1;
	}

	auto const a = std::stof(argv[1]);
	auto const b = std::stof(argv[2]);
	std::cout << a / b;
	std::cout << "\n";
	return 0;

}
