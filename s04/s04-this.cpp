#include <iostream>
#include <string>


using namespace std;

int main() 
{
	struct point 
{
	void printout() {cout << temp << "\n";}

point* temp = this;

};

point manager;
	
manager.printout();
cout << &manager << "\n";

return 0;
}
