#include "Sample.h"
#include <iostream>
#include <string>
using namespace std;
Sample::Sample(unsigned char chromosone)
{
	_chromosone = chromosone;
}
Sample::Sample()
{
	_chromosone = rand() % 255;
}
unsigned char Sample::GetChromosone()
{
	return _chromosone;
}
string Sample::GetChromosoneAsString()
{
	string chromosone_string = "";
		for(unsigned char check = 128; check > 0; check = check >> 1)
	{
		chromosone_string += to_string(check == (check & _chromosone));
	}
	return chromosone_string;
}
