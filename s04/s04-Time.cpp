#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>   
using namespace std;

int main() 
{
    struct czas 
    {
        czas() 
        {
            if(godzina >= 24) { godzina = 24 - godzina;}
            if(minuta >= 60) { godzina = 60 - minuta;}
            if(sekunda >= 60) { godzina = 60 - sekunda;}
        }
        
        void to_string()
        {
            cout << godzina << ":" << minuta << ":" << sekunda << "\n";
        }
        
        void next_hour(int addition)
        {
            godzina += addition;
            update();
        }
        
        void next_minute(int addition) 
        {
            minuta += addition;
            update();
        } 
        
        void next_sec(int addition) 
        {
            sekunda += addition;
            update();
        } 
        
        void update()
        {
            if (sekunda >= 60)
            {
                auto temp = sekunda / 60;
                minuta += floor(temp);
                sekunda = sekunda - (temp * 60);
                
            }
            
             if (minuta >= 60) 
            {
                auto temp = minuta / 60;
                godzina += floor(temp);
                minuta = minuta - (temp * 60);
            }
            
            if (godzina >= 24) { godzina = godzina - 24;}
        }
        
        void test()
        {
            godzina = 23;
            minuta = sekunda = 59;
            to_string();
            next_sec(1);
            to_string();
        }
        
        
        int godzina = 0;
        int minuta = 0;
        int sekunda = 0;
    };
    
    czas now;
    now.test();
    
    return 0;
}
