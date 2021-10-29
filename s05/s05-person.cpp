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
        
        virtual void to_string() = 0;
        
        protected:
        string imie;
    };

    class Mrs : Person 
    {
        public:
        void to_string() 
        {
            cout << "Hello Mrs " << imie;
        }
    };
       class Mr : Person 
    {
        public:
        void to_string() 
        {
            cout << "Hello Mr " << imie;
        }
    };
       class King : Person 
    {
        public:
        void to_string() 
        {
            cout << "Hello King " << imie;
        }
    };
       class Queen : Person 
    {
        public:
        void to_string() 
        {
            cout << "Hello Queen " << imie;
        }
    };

    return 0;
}
