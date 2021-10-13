/*
 * Reading command line arguments.
 */

#include <iostream>
#include <string>

auto main(int argc, char* argv[]) -> int
{
	if (argc < 3) 
	{
		std::cout << "Prosze podać liczby\n";
		return 1;
	}

	auto const a = std::stoi(argv[1]);
	auto const b = std::stoi(argv[2]);
	std::cout << a * b;
	std::cout << "\n";
	return 0;

}
