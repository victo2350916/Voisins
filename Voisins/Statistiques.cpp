#include <vector>
#include <algorithm>
#include <cmath>

#include "Statistiques.h"


int CalculerMoyenne(vector<int> tableauNombre)
{
	int moyenne{ 0 };
	int total{ 0 };

	// Additionne tout les nombres et le met dans la variable total
	for (int i = 0; i < tableauNombre.size(); i++) 
	{
		total += tableauNombre[i];
	}

	// Calcule de la moyenne
	moyenne = total / tableauNombre.size();

	// Retourne la moyenne
	return moyenne;
}

int CalculerMedianne(vector<int> tableauNombre)
{
	int medianne{ 0 };

	// met les nombers du tableau en ordre croissant
	sort(tableauNombre.begin(), tableauNombre.end());

	if (tableauNombre.size() % 2 == 0) // Si le tableau est pair
	{
		int index{ 0 };

		index = tableauNombre.size() / 2;

		medianne += tableauNombre[index];

		index -= 1;

		medianne += tableauNombre[index];

		medianne = medianne / 2;
	}
	else // Sinon
	{
		int index{ 0 };

		index = (tableauNombre.size() / 2) + 0.5;

		medianne = tableauNombre[index];
	}

	return medianne;
}

int CalculerEcart(vector<int> tableauNombre)
{
	double moyenne{ 0 };
	int temp{ 0 };
	int total{ 0 };
	double ecart{ 0 };

	moyenne = CalculerMoyenne(tableauNombre);

	for (int i{ 0 }; i < tableauNombre.size(); i++)
	{
		temp = tableauNombre[i] - moyenne;

		total += temp * temp;
	}

	ecart = sqrt(total);

	return ecart;
}

double CalculerEuclidienne(vector<double> point1, vector<double> point2)
{
	double somme{ 0 };
	double difference{ 0 };

	if (point1.size() != point2.size())
	{
		return 0;
	}

	for (int i{ 0 }; i < point1.size(); i++)
	{
		difference = point1[i] - point2[i];
		somme += difference * difference;
	}

	return std::sqrt(somme);

}

double CalculerManhatan(vector<double> point1, vector<double> point2)
{

	double somme{ 0 };

	if (point1.size() != point2.size())
	{
		return 0;
	}

	for (int i{ 0 }; i < point1.size(); i++)
	{
		somme += abs(point1[i] - point2[i]);
	}

	return somme;

}




