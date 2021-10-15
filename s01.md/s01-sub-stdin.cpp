/*
 * Reading command line arguments.
 */

#include <iostream>
#include <string>


auto askInput(string prompt) -> int
{
	string temp;
	char const* input;
	
	cout << prompt << " int: ";
	getline(cin, temp);	
	input = temp.c_str();
	auto result = strtol(input, NULL, 10);
	return result;
}

auto main() -> int
{
	int a = prompt("liczbna a");	
	int b = prompt("liczbna b");

	std::cout << a - b << '\n';	

	return 0;

}
