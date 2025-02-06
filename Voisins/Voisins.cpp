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
    // Initialisation de RessourceLoader avec le fichier CSV et chargement des données
    RessourceLoader loader("binary-winequality-white.csv", true);
    vector<vector<float>> data = loader.getData();

    // Récupération des données d'entraînement sous forme de liste chaînée
    Noeud* practiceData = loader.GetTrainData(0.1, data);

    // Affichage de la liste chaînée des données d'entraînement
    cout << "Données d'entraînement (liste chaînée) :" << endl;
    printList(practiceData);

    // Récupération des données de test sous forme de liste chaînée
    Noeud* testData = loader.GetTestData(0.1, data);

    // Affichage de la liste chaînée des données de test
    cout << "Données de test (liste chaînée) :" << endl;
    printList(testData);

    return 0;
}
