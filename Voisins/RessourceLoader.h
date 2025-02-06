#pragma once

#include <vector>
#include <string>
#include "Noeud.h"

using namespace std;

/// <summary>
/// Classe qui récupère les données d'un fichier .csv
/// </summary>
class RessourceLoader
{
public:
	/// <summary>
	/// Constructeur pour lire le fichier
	/// </summary>
	/// <param name="file_path">Chemin vers le fichier .csv</param>
	/// <param name="load_on_init">Booléens afin de déterminer si le fichier est initialisé dans la mémoire au début.</param>
	RessourceLoader(const string& file_path, bool load_on_init = false);

	/// <summary>
	/// Prend les données du fichier .csv et les met dans un vecteur de vecteur de float.
	/// </summary>
	void loadData();
	
	/// <summary>
	/// Vecteur qui contient les données du fichier .csv
	/// </summary>
	/// <returns>Un vecteur de vecteur de float</returns>
	const vector<vector<float>>& getData() const;

	/// <summary>
	/// Prend un pourcentage des données du vecteur et les met dans une liste chainé.
	/// </summary>
	/// <param name="">Pourcentage de données voulu (de 0 à 1) </param>
	/// <param name="">Tableau de données utilisé par la méthode</param>
	/// <returns>Une liste chainé avec le bon pourcentage de données</returns>
	Noeud* GetTrainData(double, vector<vector<float>>);

	/// <summary>
	/// Prend le reste des données que la méthode GetTrainData() n'utilise pas et les met dans une liste chainé
	/// </summary>
	/// <param name="">Pourcentage des données utilisé par GetTrainData()</param>
	/// <param name="">Tableau de données utilisé par la méthode</param>
	/// <returns>Une liste chainé avec le bon pourcentage de données</returns>
	Noeud* GetTestData(double, vector<vector<float>>);
private:
	string file_path;
	vector<vector<float>> data;
};


