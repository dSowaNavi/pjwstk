#include <iostream>
#include <typeinfo>
#include <string.h>
#include "Item.h"

int main()
{
   
 class Weapon : Item 
    {
        public:
        void use_on(Creature& zwierz) 
        {
            zwierz.hp -= strength();
        };
    };
    
    class Sword : Weapon
    {
        public:
        const int strength() {return 5; } 
	void use_on(Creature& zwierz) 
        {
            zwierz.hp -= strength();
        };
           
        
    };
    
    class Potion : Item
    {
        public:
        void use_on(Creature& zwierz) 
        {
            zwierz.hp += strength();
        }
    };
    
    class Health_potion : Potion
    {
        public:
        const int strength()
        {
            if (uses > 0)
            return 10;
            else return 0;
        }
        
        void use_on(Creature& zwierz) 
        {
            zwierz.hp += strength();
            uses -= 1;
        }
        int uses = 2;
    };
    
    Sword swr;
    Health_potion pot;
    Creature zwierz;
    
    std::cout << zwierz.nazwa << " hp: "<< zwierz.hp << "\n";
	pot.use_on(zwierz);
	std::cout << "potion 1: " << zwierz.hp << "\n";
	pot.use_on(zwierz);
	std::cout << "potion 2: " << zwierz.hp << "\n";
	pot.use_on(zwierz);
	std::cout << "potion 3: " << zwierz.hp << "\n";

	std::cout << "teraz miecz, hp: " << zwierz.hp << "\n";
	swr.use_on(zwierz);
	std::cout << "*slash* " << zwierz.hp << "\n";
	swr.use_on(zwierz);
	std::cout << "*slash* " << zwierz.hp << "\n";
	swr.use_on(zwierz);
	std::cout << "*slash* " << zwierz.hp << "\n";

    
    
    return 0;
}
