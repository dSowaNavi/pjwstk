#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main() 
{

	struct ctor_dtor
	{
		ctor_dtor()
		{
		cin >> input;
		}

	string input;

~ctor_dtor() { cout << "DESTRUCTION! " << input << "\n";}
	};

ctor_dtor temp;
	
return 0;
}
