#include <iostream>
#include <string>

int main() 
{

	struct ctor_dtor
	{
		ctor_dtor()
		{
		std::cin >> input;
		}

	std::string input;

~ctor_dtor() { std::cout << "DESTRUCTION! " << input << "\n";}
	};

ctor_dtor temp;
	
return 0;
}
