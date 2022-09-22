#pragma once
using namespace std;
#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>

int nSurface = 0;
int nVolume = 0;


char menu() {
	cout << "Que souhaitez-vous faire ?:" << endl
		<< "	-Calculer la surface du disque de rayon (Tapez 1)" << endl
		<< "	-Calculer le volume du cylindre de rayon et hauteur (Tapez 2)" << endl
		<< "	-Quittez le programme (Tapez 3)" << endl;
	char choix;
	cin >> choix;

	return choix;
}

int surface(double rayon) {
	double surface = pow(rayon, 2) * 3.141592;
	cout << "La surface est de " << setprecision(2) << surface << endl;
	return ++nSurface;
}

double volume(double rayon, double hauteur) {
	double volume = pow(rayon, 2) * 3.141592 * hauteur;
	cout << "le volume est de " << setprecision(2) << volume << endl;
	return ++nVolume;
}