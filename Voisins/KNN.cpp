#include "KNN.h"
#include "Statistiques.h"
#include <algorithm>

KNN::KNN(vector<vector<float>> donneesEntrainement) : donneesEntrainement(donneesEntrainement) {}

int KNN::Classifier(vector<float> vin, int k) {
    vector<pair<double, int>> distances;
    for (auto& vinEntrainement : donneesEntrainement) {
        double distance = CalculerEuclidienne(vin, vector<float>(vinEntrainement.begin(), vinEntrainement.end() - 1));
        distances.push_back({ distance, vinEntrainement.back() });
    }

    sort(distances.begin(), distances.end());

    int compteurBon = 0, compteurMauvais = 0;
    for (int i = 0; i < k; i++) {
        if (distances[i].second == 1)
            compteurBon++;
        else
            compteurMauvais++;
    }

    return (compteurBon > compteurMauvais) ? 1 : 0;
}

map<string, int> KNN::Tester(Noeud* testData, int k) {
    map<string, int> resultats = { {"Vrai Positif", 0}, {"Faux Positif", 0}, {"Vrai Négatif", 0}, {"Faux Négatif", 0} };

    Noeud* current = testData;
    while (current != nullptr) {
        int classificationConnue = current->data.back();
        int classificationPredite = Classifier(vector<float>(current->data.begin(), current->data.end() - 1), k);

        if (classificationPredite == 1 && classificationConnue == 1)
            resultats["Vrai Positif"]++;
        else if (classificationPredite == 1 && classificationConnue == 0)
            resultats["Faux Positif"]++;
        else if (classificationPredite == 0 && classificationConnue == 0)
            resultats["Vrai Négatif"]++;
        else if (classificationPredite == 0 && classificationConnue == 1)
            resultats["Faux Négatif"]++;

        current = current->next;
    }

    return resultats;
}
