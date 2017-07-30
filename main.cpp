#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<process.h>
using namespace std;

char cpu[60000];           // powerful brainfuck memory
vector<char> acc;          // vector with script
char current_symbol;
char path_to_file[100];
void run_script()
{
	// this var point current cell in cpu
	unsigned int pointer = 0;
	for (int i = 0; i < acc.size(); ++i)
	{
		if (acc[i] == NULL)
		{
			break;
    	}
		else if (acc[i] == '$')
		{

		}
		else if (acc[i] == '&')
		{
			break;
		}
		else if (acc[i] == ',')
		{
			cout << "enter:";
			cin >> cpu[pointer];
		}
		else if (acc[i] == '.')
		{
			cout<<cpu[pointer];
		}
		else if (acc[i] == '>')
		{
			cpu[pointer]++;
		}
		else if (acc[i] == '<')
		{
			cpu[pointer]--;
		}
		else if (acc[i] == '+')
		{
			pointer++;
		}
		else if (acc[i] == '-')
		{
			pointer--;
		}
		else 
		{
			cout << endl << "shit in programm! symbol ¹" << i;
			exit(-1);
		}
	
	}

}
void check_format()
{
	for (int i = 0; i < 100; ++i)
	{
		if (path_to_file[i] == NULL)
		{
			break;
		}
		else if (path_to_file[i] == '.')
		{
			++i;
			if (path_to_file[i] == 'p')
			{
				++i;
				if (path_to_file[i] == 'b')
				{
					++i;
					if (path_to_file[i] == 'f')
					{
						cout << "starting to run script..." << endl;
					}
				}
			}
			else {
				cout << "wrong format!";
				exit(-1);
			}
		}
	}
}


int main(int argc, char* argv[])
{
	string file_path = argv[1];
	strcpy_s(path_to_file, argv[1]); // we need this to check pbf in file end

	ifstream script(file_path);
	while(script)
	{
		script.get(current_symbol);
		acc.push_back(current_symbol);
	}
	script.close();
	check_format();
	run_script();
	return 0;
}