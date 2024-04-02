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
void breed(Sample s1, Sample s2, Sample& r1, Sample& r2)
{
	unsigned char t1, t2, h1, h2;
	int cross_point = rand() % 8;
	t1 = (s1._chromosone << cross_point) >> cross_point;
	t2 = (s2._chromosone << cross_point) >> cross_point;
	h1 = (s1._chromosone >> cross_point) << cross_point;
	h2 = (s2._chromosone >> cross_point) << cross_point;
	r1 =  Sample(t1 | h2);
	r2 =  Sample(t2 | h1);

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

