#include <iostream>
#include <string>
#include <cmath>
#include<string>
using namespace std;
template <typename T> class Sample
{
	public:
		Sample(T chromosone);
		Sample();
		T GetChromosone();
		string GetChromosoneAsString();
		T _chromosone;
		float Phenotype();
};
template <typename T> Sample<T>::Sample(T chromosone)
{
	_chromosone = chromosone;
}
template <typename T> Sample<T>::Sample()
{
	_chromosone = rand() % 255;
}
template <typename T> T Sample<T>::GetChromosone()
{
	return _chromosone;
}
template <typename T> string Sample<T>::GetChromosoneAsString()
{
	string chromosone_string = "";
		for(unsigned char check = 128; check > 0; check = check >> 1)
	{
		chromosone_string += to_string(check == (check & _chromosone));
	}
	return chromosone_string;
}
template <typename T> float Sample<T>::Phenotype()
{
	return pow(((float)(255/2) - _chromosone),2);
}
