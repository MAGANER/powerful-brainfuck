#include "variable.h"
#include<iostream>
using namespace std;


variable::variable()
{

}
void variable::show_name()
{
	cout << name;
}
void variable::show_value()
{
	cout << value;
}
char variable::get_name()
{
	return name;
}
char variable::get_value()
{
	return value;
}
void variable::set(char getting_name , char getting_value)
{
	this->name = getting_name;
	this->value = getting_value;

}
void variable::set(char getting_value)
{
	this->value = getting_value;
}
variable::~variable()
{
}
