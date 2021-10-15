/*
 * Reading command line arguments.
 */

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

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
	int a = askInput("liczbna a");	
	int b = askInput("liczbna b");

	cout << a + b << '\n';	

	return 0;

}
