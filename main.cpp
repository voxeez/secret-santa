#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

void ajouterPersonne(std::list<std::string> * listePersonnes){
    std::string nom;
    for (int i = 0 ; i < 14 ; i++){
        std::cout << "Entrer nom " << i << ": ";
        std::cin >> nom;
        listePersonnes->push_back(nom);
        std::cin.ignore();
    }
}

void afficherPersonnes(std::list<std::string> * listePersonnes){
    std::list<std::string>::iterator it;
    for (it = listePersonnes->begin() ; it != listePersonnes->end() ; it++){
        std::cout << *it << std::endl;
    }
}

void randomList(std::list<std::string> * listePersonnes2){
    std::vector<std::string> vector(listePersonnes2->begin(), listePersonnes2->end());
    srand((unsigned) time(0));
    std::random_shuffle(vector.begin(), vector.end());
    std::copy(vector.begin(), vector.end(), listePersonnes2->begin());
}

int main()
{
    std::cout << "Secret Santa !" << std::endl;
    std::list<std::string> * listePersonnes = new std::list<std::string>();
    ajouterPersonne(listePersonnes);
    afficherPersonnes(listePersonnes);
    std::list<std::string> * listePersonnes2 = listePersonnes;
    randomList(listePersonnes2);
    std::cout << "===============================================\n";
    afficherPersonnes(listePersonnes2);


    return 0;
}
