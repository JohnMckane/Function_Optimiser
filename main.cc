#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include "Sample.h"
using namespace std;
void mutate(int size, float mutation_rate, Sample<unsigned char> pool[])
{
	int n_to_mutate = (int)(size * mutation_rate);
	for(int i = 0; i < n_to_mutate; i++)
	{
		int index = rand() % size;
		pool[index]._chromosone = pool[index]._chromosone ^ (unsigned char) (1 << rand() % 8 );
	}
}
void print_pool(int size, Sample<unsigned char> pool[])
{
	for(int i = 0; i < size; i++)
		{
			cout << pool[i].GetChromosoneAsString() << endl;
		}
}
void breed(Sample<unsigned char> s1, Sample<unsigned char> s2, Sample<unsigned char>* r1, Sample<unsigned char>* r2)
{
	unsigned char t1, t2, h1, h2;
	int cross_point = rand() % 8;
	t1 = (unsigned char)(s1._chromosone << cross_point) >> cross_point;
	t2 = (unsigned char)(s2._chromosone << cross_point) >> cross_point;
	h1 = (unsigned char)(s1._chromosone >> (8- cross_point)) << (8-cross_point);
	h2 = (unsigned char)(s2._chromosone >> (8-cross_point)) << (8-cross_point);
	r1 = new Sample<unsigned char>(t1 | h2);
	r2 =  new Sample<unsigned char>(t2 | h1);

}
// Score will be 1/ distance of phenotype from 1
float score(Sample<unsigned char> sample)
{
	return sample.Phenotype();
}
void sortPool(int size, Sample<unsigned char>* samples)
{
	return sort(samples, samples + size, [](Sample<unsigned char> a, Sample<unsigned char> b)
                                  {
                                      return score(a) > score(b);
                                  });
}

int main() {
	string size_string, mutation_string, breed_string;
	int size;
	float mutation_rate;
	float breed_rate;
	//Get Gene Pool Size
	cout << "Gene Pool Size:";
	cin >> size_string;
	size = stoi(size_string);
	//Get Mutation Rate
	cout << "Mutation Rate:";
	cin >> mutation_string;
	mutation_rate = stof(mutation_string);
	//Get Breed rate
	cout << "Breed Rate:";
	cin >> breed_string;
	breed_rate = stof(breed_string);
	//Create inital pool
	Sample<unsigned char> pool[size];
	float best_score = 0;
	for(int i = 0; i < 5000; i++)
	{
		//Sort Pool and print score of current best
		sortPool(size, pool);
		if(best_score < score(pool[0]))
		{
		best_score = score(pool[0]);
		cout << best_score << endl;
		}
		//Breed best size * breed rate samples, replace worst with result
		int n_breeders = size * breed_rate;
		Sample<unsigned char> * progeny = new Sample<unsigned char>[2*n_breeders];
		for(int j = 0; j < n_breeders; j++)
		{
			breed(pool[j], pool[rand() % size], progeny + j*2, progeny+ (j*2+1));	
		}
		for(int j = size - 2* n_breeders; j < size; j++)
		{
			pool[j] = progeny[j-size];
		}
		mutate(size, mutation_rate, pool);

	}
	return 0;
}

