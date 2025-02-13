#include "Ressourceloader.h"
#include <fstream>
#include <sstream>
#include <iostream>

RessourceLoader::RessourceLoader(const string& file_path, bool load_on_init) : file_path(file_path) 
{

	//seulement initier les donn�es � la d�claration seulement si n�cessaire
	if (load_on_init)
	{
		loadData();
	}
}

void RessourceLoader::loadData()
{
	//ouvrir le fichier et initier une ligne vide
	ifstream file(file_path);
	string line{ "" };

	while (getline(file, line))
	{
		vector<float> row;
		istringstream s(line);
		float cell;

		while (s >> cell) //tant qu'on peut extraire des floats du stringstream
		{
			//ajouter le float au vecteur
			row.push_back(cell);

			//ignorer la virgule si elle est le prochain char
			if (s.peek() == ',')
				s.ignore();
		}

		//ajouter le vecteur au data
		data.push_back(row);	
	}
}

const vector<vector<float>>& RessourceLoader::getData() const
{
	if (data.empty())
	{
		//call loadData() en const et initialiser la data
		const_cast<RessourceLoader*>(this)->loadData();
	}
	return data;
}

Noeud* RessourceLoader::GetTrainData(double k, vector<vector<float>> donnees)
{
	//faire une chaine de noeud et retourner le d�but

	int nbEnreg = donnees.size() * k; // end = size * k
	Noeud* head = nullptr;
	Noeud* current = nullptr;

	for (int i{ 0 }; i < nbEnreg; i++)
	{
		//...
		Noeud* nouveau = new Noeud();
		nouveau->data = donnees[i];
		nouveau->next = nullptr;

		if (head == nullptr) //ex�cuter au tout d�but
		{
			head = nouveau;
			current = nouveau;
		}
		else //le reste du temps:
		{
			current->next = nouveau;
			current = nouveau;
			

			//on ne change pas head pour garder une trace du d�but
		}
	}

	return head;
}

Noeud* RessourceLoader::GetTestData(double k, vector<vector<float>> donnees)
{	
	//faire une chaine de noeud et retourner le d�but

	int start{ 0 };
	start = k * donnees.size(); //start = k-1% = k * size

	Noeud* head = nullptr;
	Noeud* current = nullptr;

	for (int i{ start }; i < donnees.size(); i++)
	{
		//...
		Noeud* nouveau = new Noeud;
		nouveau->data = donnees[i];
		nouveau->next = nullptr;

		if (head == nullptr) //ex�cuter la premi�re fois
		{
			head = nouveau;
			current = nouveau;
		}
		else //le reste du temps
		{
			current->next = nouveau;
			current = nouveau;

			//on ne change pas head pour garder une trace du d�but
		}
	}

	return head;
}
