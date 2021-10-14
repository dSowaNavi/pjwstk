#include <iostream>
#include <string>
using namespace std;

int validate() 
{
	string temp;
	char const* input;

	if (!getline(cin, temp)) {return -1;}
	input = temp.c_str();
	
	while(strtol(input, NULL, 10) == 0)
	{
		cout << "Proszę podac poprawną liczbę od 1 do 100:\n";	
		if (!getline(cin, temp)) {return -1;}
		input = temp.c_str();
	}
	
	return strtol(input, NULL, 10);
}

int main()
{	
	srand(time(NULL));
	int random = rand() % 100 + 1;
	int answer;

	cout << random << "\n";
	cout << "Zgadnij liczbe od 1 do 100:\n";
	answer = validate();	
	
	while (answer != random)
	{	
		cout << "Spróbuj jeszcze raz: \n";
		answer = validate();

		if (answer > random) { cout << "Za dużo!\n"; }
		else if (answer < random) {cout << "Za mało!\n";}
	}

	cout <<"Bravo!\n";
	return 0;
}
