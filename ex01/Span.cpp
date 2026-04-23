#include "Span.hpp"

Span::Span() : _N(0)
{
}

Span::Span(unsigned int N) : _N(N)
{
}

Span::Span(const Span &other)
{
    this->_N = 0;
    //ici j utiliser la methode de vecteur pour le mettre a default
    //mais je ne suis pas obliger de le faire comme il est a default deja
    this->_v.clear();
    //comme on a l operator de = on peut juste l utiliser
    //sans copier a la main
	*this = other;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_N = other._N;
		this->_v = other._v;
	}
	return (*this);
}

Span::~Span()
{
}

//methode pour rajouter goutte par goutte
void	Span::addNumber(int n)
{
	if (this->_v.size() >= this->_N)
		throw FullContainerException();
    //push_back vas mettre toute a la fin
	this->_v.push_back(n);
}

//-------------------------------------------------------------------------------------
//methode pour rajouter pein de fonction d un coupé

//je peux tres bien indexer un vecteur en mode [i]
//j utilise les iterator parceque ils peuvent etre utiliser avec plein d autre containers

//begin pointe sur le tout premier
//end pointe sur le dernier + 1

//ces iterator vont pointer sur les index d un autre vecteur pas sur le quelle je vais utiliser cette methode
void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    //si ils sont pareille on a rien a ajouter donc on sort
    if (begin == end)
        return ;
    //this->_v.size vas renvoyer la taille de notre vecteur
    //et en ajoutant le nombre d elements qu on veut ajouter on a la taille qu on aura au final

    //la fonction distance vas juste compter le nombre de incrimentation entre les 2 iterator
	if (this->_v.size() + std::distance(begin, end) > this->_N)
		throw FullContainerException();
    //le premier arguments c est la fin de notre vecteur
    //le deuxieme et le troisieme c est de ou est ce qu on veut copier ces valeurs
	this->_v.insert(this->_v.end(), begin, end);
}
//
//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
//
int		Span::shortestSpan()
{
    //on verifier la taille
	if (_v.size() <= 1)
		throw NotEnoughNumbersException();
    //on va creer une copie de notre vecteur
    //et on va la sort comme ca on a de plus petit au plus grand
    std::vector<int> tmp = _v;
	std::sort(tmp.begin(), tmp.end());
	
    //ici on peut juste comparer avec les nombres qui se suivent comme ils sont dans l ordre croissant
    int min = tmp[1] - tmp[0];
	for (unsigned int i = 1; i < tmp.size(); i++)
	{
		if (tmp[i] - tmp[i - 1] < min)
			min = tmp[i] - tmp[i - 1];
	}
	return (min);
}
//
//-------------------------------------------------------------------------------------


int		Span::longestSpan()
{
	if (_v.size() <= 1)
		throw NotEnoughNumbersException();
	std::vector<int> tmp = _v;
    //ici on va utiliser la meme technique
    //on va sort de plus petit au plus grand
    //on et on va enlever le plus petit au plus grand
    std::sort(tmp.begin(), tmp.end());
	return (tmp[tmp.size() - 1] - tmp[0]);
}

const char *Span::FullContainerException::what() const throw()
{
	return ("Container is full");
}

const char *Span::NotEnoughNumbersException::what() const throw()
{
	return ("Not enough numbers in container");
}