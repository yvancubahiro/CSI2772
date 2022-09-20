#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int entier;
double reel;
char character;

/*
* Ask the user to enter the values of entier, reel and character
*/
void initialize() {
    cout << "Entrez un entier : ";
    cin >> entier;
    cout << "Entrez un reel : ";
    cin >> reel;
    cout << "Entrez un character : ";
    cin >> character;
}


void displayEntier1() {
    cout << endl << "-------------- AFFICHAGE 1 -------------------" << endl;
    cout << "Entier en decimal :" << entier << endl;
    cout << "Entier en octal :" << oct << entier << endl;
    cout << "Entier en hexadecimal :" << hex << entier << endl;
    cout << "-----------------------------------------------" << endl;
}



vector<int> decimalToBinary(int decimalNumber) {
    vector<int> binaryNumber;
    while (decimalNumber != 0) {
        binaryNumber.push_back(decimalNumber % 2);
        decimalNumber = decimalNumber/2;
    }
    //reverse(binaryNumber.begin(), binaryNumber.end());
    return binaryNumber;
}


void displayEntier2() {

    printf("\n--------------AFFICHAGE 2 -------------------\n");
    printf("Entier en decimal : ");
    printf("%d",entier);
    printf("\n");
    printf("Entier en octal : ");
    printf("%o", entier);
    printf("\n");
    printf("Entier en hex : ");
    printf("%x",entier);
    printf("\n");
    printf("-----------------------------------------------\n");

}

void displayReel() {
    cout << endl << "-------------- AFFICHAGE DU REEL -------------------" << endl;
    cout << "Le reel est :" << reel << endl;
    cout.precision(3);
    cout << scientific;
    cout << "La notation scientifique est : " << reel << endl;
    cout << "-----------------------------------------------" << endl;
}

void displayChar() {
    cout << endl << "-------------- AFFICHAGE DU CARACTERE -------------------" << endl;
    cout << "Le caractere est : " << character << endl;
    cout << "La valeur decimal du caractere est : " << dec <<(int)character << endl;
    cout << "-----------------------------------------------" << endl;
}

