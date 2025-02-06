#pragma once

#include <vector>

using namespace std;

/// <summary>
/// Calcule la moyenne d'un vecteur de nombre
/// </summary>
/// <param name="">Vecteur de nombre</param>
/// <returns>La moyenne</returns>
int CalculerMoyenne(vector<int>);

/// <summary>
/// Calcule la médianne d'un vecteur de nombre
/// </summary>
/// <param name="">Vecteur de nombre</param>
/// <returns>La médianne</returns>
int CalculerMedianne(vector<int>);

/// <summary>
/// Calcule l'écart type d'un vecteur de nombre
/// </summary>
/// <param name="">Vecteur de nombre</param>
/// <returns>l'écart type</returns>
int CalculerEcart(vector<int>);

/// <summary>
/// Calcule l'euclidienne entre deux vecteur de nombre
/// </summary>
/// <param name="">Premier vecteur de nombre</param>
/// <param name="">Deuxième vecteur de nombre</param>
/// <returns>L'euclidienne</returns>
double CalculerEuclidienne(vector<double>, vector<double>);

/// <summary>
/// Calcule la Manhatan entre deux vecteurs
/// </summary>
/// <param name="">Premier vecteur de nombre</param>
/// <param name="">Deuxième vecteur de nombre</param>
/// <returns>La Manhatan</returns>
double CalculerManhatan(vector<double>, vector<double>);


