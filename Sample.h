#include<string>
class Sample
{
	public:
		Sample(unsigned char chromosone);
		unsigned char GetChromosone();
		std::string GetChromosoneAsString();
	private:
		unsigned char _chromosone;
};
