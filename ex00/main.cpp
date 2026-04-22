#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

//-------------------------------------------------------
//push_back()
//
//  cette fonction vas mettre l'elements a la fin de 4 conteneur
//
//      std::vector
//      std::list
//      std::deque
//      std::string
//-------------------------------------------------------

int main()
{

    //-----------------------------------------------------------------
    //LIST
    //------------------------------------------------------------------
    //FUN FACT 1
    //  la memoire d une liste est dispercer par tout dans la memoire
    //
    //FUN FACT 2
    //  une liste est construite comme un liste chainer en avec
    //  un next
    //  et un prev
    //  donc chaque maillonts est coller aux prochine et au prev
    //
    // FUN FACT 3
    //  on ne peut pas indexer une list
    //------------------------------------------------------------------
    std::cout << "\nTest list container"<< std::endl;
    std::list<int> list;
    for (int i = 0; i < 999; i++)
    {
        list.push_back(i);
    }
    try
    {
        easyfind(list, 69);
        easyfind(list, 1111);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    
    //-----------------------------------------------------------------------------------
    //VECTOR
    //-----------------------------------------------------------------------------------
    //FUN FACT 1
    //le vecctor a une memoire toute colle en mode c est une ligne
    //mais std::list a plein de petit bout de sa memoire partout
    //se qui rajoute aux vecteur le talent d etre tres rapide en execution
    //
    //FUN FACT 2
    //le compilateur ne doit pas chercher des petits bout
    //si a un moment il a plus de ligne droite opour continuer a remplir le vecteur
    //-----------------------------------------------------------------------------------
	std::cout << "\nTest vector container" << std::endl;
    std::vector<int> vector;
    
	for (int i = 0; i < 7; i++)
	{
		vector.push_back(i);
	}
	try
	{
		easyfind(vector, 3);
		easyfind(vector, 20);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

    //-----------------------------------------------------------------------------------
    //TABLEAU DE INT
    //-----------------------------------------------------------------------------------
    //FUN FACT 1
    //  on peut indexer un tableau en fesant tab[2]
    //  mais on peut aussi le faire comme ca 2[tab]
    //-----------------------------------------------------------------------------------
    std::cout << "\nTest int tab"<< std::endl;
    int tab[] = {10, 20, 30, 40, 50};
    try
	{
        easyfind(tab, 10);
		easyfind(tab, 11);
	}
	catch (std::exception &e)
	{
        std::cout << e.what() << std::endl;
	}
	

    //-----------------------------------------------------------------------------------
    //DEQUE
    //-----------------------------------------------------------------------------------
    //c est comme une liste homogene(que le meme type peut etre a l interieur)
    //  mais meilleure sous le capot
    //
    //FUN FACT 1
    //  Sa memoire est en ilt d elements repartis dans la dans la stack
    //
    //FUN FACT 2
    //  on peut l indexer comme un vecteur se que tu ne peux pas faire avec une liste
    //
    //donc en gros deque est meilleure qu une liste
    //-----------------------------------------------------------------------------------
    std::cout << "\nTest deque container"<< std::endl;
    std::deque<int> deque;

    for (int i = 0; i < 500; i++)
    {
        deque.push_back(i);
    }

    try
    {
        easyfind(deque, 1);
        easyfind(deque, 501);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    return (0);
}