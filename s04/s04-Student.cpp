#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main() 
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
        
        string to_string()
        {
            //string yea =  format("Imie studenta: {}, id: {}. Semestr: {}. srednia ocen: {}.", imie, id, semestr, srednia);
            return  "Imie i id studenta : " + imie + " "+ id + ". Semestr i średnia ocen: " + semestr + " " + srednia;
        }
        
        private:
        string imie;
        string id;
        string semestr;
        string srednia;
        
    };
    STUDENT ja;
    cout << ja.to_string();
    
    return 0;
}
