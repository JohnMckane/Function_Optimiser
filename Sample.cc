#include "Sample.h"
#include <iostream>
#include <string>
Sample::Sample(unsigned char chromosone)

{
	_chromosone = chromosone;
}
unsigned char Sample::GetChromosone()
{
	return _chromosone;
}
std::string Sample::GetChromosoneAsString()
{
	std::string chromosone_string = "";
		for(unsigned char check = 128; check > 0; check = check >> 1)
	{
		chromosone_string += std::to_string(check == (check & _chromosone));
	}
	return chromosone_string;
}
