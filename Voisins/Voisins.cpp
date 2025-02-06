#include <iostream>
#include "RessourceLoader.h"

void printList(Noeud* node) {
    while (node != nullptr) {
        for (const float& val : node->data) {
            cout << val << " ";
        }
        cout << endl;
        node = node->next;
    }
}

int main() {
    // Initialisation de RessourceLoader avec le fichier CSV et chargement des donn�es
    RessourceLoader loader("binary-winequality-white.csv", true);
    vector<vector<float>> data = loader.getData();

    // R�cup�ration des donn�es d'entra�nement sous forme de liste cha�n�e
    Noeud* practiceData = loader.GetTrainData(0.1, data);

    // Affichage de la liste cha�n�e des donn�es d'entra�nement
    cout << "Donn�es d'entra�nement (liste cha�n�e) :" << endl;
    printList(practiceData);

    // R�cup�ration des donn�es de test sous forme de liste cha�n�e
    Noeud* testData = loader.GetTestData(0.1, data);

    // Affichage de la liste cha�n�e des donn�es de test
    cout << "Donn�es de test (liste cha�n�e) :" << endl;
    printList(testData);

    return 0;
}
