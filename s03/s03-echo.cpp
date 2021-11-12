#include <iostream>
#include <string>

void large(int c, char** words, int pos, int count, char ending)
{
	if (pos == -1) { pos = 1 + count;}	

	do 
	{		
		std::cout << words[abs(pos)] << ending;
		pos ++;
	} while (abs(pos) > count && pos < c);
}

auto main(int argc, char* argv[]) -> int
{
	char end;	
	int count = 0;
	int pos = -1;

	if(argc < 2)
	{
		std::cout << "Proszę podać argumenty.\n";
		return 1;
	}
	

	for (int i = 1; i < argc && i <= 3 ; i++) 
	{
		if (argv[i][0] == '-')
		{
			char temp = argv[i][1];
			count++;
			switch (temp)
			{
				case 'n':
					end = ' ';
					break;
				case 'r':
					pos = -(argc - 1);
					break;
				case 'l':
					end = '\n';
					break;
				default:
					std::cout << "Nie poprawny argument " << argv[i] << '\n';					
			}
		}

	}		

	large(argc, argv, pos, count, end);
	return 0;
}
