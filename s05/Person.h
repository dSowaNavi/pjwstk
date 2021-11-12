#include <iostream>
#include <string.h>

class Person 
    {
	public:
	Person()	
	{
		std::cin >> imie;
		std::cin >> nazwisko;
        }
        
        std::string who_is_it(Person const& obiekt) 
        {
            return "Imie: " + obiekt.imie + ", Nazwsko: " + obiekt.nazwisko;
        }
            
        virtual  std::string to_string() const =  0;
        
        std::string imie;
	std::string nazwisko;
    };

class Greet 
    {
        virtual void greet(Person const& obiekt) const = 0;
    };
