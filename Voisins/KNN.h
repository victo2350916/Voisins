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
    /// <param name="donneesEntrainement">vecteur contenant les données d'entrainement</param>
    KNN(vector<vector<float>> donneesEntrainement);

    /// <summary>
    /// compare une donné de test avec toutes les données d'entrainement afin de déterminer si le vin est bon.
    /// </summary>
    /// <param name="vin">vin à comparer</param>
    /// <param name="k">Nombre de voisin à comparer avec le vin.</param>
    /// <returns>1 si le vin est bon, 0 à l'invèrse</returns>
    int Classifier(vector<float> vin, int k);

    /// <summary>
    /// Comparer le si le vin est bon avec les données de test vs avec la méthode Classifier.
    /// </summary>
    /// <param name="testData">Liste des données de test</param>
    /// <param name="k">nombre de voisin avec lesquelles comparer le vin</param>
    /// <returns>Une carte avec toute les possiblités de réponses ainsi que leur occurence</returns>
    map<string, int> Tester(Noeud* testData, int k);

private:
    vector<vector<float>> donneesEntrainement;
};
