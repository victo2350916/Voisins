#pragma once

#include <vector>
#include <string>
#include "Noeud.h"

using namespace std;

/// <summary>
/// Classe qui r�cup�re les donn�es d'un fichier .csv
/// </summary>
class RessourceLoader
{
public:
	/// <summary>
	/// Constructeur pour lire le fichier
	/// </summary>
	/// <param name="file_path">Chemin vers le fichier .csv</param>
	/// <param name="load_on_init">Bool�ens afin de d�terminer si le fichier est initialis� dans la m�moire au d�but.</param>
	RessourceLoader(const string& file_path, bool load_on_init = false);

	/// <summary>
	/// Prend les donn�es du fichier .csv et les met dans un vecteur de vecteur de float.
	/// </summary>
	void loadData();
	
	/// <summary>
	/// Vecteur qui contient les donn�es du fichier .csv
	/// </summary>
	/// <returns>Un vecteur de vecteur de float</returns>
	const vector<vector<float>>& getData() const;

	/// <summary>
	/// Prend un pourcentage des donn�es du vecteur et les met dans une liste chain�.
	/// </summary>
	/// <param name="">Pourcentage de donn�es voulu (de 0 � 1) </param>
	/// <param name="">Tableau de donn�es utilis� par la m�thode</param>
	/// <returns>Une liste chain� avec le bon pourcentage de donn�es</returns>
	Noeud* GetTrainData(double, vector<vector<float>>);

	/// <summary>
	/// Prend le reste des donn�es que la m�thode GetTrainData() n'utilise pas et les met dans une liste chain�
	/// </summary>
	/// <param name="">Pourcentage des donn�es utilis� par GetTrainData()</param>
	/// <param name="">Tableau de donn�es utilis� par la m�thode</param>
	/// <returns>Une liste chain� avec le bon pourcentage de donn�es</returns>
	Noeud* GetTestData(double, vector<vector<float>>);
private:
	string file_path;
	vector<vector<float>> data;
};


