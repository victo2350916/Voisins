#pragma once
#include <vector>


/// <summary>
/// Noeud pour faire une liste chain� de vecteurs avec la classe RessourceLoader.
/// </summary>
struct Noeud
{
	std::vector<float> data;
	Noeud* next;
};
