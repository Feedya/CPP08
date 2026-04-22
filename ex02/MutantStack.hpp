#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

# include <stack>
# include <iostream>

//-----------------------------------------------------------------------------------------
//STD::STACK
//
//      la std::stack n est pas un containeur, c est un adaptateur de conteneur 
//      c est comme une enveloppe au tours d un conteneur       
//
//      pour l initializer il faut faire 
//          std::stack<int, std::list<int>>    maPileList;
//          et la on aura une stack comme enveloppe et dedans une liste
//
//      elle suit la regle de LIFO (last in, first out)
//          en gros ca veut dire on a acces que au dernier elements de notre liste
//
//      les seules fonctions autoriser avec une stack
//          push()	Ajoute un élément a la fin (appelle secrètement push_back sur la liste).
//          pop()	Retire l'élément de la fin (appelle secrètement pop_back sur la liste).
//          top()	Vous montre l'élément de la fin (appelle back sur la liste).
//          size()	Vous donne le nombre d'éléments.
//          empty()	Vous dit si la pile est déserte.
//
//      FUN FACT 1 : La stack est construite sur la regle LIFO
//
//      FUN FACT 2 : Dans une staque ca sera un deque si on ne precise pas 
//
//      en fesant ca "class MutantStack : public std::stack<T>" je vais dire que ca sera un deque
//      de se type de valeur
//-----------------------------------------------------------------------------------------


template <typename T>
//on va heriter de stack a qui on doit preciser quelle type elle va stoquer
//comme quand on initialize une stack normale
class MutantStack : public std::stack<T>
{
public:
	MutantStack();
	MutantStack(MutantStack const &other);
	MutantStack &operator=(MutantStack const &other);
	~MutantStack();

    //-----------------------------------------------------------------------------------------------
    //ITERATOR : c est comme un pointeur qui pointe sur une adresse memoire de notre elements dans notre containeur
    //
    //different iterator: 
    //      
    //      iterator : comme un index avec le quelle on peut avancer en fesant ++ et --
    //
    //      const_iterator : la meme chose qu un iterator juste on ne peut pas modifier la valeur sur la quelle il pointe
    //
    //      reverse_iterator : comme un iterator normal juste les -- et ++ sont inverser
    //
    //      const_reverse_iterator : la meme chose qu un reverse_iterator juste on ne peut pas modifier la valeur
    //
    //-----------------------------------------------------------------------------------------------
    //les stack askip n ont pas d iterator mais on peut les avoir en passant
    //par l objet qui se trouve a l interieur
    //donc c est con ca mere les stack je capte pas a quoi ils servent
    //-----------------------------------------------------------------------------------------------
    //ici on va donner une signification a un mot
    //par exemple dans la premiere ligne
    //iterator sera egale a  std::stack<T>::container_type::iterator
    //iterator =  std::stack<T>::container_type::iterator
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
    //-----------------------------------------------------------------------------------------------

	iterator begin();
	iterator end();

	const_iterator begin() const;
	const_iterator end() const;

	reverse_iterator rbegin();
	reverse_iterator rend();

	const_reverse_iterator rbegin() const;
	const_reverse_iterator rend() const;
};

# include "MutantStack.tpp"

#endif