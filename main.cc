#include <iostream>
#include <string>
#include "Sample.h"
using namespace std;
void mutate(int size, float mutation_rate, Sample pool[])
{
	int n_to_mutate = (int)(size * mutation_rate);
	for(int i = 0; i < n_to_mutate; i++)
	{
		int index = rand() % size;
		pool[index]._chromosone = pool[index]._chromosone ^ (unsigned char) (1 << rand() % 8 );
	}
}
void print_pool(int size, Sample pool[])
{
for(int i = 0; i < size; i++)
	{
		cout << pool[i].GetChromosoneAsString() << endl;
	}
}
int main() {
	string size_string;
	int size;
	cout << "Gene Pool Size:";
	cin >> size_string;
	size = stoi(size_string);
	Sample pool[size];
	return 0;
}

