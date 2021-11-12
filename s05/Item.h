
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
        virtual const int strength() = 0;  
    };
