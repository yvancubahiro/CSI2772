#include "monfichier2.h"

int main(void) {
	char choix;
	int nvolume = 0; //nombre de fois que la fonction volume a été lancee
	int nsurface = 0; //nombre de fois que la fonction surface a été lancee
	double rayon, hauteur;
	while (1)
	{
		choix = menu();
		switch (choix)
		{
		case '1': cout << endl << "Calcul de la surface :" << endl;
			cout << "Donnez le rayon: ";
			cin >> rayon;
			nsurface = surface(rayon);
			break;
		case '2': cout << endl << "Calcul du volume :" << endl;
			cout << "Donnez le rayon: ";
			cin >> rayon;
			cout << "Donnez la hauteur: ";
			cin >> hauteur;
			nvolume = volume(rayon, hauteur);
			break;
		case '3':cout << endl << "Sortie du programme" << endl;
			cout << "La fonction volume a ete lancee " << nvolume << " fois" << endl;
			cout << "La fonction surface a ete lancee " << nsurface << " fois" << endl;
			exit(0);
		default: break;
		}
	}
}