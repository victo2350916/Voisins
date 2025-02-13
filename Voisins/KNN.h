#pragma once

#include "RessourceLoader.h"
#include <map>
#include <vector>

using namespace std;

class KNN {
public:
    /// <summary>
    /// Constructeur de la classe KNN
    /// </summary>
    /// <param name="donneesEntrainement">vecteur contenant les donn�es d'entrainement</param>
    KNN(vector<vector<float>> donneesEntrainement);

    /// <summary>
    /// compare une donn� de test avec toutes les donn�es d'entrainement afin de d�terminer si le vin est bon.
    /// </summary>
    /// <param name="vin">vin � comparer</param>
    /// <param name="k">Nombre de voisin � comparer avec le vin.</param>
    /// <returns>1 si le vin est bon, 0 � l'inv�rse</returns>
    int Classifier(vector<float> vin, int k);

    /// <summary>
    /// Comparer le si le vin est bon avec les donn�es de test vs avec la m�thode Classifier.
    /// </summary>
    /// <param name="testData">Liste des donn�es de test</param>
    /// <param name="k">nombre de voisin avec lesquelles comparer le vin</param>
    /// <returns>Une carte avec toute les possiblit�s de r�ponses ainsi que leur occurence</returns>
    map<string, int> Tester(Noeud* testData, int k);

private:
    vector<vector<float>> donneesEntrainement;
};
