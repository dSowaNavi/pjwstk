#include <iostream>
#include <string>
#include <cstdlib>

int main()
{
	for (int i = 99; i > 0; i--)
	{
		std::cout << i << " bottles of beer on the wall, " << i << " bottles of beer.\nTake one down and pass it around,"<< i - 1 <<" bottles of beer on the wall.\n\n";
	}

	std::cout << "No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, 99 bottles of beer on the wall.\n\n";
	return 0;
}
