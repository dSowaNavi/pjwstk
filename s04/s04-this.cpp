#include <iostream>
#include <string>


int main() 
{
	struct point 
{
	void printout() {std::cout << temp << "\n";}

point* temp = this;

};

point manager;
	
manager.printout();
std::cout << &manager << "\n";

return 0;
}
