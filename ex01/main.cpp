
#include "Span.hpp"
#include <cstdlib>


int main()
{
	std::cout << "vecteur test" << std::endl;
	Span sp(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	try
	{
		sp.addNumber(11);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << "Test 50 elements vector" << std::endl;
	Span sp2(100);
	std::vector<int> v;
	std::srand(time(NULL));
	for (int i = 0; i < 50; i++)
	{
		int random_int = rand() % 1000000;
		v.push_back(random_int);
	}
	try
	{
		sp2.addNumber(v.begin(), v.end());
		std::cout << "shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp2.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << "vecteur tres grand\n" << std::endl;
	Span sp3(100000);
	std::vector<int> v2;
	std::srand(time(NULL));
	for (int i = 0; i < 100000; i++)
	{
		
		int random_int = rand() % 1000000000;
		v2.push_back(random_int);
	}
	try
	{
		sp3.addNumber(v2.begin(), v2.end());
		std::cout << "shortest span: " << sp3.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp3.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}