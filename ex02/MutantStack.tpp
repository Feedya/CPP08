#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{

}

//---------------------------------------------------------------------------
//comme notre classe n a pas de variables
//on doit juste copier se qu on herite
template <typename T>
MutantStack<T>::MutantStack(MutantStack const &other) : std::stack<T>(other)
{

}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//comme notre classe ne contient pas de variables
//on doit juste copier avec l operator de notre heritage
template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &other)
{
	if (this != &other)
		std::stack<T>::operator=(other);
	return (*this);
}
//---------------------------------------------------------------------------


template <typename T>
MutantStack<T>::~MutantStack()
{
    
}

//---------------------------------------------------------------------------
//le .c vient de la classe stack qui designe le deque de type T
//comme c est un deque on peut utiliser les methodes dessus
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (std::stack<T>::c.begin());
}
//---------------------------------------------------------------------------


template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (std::stack<T>::c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return (std::stack<T>::c.end());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
	return (std::stack<T>::c.rbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	return (std::stack<T>::c.rend());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
	return (std::stack<T>::c.rbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
	return (std::stack<T>::c.rend());
}