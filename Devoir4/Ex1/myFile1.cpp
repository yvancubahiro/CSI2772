/*Ex1 devoir4 CSI2772A*/

#include <iostream> 
#include "myFile1a.h"
#include "myFile1b.h"
using namespace std;


int main() {
	Course* Math = new Course(100, 60);
	Course* ITI = new Course(200, 120);
	Student* Yan = new Student(1, 35);
	Student* Jane = new Student(2, 35);
	Yan->addCourse(Math, 15);
	Yan->addCourse(ITI, 12);
	Jane->addCourse(Math, 11);
	Jane->addCourse(ITI, 16);
	cout << "The total hours of Yan is " << Yan->totalHours() << endl;
	cout << "The average of Yan is " << Yan->average() << endl;
	cout << "The total hours of Jane is " << Jane->totalHours() << endl;
	cout << " The average of Jane is " << Jane->average() << endl;
	delete Math;
	delete ITI;
	delete Yan;
	delete Jane;
	cout << " Enter a number to exit..." << endl;
	return 0;
}

 Course::Course(int a, int b){
	num = a;
	hours = b;

} 

int Course::getHours(){
	return hours;
}

int Course::getNum(){
	return num;
}

Student::Student(int a, int b){
	numID = a;
	maxCourses = b;
	nbCourses = 0;
	List_grades = new int [maxCourses];
	
	List_courses = new Course * [maxCourses];

}

Student::~Student(){

	delete List_courses;
	delete List_grades;
	
}

double Student::average(){
	double result=0.0;

	if(nbCourses>0){
		for(int i=0;i<nbCourses;i++){
			result+=List_grades[i];

		}

		result=result/nbCourses;
	}
	return result;

}

int Student::totalHours(){
	int total=0;

	if(nbCourses>0){
		for(int i=0;i<nbCourses;i++){
			total+=List_courses[i]->getHours();
		}

	}
	
	return total;

}

bool Student::addCourse(Course* adr, int max){

	bool result=false;

	if(nbCourses<35){
		List_courses[nbCourses]=adr;
		List_grades[nbCourses]= max;
		nbCourses++;
		result=true;

	}

	return result;
	


}