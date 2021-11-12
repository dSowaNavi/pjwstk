#include <iostream>
#include <typeinfo>
#include <string.h>

int main()
{
    class Creature 
    {
        public:
        Creature() 
        {
            std::cin >> nazwa;
            std::cin >> hp;
        }
        
        std::string nazwa;
        int hp;
    };

    class Item
    {
        public:
        virtual void use_on(Creature& zwierz) = 0;  
        virtual int strength() = 0;  
    };
    
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
        int strength() {return 5; }
        
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
        int strength()
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
    
    std::cout << zwierz.nazwa << zwierz.hp;
    pot.use_on(zwierz);
    std::cout << zwierz.nazwa << zwierz.hp;
    std::cout << "\n";
    std::cout << zwierz.nazwa << zwierz.hp;
    pot.use_on(zwierz);
    std::cout << zwierz.nazwa << zwierz.hp;
    std::cout << "\n";
    std::cout << zwierz.nazwa << zwierz.hp;
    pot.use_on(zwierz);
    std::cout << zwierz.nazwa << zwierz.hp;
   std::cout << "\n";
    std::cout << zwierz.nazwa << zwierz.hp;
    pot.use_on(zwierz);
    std::cout << zwierz.nazwa << zwierz.hp;
    
    return 0;
}
