/*Ex2 - Devoir 3 CSI2772A*/

#include "myLinkedList.h"

int main()
{
	Evaluation* first = NULL;	//Pointer on the first element of the list
						//the list is empty, so initialization to NULL
	int number = 0;			//number of elements in the linked  list 
	int choice;			//choice for the menu

	do
	{
		cout << endl << endl << "1) Display  of the complete linked list.\n";
		cout << "2) Insert an element\n";
		cout << "3) Remove an element.\n";
		cout << "4) Calculation of the class average.\n";
		cout << "5) Exit the program.\n" << endl << endl;
		cout << "Your choice ??:";
		cin >> choice;

		switch (choice)
		{
		case 1: display(first);
			break;
		case 2: first = add(first, number);
			break;
		case 3: first = remove(first, number);
			break;
		case 4: average(first, number);
			break;
		case 5: exit(0);
		default:
			break;
		}
	} while (1);
	return 0;
}





/*
*add() Function*
**/

Evaluation* add(Evaluation* p, int& number)
{
	Evaluation *evaluation = new Evaluation;
	Evaluation newEvaluation;
	int position;
	bool validPosition = false;

	//saisie de donnees	de student
	cout << "Enter the name of the Student (20 characters max.) : ";
	cin >> newEvaluation.student;
	cout << "Enter the grade of the student : ";
	cin >> newEvaluation.grade;

	//choix de la position de student
	if(number == 0){
		cout << "The element will be added to the first position since it's the first one !" << endl;
	}else{
		cout << "Choose the place of " << newEvaluation.student << " (between 1 and " << number << ") : ";

		// verification de la valeur de position
		while (!validPosition)
		{
			cin >> position;
			position;
			if(position <= 0 || position > number){
				cout << "The entered place is not valid, try a place between 1 and " << number << " : ";
			}else{
				validPosition = true;
			}
		}   
	}

	
	//ajout de donnees dans le linkedList
	if(number == 0){//si la liste est vide
		p = new Evaluation;
		*p = newEvaluation;
	}else{ // s'il y a d autres elements
		Evaluation* currentEvaluation = p;
		for(int i = 1; i<position;i++){ // navigation a la position ou ajouter l element
			currentEvaluation = currentEvaluation->next;
		}
		newEvaluation.next = currentEvaluation->next;
		currentEvaluation->next = new Evaluation;
		*currentEvaluation->next = newEvaluation;
	}

	number++;
	return p;
}


/**
*remove() Function*
**/

Evaluation* remove(Evaluation* p, int& number)
{
	if(number > 0){
		Evaluation* currentEvaluation = p;
		
		//Display all evaluations
		for(int i = 1; i<=number; i++){
			cout << "Evaluation " << i << " -------- student : " << currentEvaluation->student << " , grades : " << currentEvaluation->grade << "." << endl;
			currentEvaluation = currentEvaluation->next;
		}
		
		
		int position = 0;
		cout << "Choose the number of Evaluation to delete (between 1 and " << number << " ) : ";
		cin >> position;
		//verification de l'entree
		while(position>number || position <1){
			cout << "Please choose a number between 1 and "<< number <<" ) : ";
			cin >> position;
		}

		if(number = 1 && position == 1){//s'il y a un element dans la liste
			p = NULL;
		}else if(position == 1){ // s'il y a plusieurs elements et qu on efface la premiere
			p = p->next;
		}else{ // s'il y a plusieurs elements et qu on efface un element a une postion donnee
			currentEvaluation = p;
			for(int i = 1;i<position-1; i++){
				currentEvaluation = currentEvaluation->next;
			}
			currentEvaluation->next = (currentEvaluation->next)->next;
			
		}
		number--;
		cout << "deleted ! " << endl;
	}else{
		cout << "No evaluation to delete ! " << endl;
	}
	return p;
}



/**
*display() Function *
**/
void display(Evaluation* p)
{
	if(p != NULL){//si la liste n est pas vide

		Evaluation* currentEvaluation = p;
		int i = 1;
		while(true){ // naviger a travers de la liste
			cout << "Evaluation " << i++ << " -------- student : " << currentEvaluation->student << " , grades : " << currentEvaluation->grade << endl;
			currentEvaluation = currentEvaluation->next;
			if(currentEvaluation->next == NULL){
				break;
			}
		}
	}else{ //si la liste est vide
		cout << "No Evaluation to display !" << endl;
	}
}


/**
*average() Function *
***/
int average(Evaluation* p, int const& nbre)
{
	int average = 0;
	if(nbre == 0){ //si la liste est vide
		cout << "No evaluation to calculate average" << endl;
		return 0;
	}else{ // s il ya plusieurs elements
		Evaluation *currentEvaluation = p;
		for(int i = 0; i<nbre; i++){ // naviguer a travers de la liste
			average += currentEvaluation->grade;
			currentEvaluation = currentEvaluation->next;
		}
		average = average/nbre;
		cout << "The average is " << average << endl;
		return 1;
	}
}






