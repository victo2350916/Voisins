#pragma once

#include <vector>
#include <string>
#include "Noeud.h"

using namespace std;

class RessourceLoader
{
public:
	RessourceLoader(const string& file_path, bool load_on_init = false);
	void loadData();
	const vector<vector<float>>& getData() const;
	Noeud* GetTrainData(double, vector<vector<float>>);
	Noeud* GetTestData(double, vector<vector<float>>);
private:
	string file_path;
	vector<vector<float>> data;
};


