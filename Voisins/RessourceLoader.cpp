#include "Ressourceloader.h"
#include <fstream>
#include <sstream>
#include <iostream>

RessourceLoader::RessourceLoader(const string& file_path, bool load_on_init) : file_path(file_path) 
{
	if (load_on_init)
	{
		loadData();
	}
}

void RessourceLoader::loadData()
{
	ifstream file(file_path);
	string line{ "" };

	while (getline(file, line))
	{
		vector<float> row;
		istringstream s(line);
		float cell;

		while (s >> cell)
		{
			row.push_back(cell);
			if (s.peek() == ',')
				s.ignore();
		}
		row.pop_back();
		data.push_back(row);	
	}
}

const vector<vector<float>>& RessourceLoader::getData() const
{
	if (data.empty())
	{
		const_cast<RessourceLoader*>(this)->loadData();
	}
	return data;
}

Noeud* RessourceLoader::GetTrainData(double k, vector<vector<float>> donnees)
{
	int nbEnreg = donnees.size() * k;
	Noeud* head = nullptr;
	Noeud* current = nullptr;

	for (int i{ 0 }; i < nbEnreg; i++)
	{
		Noeud* nouveau = new Noeud();
		nouveau->data = donnees[i];
		nouveau->next = nullptr;

		if (head == nullptr)
		{
			head = nouveau;
			current = nouveau;
		}
		else
		{
			current->next = nouveau;
			current = nouveau;
		}
	}

	return head;
}

Noeud* RessourceLoader::GetTestData(double k, vector<vector<float>> donnees)
{	
	int start{ 0 };
	start = k * donnees.size();

	Noeud* head = nullptr;
	Noeud* current = nullptr;

	for (int i{ start }; i < donnees.size(); i++)
	{
		Noeud* nouveau = new Noeud;
		nouveau->data = donnees[i];
		nouveau->next = nullptr;

		if (head == nullptr)
		{
			head = nouveau;
			current = nouveau;
		}
		else
		{
			current->next = nouveau;
			current = nouveau;
		}
	}

	return head;
}
