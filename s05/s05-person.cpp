#include <iostream>
#include <string.h>
using namespace std;



int main()
{
    class Person 
    {
        public:
        Person()
        {
            cin >> imie;
        }
        
        string who_is_it(Person const& obiekt) 
        {
            return "0";
        }
            
        virtual  string to_string() const =  0;
        
        string imie;
    };
    
    class Mrs : public Person 
    {
        public:
        string to_string() const 
        {
            return "Mrs " + imie;
        }
    };   
        
    class Greet 
    {
        virtual void greet(Person const& obiekt) const = 0;
    };
    
    class Hello : public Greet 
    {
        public:
        /*void greet(Person* obiekt)
        {
            cout << "Hello "  << obiekt->to_string();
        }*/
        void greet(Person const& obiekt) const
        {
            cout << "Hello "  << obiekt.to_string();
        }
    };
    
    Mrs osoba;
    Hello wit;
    wit.greet(osoba);
    
    
    return 0;
}
