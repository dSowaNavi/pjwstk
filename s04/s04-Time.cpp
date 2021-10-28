
#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>   
#include <valarray>
using namespace std;

int main() 
{
    struct czas 
    {
      czas() 
        {
            godzina = 0;
            minuta = 0;
            sekunda = 0;
		poraDnia = Time_Of_Day::night;
        }
	enum class Time_Of_Day
	{
		morning = 0, day, evening, night
	} key;
        
      void build(int h, int m, int s)
        {
            godzina = h;
            minuta = m;
            sekunda = s;
            
            update();		
        }
        
        string to_string()
        {
		return std::to_string(godzina) + ":" + std::to_string(minuta) + ":" + std::to_string(sekunda);
        }

	  string to_string(Time_Of_Day)
	{
		switch (poraDnia)		
		{
			case Time_Of_Day::morning: return "poranek"; 	break;
			case Time_Of_Day::day: return "dzień";		break;
			case Time_Of_Day::evening: return "wieczór";	break;
			case Time_Of_Day::night: return "noc";		break;
		}
		return "error";
	}

	void time_of_day()
	{		
		if(godzina >= 6 && godzina < 12) { poraDnia = Time_Of_Day::morning;}	
		if(godzina >= 12 && godzina < 17) { poraDnia = Time_Of_Day::day;}	
		if(godzina >= 17 && godzina < 22) { poraDnia = Time_Of_Day::evening;}	
		if(godzina >= 22 && godzina < 6) { poraDnia = Time_Of_Day::night;}		
	}        

        void next_hour()
        {
            godzina += 1;
            update();
        }
        
        void next_minute() 
        {
            minuta += 1;
            update();
        } 
        
        void next_sec() 
        {
            sekunda += 1;
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
            else if (sekunda < 0) 
            {
                sekunda = 60 + sekunda;
                minuta -= 1;
            }
            
             if (minuta >= 60) 
            {
                auto temp = minuta / 60;
                godzina += floor(temp);
                minuta = minuta - (temp * 60);
            }
            else if (minuta < 0) 
            {
                minuta = 60 + minuta;
                godzina -= 1;
            }
            
            if (godzina >= 24) {
                auto temp = godzina / 24;
                godzina = godzina - 24 * temp;
            }
            else if (godzina < 0) 
            {
                godzina = 24 + godzina;
            }
		time_of_day();
        }       
        
	int count_seconds()	
	{
		return godzina * 3600 + minuta * 60 + sekunda;		
	}
       
	int count_minutes()	
	{
		return godzina * 60 + minuta * 60;		
	} 

	czas time_alg(czas first, czas second,char sign)
        {           
            valarray<int> a{first.godzina, first.minuta, first.sekunda},b{second.godzina, second.minuta, second.sekunda}, c;
            czas answer;
            switch(sign) 
            {
                case '+':
                   c = a + b;
                break;
                
                case '-':
                    c = a-b;
                break;
            }
            
            answer.godzina = c[0];
            answer.minuta = c[1];
            answer.sekunda = c[2];
            answer.update();
            
            return answer;
        }        
	
	bool time_alg(czas first, czas second,string sign)
	{
		int a = first.count_seconds();
		int b = second.count_seconds();

		if(sign == "==" && a == b) 
		{			
			return true;
		}
		 else if(sign == "==")
		{
			return false;
		}

		if(sign == "!=" && a != b) 
		{			
			return true;
		}
		 else if(sign == "!=")
		{
			return false;
		}

		if(sign == "<" && a < b)
		{
			return true;
		}		
		else if(sign == "<")
		{return false;}

		if(sign == ">" && a > b)
		{
		return true;
		} else if(sign == ">")
		 {return false;}

		return false;
        }

	czas time_to_midnight(czas a)
	{
		czas temp;

		return time_alg(a, temp, '-');
	}

        void midnight_test()
        {
            godzina = 23;
            minuta = sekunda = 59;
            to_string();
            next_sec();
            to_string();
        }    
                
        private:
        int godzina;
        int minuta;
        int sekunda;	
	  Time_Of_Day poraDnia;
    };   
    
czas manager;
czas a;
czas b;
a.build(12,0,0);
b.build(0,0,1);
    
cout << "godzina a: " << a.to_string() << "\n";
cout << "godzina b: " << b.to_string() << "\n";
//zadanie czas
manager.midnight_test();
//zadanie time of day
cout << "Pora dnia: " << a.to_string(a.key) << "\n";
//zadanie arytmetyka
czas output;
output = manager.time_alg(a,b,'+');
cout << "suma: " << output.to_string() << "\n";
output = manager.time_alg(a,b,'-');
cout << "róznica: " << output.to_string() << "\n";
cout << "Czy a == b?: " << manager.time_alg(a,b,"==") << "\n";
cout << "Czy a != b?: " << manager.time_alg(a,b,"!=") << "\n";
cout << "Czy a > b?: " << manager.time_alg(a,b,">") << "\n";
cout << "Czy a < b?: " << manager.time_alg(a,b,"<") << "\n";
//zadanie sekundy do polnocy
output = a.time_to_midnight(a);
cout << "Czas do polnocy dla a: " << output.to_string() << "\n";

return 0;
}
