#include "RessourceLoader.h"
#include "KNN.h"
#include <iostream>

using namespace std;

int main() {
    RessourceLoader rl("binary-winequality-white.csv", true);
    vector<vector<float>> data = rl.getData();

    KNN knn(data);
    Noeud* trainData = rl.GetTrainData(0.7, data);
    Noeud* testData = rl.GetTestData(0.7, data);

    map<string, int> resultats = knn.Tester(testData, 5);

    for (const auto& resultat : resultats) {
        cout << resultat.first << " : " << resultat.second << endl;
    }

    return 0;
}

