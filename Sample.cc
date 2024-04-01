#include "Sample.h"
#include <iostream>
Sample::Sample(unsigned char chromosone)

{
	std::cout << this->_chromosone << "\n";
	_chromosone = chromosone;
	std::cout << chromosone << "\n";
}
unsigned char Sample::GetChromosone()
{

	std::cout << this->_chromosone << "\n";
	return _chromosone;
}
