#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[])
{

	if(argc < 2 || strtof(argv[1],NULL) == 0)
	{
		cout << "Proszę podać argument z liczbą większą od jeden i spróbować ponownie.\n";
		return 1;

	}	
	
	auto number = strtof(argv[1],NULL);
		

	for (int i = 1; i <= number; i++)
	{

		if (i % 3 == 0 && i % 5 == 0) { cout << i << " FizzBuzz\n";}
		else if (i % 3 == 0) {cout << i << " Fizz\n";}
		else if (i % 5 == 0) {cout << i << " Buzz\n";} 
		else {cout << i << "\n";}
	}	



	return 0;
}
