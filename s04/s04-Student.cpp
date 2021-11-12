#include <iostream>
#include <string>
#include <cstdlib>


auto main() -> int
{
    
    struct STUDENT
    {
        STUDENT()
        {
            imie = "Damian";
            id = "s24589";
            semestr = "pierwszy";
            srednia = "0";
        }
        
        auto to_string() -> std::string
        {
            return  "Imie i id studenta : " + imie + " "+ id + ". Semestr i średnia ocen: " + semestr + " " + srednia;
        }
        
        private:
        std::string imie;
        std::string id;
        std::string semestr;
        std::string srednia;
        
    };
    STUDENT ja;
    std::cout << ja.to_string();
    
    return 0;
}
