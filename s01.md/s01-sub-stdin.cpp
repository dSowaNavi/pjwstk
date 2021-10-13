/*
 * Reading command line arguments.
 */

#include <iostream>
#include <string>


auto prompt(std::string prompt) -> int
{
	std::string input{};

	std::cout << prompt << " int: ";
	std::cin >> input;
	int result = std::stoi(input);
	return result;
}

auto main() -> int
{
	int a = prompt("liczbna a");	
	int b = prompt("liczbna b");

	std::cout << a - b << '\n';	

	return 0;

}
