#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[])
{

	if(argc < 2)
	{
		cout << "Proszę podać argument z cyfrą i spróbować ponownie.\n";
		return 1;

	}	
	
	auto number = strtof(argv[1],NULL);
	
	if (number == 0) 
	{
		cout << "koniec.\n";
		return 0;
	}	

	for (int i = number; i >= 0; i--)
	{
		cout << i << "...\n";
	}	

	cout << "koniec.\n";


	return 0;
}
