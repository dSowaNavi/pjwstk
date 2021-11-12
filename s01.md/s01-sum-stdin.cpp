/*
 * Reading command line arguments.
 */

#include <iostream>
#include <string>
#include <cstdlib>


auto askInput(std::string prompt) -> int
{
	std::string temp;
	char const* input;
	
	std::cout << prompt << " int: ";
	std::getline(std::cin, temp);	
	input = temp.c_str();
	auto result = strtol(input, NULL, 10);
	return result;
}

auto main() -> int
{
	int a = askInput("liczbna a");	
	int b = askInput("liczbna b");

	std::cout << a + b << '\n';	

	return 0;

}
