#include <iostream>
#include <string.h>
#include "Person.h"

int main()
{        
    class Mrs : public Person 
    {
        public:
        std::string to_string() const 
        {
            return "Mrs " + imie + " " + nazwisko;
        }
    };  

    class Mr : public Person 
    {
        public:
        std::string to_string() const 
        {
            return "Mr " + imie + " " + nazwisko;
        }
    };  

    class Queen : public Person 
    {
        public:
        std::string to_string() const 
        {
            return "Queen " + imie + " " + nazwisko;
        }
    };  

    class King : public Person 
    {
        public:
        std::string to_string() const 
        {
            return "King " + imie + " " + nazwisko;
        }
    };  
	       
        
    class Hello : public Greet 
    {
        public:
        
        void greet(Person const& obiekt) const
        {
            std::cout << "Hello "  << obiekt.to_string() << "\n";
        }
	};
    class Good_evening : public Greet 
    {
        public:
        
        void greet(Person const& obiekt) const
        {
            std::cout << "Good_evening "  << obiekt.to_string() << "\n";
        }
	};
    class Farewell : public Greet 
    {
        public:
        
        void greet(Person const& obiekt) const
        {
            std::cout << "Farewell "  << obiekt.to_string() << "\n";
        }
    };
    
    Mrs pani;
/*    Mr pan;
    Queen krolowa;
    King krol;*/
    Hello wit;
    Good_evening even;
    Farewell bye;    
	
    wit.greet(pani);   
    even.greet(pani);
    bye.greet(pani);
    return 0;
}
