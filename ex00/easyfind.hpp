#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include<algorithm>
#include <iostream>
# include<exception>

//petits truque ici c est que si notre exception on l herite de std::exception
//alors on n est pas obliger de la catch elle presicement on peut juste catch
//la generale et elle sera dedans
class PasTrouver : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Nombre pas trouver");
		}
	
};

//malheuresement dans le CPP 98 on ne peut pas verifier si  T est un contaneur valide pour la fonction
//donc si on allume ma fonciton on lui donnant une string
//par exemple ca va sortir des erreurs de compilation
//donc on doit faire plusieurs surcharge d operateur pour cette fonction

//easyfind pour les variables qui ont les fonctions begin et end
    template <typename T>
void easyfind(T &container, int n)
{
    //un iterator c est se qui se trouve a l interieur d une template si une template en a 
	typename T::iterator start_index;
    typename T::iterator end_index;

    end_index = container.end();
    start_index = container.begin();

    while (start_index != end_index)
    {
        if (*start_index == n)
        {    
            std::cout << "on a trouver!!!!!!!!!!" << std::endl;
            return ;
        }
        start_index ++;
    }
    throw (PasTrouver());
}

//pour tableau de int qui n ont pas de end et begin

//ici c est un peu technique
//mais en gros
//on dis au compilateur qu on a un unsigned int N qui vient avec mon T
//le compilateur il va chercher c est quoi ce N 
//et on va lui montrer que N est la taille en fesant ca "T (&tab)[N]"
//et avec ca il va capter que c est la taille
//c est un peu un truque qu il faut apprendre par coeur
template <typename T, unsigned int N>
void    easyfind(T (&tab)[N], int n)
{
    unsigned int i = 0;

    while (i != N)
    {
        if (tab[i] == n)
        { 
            std::cout << "on a trouver dans le tableau!!!!!!!!" << std::endl;
            return ;
        }
        i++;
    }
    throw(PasTrouver());
}


#endif