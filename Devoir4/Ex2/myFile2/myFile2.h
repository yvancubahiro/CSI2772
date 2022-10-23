#include <cstdlib> 
using namespace std;

const int INITIAL_SIZE = 5; //Longueur initiale du tableau

class SetInt
{
public:
	SetInt() : elem(NULL), size(0) {};
	SetInt(int[], int);
	~SetInt();
	SetInt(const SetInt&);  // copy constructor
	void add(int);
	void remove(int);
	bool contains(int);
	int nbElem();
	int* tabElem();
private:
	int* elem;
	int size;
	bool containsIn(int n, int&);
};


SetInt::SetInt(int* a, int s) { //constructeur avec tableau et longueur
	size = s;
	elem = new int[size];
	for (int i = 0; i < size; i++) {
		*(elem + i) = *(a + i);
	}
}


SetInt :: ~SetInt() { //constructeur sans arguments
	delete elem;
	cout << "Object deleted !";
}

SetInt::SetInt(const SetInt& obj) { // constructeur de recopie
	size = obj.size;
	elem = new int[size];
	for (int i = 0; i < size; i++) {
		*(elem + i) = *(obj.elem + i);
	}
}

void SetInt::add(int a) {
	if (!contains(a)) { // verifie si a n'est pas deja dans le tableau
		if (size % INITIAL_SIZE == 0) { // si le tableau et pleine, augmenter sa taille

			int* extendedTable = new int[size + INITIAL_SIZE]; // cree un nouveau tableau x2 plus grand
			for (int i = 0; i < size; i++) { // copie tous les elements de l'ancien tableau dans le nouveau
				*(extendedTable + i) = *(elem + i);
			}
			elem = extendedTable; // assigner le nouveau tableau a l'ancien

		}
		*(elem + size) = a; // ajouter a au tableau
		size++; 
	}
	else { //si a est dans le tableau ...
		cout << "Number already in the list !" << endl;
	}
}

void SetInt::remove(int a) {
	for (int i = 0; i < size; i++) {
		if (*(elem + i) == a) { // si a est dans le tableau
			
			for (int k = i; k < size; k++) { //decaler tous les elements de 1 index
				*(elem + k) = *(elem + k + 1);
			}
			size--; 
			*(elem + size) = NULL; // effacer le dernier index
			break;
		}
	}
	
}

bool SetInt::contains(int a) {
	for (int i = 0; i < size; i++) { // recherche de a
		if (*(elem + i) == a) { // si a est dans le tableau
			return true; //retourne vrai
		}
	}
	return false;
}

int SetInt::nbElem() {
	return size;
}

int* SetInt::tabElem() {
	return elem; // retourne le tableau
}

bool SetInt::containsIn(int number, int& position) {
	return *(elem + position - 1) == number; 
}


