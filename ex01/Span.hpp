#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>

//Je vais utiliser des fonctions dans les methodes
//  ces fonctions marche presque sur tout les containeurs
//
//  size()
//      elle donne le nombre exact d elements dans le containeur
//
//  begin()
//      donne un iterator (comme un pointeur) sur le premier elements
//
//  end()
//      elle donne un iterator (comme un pointeur) qui pointe sur le dernier elements
//
//  insert()
//      sert a introduire un ou plusieurs elements dans un container (identique) a un endroit precis

class Span
{
private:
    //taille limite
	unsigned int		_N;
    //
	std::vector<int>	_v;

public:
	// Constructors
	Span();
	Span(unsigned int N);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	// Member functions
	void	addNumber(int n);
	int		shortestSpan();
	int		longestSpan();
	void 	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	

	// Exceptions
    // si on depasse la limite
	class FullContainerException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

    //si on il n y a pas de nombres et qu on utiliser longest ou shortest
	class NotEnoughNumbersException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

#endif