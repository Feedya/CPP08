#include "MutantStack.hpp"

int main()
{
	std::cout << "Subject test"<< std::endl;

	MutantStack<int> int_stack;

	int_stack.push(1);
	int_stack.push(2);
    int_stack.push(3);

	std::cout << "tout en haut: " << int_stack.top() << std::endl;


    //on retire l elements toute en haut
	std::cout << "size: " << int_stack.size() << std::endl;
    int_stack.pop();
    std::cout << "apres pop" << std::endl;
	std::cout << "size: " << int_stack.size() << std::endl;

    std::cout << "\n\n";

	int_stack.push(4);
	int_stack.push(5);
	int_stack.push(6);
	int_stack.push(7);
	int_stack.push(8);
	int_stack.push(9);
	int_stack.push(10);


	MutantStack<int>::iterator index_start = int_stack.begin();
	MutantStack<int>::iterator index_end = int_stack.end();
	
    std::cout << "ecrire du debut a la fin";
	std::cout << "stack: ";
	while (index_start != index_end)
	{
		std::cout << *index_start << " ";
		++index_start;
	}
	std::cout << std::endl;
	std::stack<int> s(int_stack);


    std::cout << "\n\n";

	std::cout << "ecrire a l envers" << std::endl;

	MutantStack<int>::reverse_iterator reverse_index_start = int_stack.rbegin();
	MutantStack<int>::reverse_iterator reverse_index_end = int_stack.rend();

	std::cout << "stack: ";
	while (reverse_index_start != reverse_index_end)
	{
		std::cout << *reverse_index_start << " ";
		++reverse_index_start;
	}
	std::cout << std::endl;
	
	return 0;
}