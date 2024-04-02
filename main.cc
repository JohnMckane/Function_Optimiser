#include <iostream>
#include <string>
#include "Sample.h"
void mutate(int size, float mutation_rate, Sample pool[])
{
	int n_to_mutate = (int)(size * mutation_rate);
	for(int i = 0; i < n_to_mutate; i++)
	{
		int index = rand() % size;
		pool[index]._chromosone = pool[index]._chromosone ^ (unsigned char) (1 << rand() % 8 );
	}
}
using namespace std;
int main() {
	string size_string;
	int size;
	cout << "Gene Pool Size:";
	cin >> size_string;
	size = stoi(size_string);
	Sample pool[size];
	cout << size << endl;;
	for(int i = 0; i < size; i++)
	{
		cout << i << endl;
		cout << pool[i].GetChromosoneAsString() << endl;
	}
	return 0;
}

