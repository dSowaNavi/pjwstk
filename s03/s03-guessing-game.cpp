#include <iostream>
#include <string>

int validate() 
{
	std::string temp;
	char const* input;

	if (!std::getline(std::cin, temp)) {return -1;}
	input = temp.c_str();
	
	while(strtol(input, NULL, 10) == 0)
	{
		std::cout << "Proszę podac poprawną liczbę od 1 do 100:\n";	
		if (!std::getline(std::cin, temp)) {return -1;}
		input = temp.c_str();
	}
	
	return strtol(input, NULL, 10);
}

int main()
{	
	srand(time(NULL));
	int random = rand() % 100 + 1;
	int answer;

	std::cout << random << "\n";
	std::cout << "Zgadnij liczbe od 1 do 100:\n";
	answer = validate();	
	
	while (answer != random)
	{	
		std::cout << "Spróbuj jeszcze raz: \n";
		answer = validate();

		if (answer > random) { std::cout << "Za dużo!\n"; }
		else if (answer < random) { std::cout << "Za mało!\n";}
	}

	std::cout <<"Bravo!\n";
	return 0;
}
