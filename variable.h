#pragma once
class variable
{
public:
	variable();
	~variable();
	char get_name();
	char get_value();
	void show_name();
	void show_value();
	void set(char getting_name, char getting_value);
private:
	char name;
	char value;


};

