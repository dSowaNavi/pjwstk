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
	char znak;
	std::cin >> znak;
	int b = prompt("liczbna b");

	switch(znak) 
	{
		case '+':
			std::cout << a + b << "\n";
		break;

		case '-':
			std::cout << a - b << "\n";
		break;
		
		case '/':
			if(b != 0){std::cout<< a / b << "\n";}
			else { std::cout<< "Nie dzielimy przez zero\n";}
		break;

		case '*':
			std::cout << a * b << "\n";
		break;
	}

	return 0;

}
