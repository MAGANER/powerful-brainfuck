#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<process.h>
#include <cstdlib> 
#include"variable.h"
using namespace std;

char cpu[60000];           // powerful brainfuck memory
vector<char> acc;          // vector with script
char current_symbol;
char path_to_file[100];

void error(int i)
{
	cout << "shit in programm! " << "¹" << i << "=" << acc[i];
	exit(-1);
}
void run_script()
{
	// this var point current cell in cpu
	unsigned int pointer = 0;
	for (int i = 0; i < acc.size(); ++i)
	{  	
		   // that's a classic mode
			if (acc[i] == ')')
			{
			
				if (acc[i] == NULL)
				{
					break;
				}
				else if (acc[i] == ')' || acc[i] == '(')
				{
					//just do nothing.
				}
				else if (acc[i] == '&' || acc[i] == ';')
				{
					break;
				}
				else if (acc[i] == '#')
				{
					++i;
					int loop_counter = atoi(&acc[i]);
					++i;
					bool on = true; // if that's true loop is working
					int j = 0; // if j == loop_counterloop isn't working
					while (on)
					{
						if (acc[i] == '&' || acc[i] == ';')
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
							cout << cpu[pointer];
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
						++j;
						if (j == loop_counter)
						{
							on = false;
						}
					}
				}
				else if (acc[i] == ',')
				{
					cout << "enter:";
					cin >> cpu[pointer];
				}
				else if (acc[i] == '.')
				{
					cout << cpu[pointer];
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
					cout << endl << "shit in programm! symbol ¹" << i << '=' << acc[i];
					exit(-1);
				}
			}

			// that's a new powerful brainfuck's mode 
			variable var; 
			if (acc[i] == '(')
			{
				++i;
				if (acc[i] == ':')
				{
					for (int j = i; acc[j] != ';'; ++j)
					{
						if (acc[j] == var.get_name())
						{
							var.show_value();
							break;
						}
						if (acc[j] != ':')
						{
							cout << acc[j];
						}
					}
					cout << endl;
				}
				else if (acc[i] == '+')
				{
					char var_name = var.get_name();
					char var_value = var.get_value();

					char cfirst_number, csecond_number;
					int nfirst_number, nsecond_number;
					int summ = 0;
					++i;
					cfirst_number = acc[i];
					++i;
					csecond_number = acc[i];
					
					// we check var in expression,cos uf there is var, then
					// we should add var value in expression
					if (cfirst_number == var_name)
					{
						nfirst_number = atoi(&var_value);
					}
					else{
						nfirst_number = atoi(&cfirst_number);
					}

					if (csecond_number == var_name)
					{
						nsecond_number = atoi(&csecond_number);
					}
					else {
                        nsecond_number = atoi(&csecond_number);
					}		
					/////////////////////////////


					++i;
					if (acc[i] == '.')
					{
						summ = nfirst_number + nsecond_number;
						cout << summ << endl;
					}
					else if (acc[i] == '=')
					{
						++i;
						if (acc[i] == var_name)
						{
							var_value = summ;
						}
						else {
							error(i);
						}
						++i;
						if (acc[i] == '.')
						{
							summ = nfirst_number + nsecond_number;
							cout << summ << endl;
						}
						else {
							--i;
						}
					}
					else {
						--i;
					}
				}
				else if (acc[i] == '-')
				{
					char var_name = var.get_name();
					char var_value = var.get_value();

					char cfirst_number, csecond_number;
					int nfirst_number, nsecond_number;
					int summ = 0;
					++i;
					cfirst_number = acc[i];
					++i;
					csecond_number = acc[i];

					// we check var in expression,cos uf there is var, then
					// we should add var value in expression
					if (cfirst_number == var_name)
					{
						nfirst_number = atoi(&var_value);
					}
					else {
						nfirst_number = atoi(&cfirst_number);
					}

					if (csecond_number == var_name)
					{
						nsecond_number = atoi(&csecond_number);
					}
					else {
						nsecond_number = atoi(&csecond_number);
					}
					////////

					++i;
					if (acc[i] == '.')
					{
						summ = nfirst_number - nsecond_number;
						cout << summ << endl;
					}
					else if (acc[i] == '=')
					{
						++i;
						if (acc[i] == var_name)
						{
							var_value = summ;
						}
						else {
							error(i);
						}
						++i;
						if (acc[i] == '.')
						{
							summ = nfirst_number - nsecond_number;
							cout << summ << endl;
						}
						else {
							--i;
						}
					}
					else {
						--i;
					}
				}
				else if (acc[i] == '/')
				{
					char var_name = var.get_name();
					char var_value = var.get_value();

					char cfirst_number, csecond_number;
					int nfirst_number, nsecond_number;
					int summ = 0;
					++i;
					cfirst_number = acc[i];
					++i;
					csecond_number = acc[i];

					// we check var in expression,cos uf there is var, then
					// we should add var value in expression
					if (cfirst_number == var_name)
					{
						nfirst_number = atoi(&var_value);
					}
					else {
						nfirst_number = atoi(&cfirst_number);
					}

					if (csecond_number == var_name)
					{
						nsecond_number = atoi(&csecond_number);
					}
					else {
						nsecond_number = atoi(&csecond_number);
					}
					//////////

					++i;
					if (acc[i] == '.')
					{
						cout << nfirst_number / nsecond_number << endl;
					}
					else if (acc[i] == '=')
					{
						++i;
						if (acc[i] == var_name)
						{
							var_value = summ;
						}
						else {
							error(i);
						}
						++i;
						if (acc[i] == '.')
						{
							summ = nfirst_number / nsecond_number;
							cout << summ << endl;
						}
						else {
							--i;
						}
					}
					else {
						--i;
					}
				}
				else if (acc[i] == '*')
				{
					char var_name = var.get_name();
					char var_value = var.get_value();

					char cfirst_number, csecond_number;
					int nfirst_number, nsecond_number;
					int summ = 0;
					++i;
					cfirst_number = acc[i];
					++i;
					csecond_number = acc[i];

					// we check var in expression,cos uf there is var, then
					// we should add var value in expression
					if (cfirst_number == var_name)
					{
						nfirst_number = atoi(&var_value);
					}
					else {
						nfirst_number = atoi(&cfirst_number);
					}

					if (csecond_number == var_name)
					{
						nsecond_number = atoi(&csecond_number);
					}
					else {
						nsecond_number = atoi(&csecond_number);
					}
                     //////////

					++i;
					if (acc[i] == '.')
					{
						cout << nfirst_number * nsecond_number << endl;
					}
					else if (acc[i] == '=')
					{
						++i;
						if (acc[i] == var_name)
						{
							var_value = summ;
						}
						else {
							error(i);
						}
						++i;
						if (acc[i] == '.')
						{
							summ = nfirst_number * nsecond_number;
							cout << summ << endl;
						}
						else {
							--i;
						}
					}
					else {
						--i;
					}
				}
				else if (acc[i] == '%')
				{
					char var_name = var.get_name();
					char var_value = var.get_value();

					char cfirst_number, csecond_number;
					int nfirst_number, nsecond_number;
					int summ = 0;

					++i;
					cfirst_number = acc[i];
					++i;
					csecond_number = acc[i];

					// we check var in expression,cos uf there is var, then
					// we should add var value in expression
					if (cfirst_number == var_name)
					{
						nfirst_number = atoi(&var_value);
					}
					else {
						nfirst_number = atoi(&cfirst_number);
					}

					if (csecond_number == var_name)
					{
						nsecond_number = atoi(&csecond_number);
					}
					else {
						nsecond_number = atoi(&csecond_number);
					}
					/////////


					++i;
					if (acc[i] == '.')
					{
						cout << nfirst_number % nsecond_number << endl;
					}
					else if (acc[i] == '=')
					{
						++i;
						if (acc[i] == var_name)
						{
							var_value = summ;
						}
						else {
							error(i);
						}
						++i;
						if (acc[i] == '.')
						{
							summ = nfirst_number % nsecond_number;
							cout << summ << endl;
						}
						else {
							--i;
						}
					}
					else {
						--i;
					}
				}
				else if (acc[i] == '$')
				{
					++i;
					char name = acc[i];
					++i;
					char value = acc[i];
					if (value == '^')
					{
						value = ' ';
					}
					if(value == NULL) {
						error(i);
					}
					var.set(name, value);
					++i;
					if (acc[i] == '.')
					{
						var.show_value();
					}
					else {
						--i;
					}
				}
				else if (acc[i] == '!')
				{
					++i;
					if (acc[i] == var.get_name())
					{
						var.set(' ', ' ');
						cout << "variable" << " is killed!"<<endl;
					}
					else {
						error(i);
					}
				}
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
						++i;
						if (path_to_file[i] != NULL)
						{
							cout << "wrong format!";
							exit(-1);
						}
					}
					else {
						cout << "wrong format!";
						exit(-1);
					}
				}
				else {
					cout << "wrong format!";
					exit(-1);
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