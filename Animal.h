//Class: Animal
//Created by: Roberto Id number: 12345
//Date: 27/05/2018

#ifndef ANIMAL_H_INCLUDED
#define ANIMAL_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class Animal{

//Methods
public: 
	//Constructors
	//Default Constructor
	Animal();
	//Contructor with parameters
	Animal(int, bool, string);

	//Getter Methods
	int getAge();
	bool getVaccinated();
	string getName();

	//Setter Methods 
	void setAge(int);
	void setVaccinated(bool);
	void setName(string);

//Attributes
private: 
	int age;
	bool vaccinated;
	string name;
};

//Development of Methods
//Constructors
//Default Constructors
Animal::Animal(){
	this -> age = 0;
	this -> vaccinated = false;
	this -> name = "";
}

//Contructor
Animal::Animal(int age, bool vaccinated, string name){
	this -> age = age;
	this -> vaccinated = vaccinated;
	this -> name = name;
}

//Getter Methods
int Animal::getAge(){
	return age;
}

bool Animal::getVaccinated(){
	return vaccinated;
}

string Animal::getName(){
	return name;
}



//Setter Methods
void Animal::setAge(int age){
this -> age = age;
}

void Animal::setVaccinated(bool vaccinated){
this -> vaccinated = vaccinated;
}

void Animal::setName(string name){
this -> name = name;
}


#endif