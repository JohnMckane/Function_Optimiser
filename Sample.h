#include<string>
class Sample
{
	public:
		Sample(unsigned char chromosone);
		Sample();
		unsigned char GetChromosone();
		std::string GetChromosoneAsString();
		unsigned char _chromosone;
		float Phenotype();
};
