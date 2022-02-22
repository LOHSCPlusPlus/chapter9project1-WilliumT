#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// This file is ONLY an example of how to load a struct from a file
struct Car{
  enum {MAX_CHAR_LEN=100};
  char name[MAX_CHAR_LEN];
  double MPG;
  int Cylinders;
  double Displacement;
  double Horsepower;
  double Weight;
  double Acceleration;
  int Model;
  char Origin [MAX_CHAR_LEN];
  bool ValidEntry;
  Car();
};

Car::Car (){
for(int index = 0; index < MAX_CHAR_LEN; index++){
  name[index] = '\0';
  Origin[index] = '\0';
}
ValidEntry = false;
MPG = 0;
Cylinders = 0;
Displacement = 0;
Horsepower = 0;
Weight = 0;
Acceleration = 0;
Model = 0;
}

void printCar(Car car);

const int MAX_CARS=500;
Car readcar(ifstream &inFile){
    Car car; 
    inFile.get(car.name, Car::MAX_CHAR_LEN, ';');
    inFile.ignore(100,';');
    inFile >> car.MPG;
    inFile.ignore(100,';');
    inFile >> car.Cylinders;
    inFile.ignore(100,';');
    inFile >> car.Displacement;
    inFile.ignore(100,';');
    inFile >> car.Horsepower;
    inFile.ignore(100,';');
    inFile >> car.Weight;
    inFile.ignore(100,';');
    inFile >> car.Acceleration;
    inFile.ignore(100,';');
    inFile >> car.Model;
    inFile.ignore(100,';');
    inFile >> car.Origin;
    inFile.ignore(100,'\n');
    // If we reached the end of the file while reading, then the entry is not valid
    car.ValidEntry = !inFile.eof();
    return car;
}



void printCar(Car car){
  //if(car.isValid == true);
    cout << car.name << ";" << car.MPG << ";" << car.Cylinders << ";" << car.Displacement << ";" << car.Horsepower << ";" << car.Weight << ";" << car.Acceleration << ";" << car.Model << ";" << car.Origin <<";" << car.ValidEntry << ";" << endl;
  }
//}

int readCars(Car car[]) {
    ifstream carFile("cars.txt");
    int numCars = 0;
    while(carFile.peek() != EOF && numCars < MAX_CARS) {
        car[numCars] = readcar(carFile);
        numCars++;
    }
    return numCars;
}

void PrintCars (Car car[MAX_CARS]){
for (int index = 0; index < MAX_CARS; index++){

if (car[index].ValidEntry == true){
cout << "Index " << index << ": ";
printCar(car [index]);
cout << endl;
}
}
}

void PrintCarByOrigin (Car car[MAX_CARS]){
char Input [20];
cout << "What origin do you want? ";
cin >> Input;
for (int index = 0; index < MAX_CARS; index++){

if (strcmp (Input, car[index].Origin) == 0){
cout << "Index " << index << ": ";
printCar(car [index]);
cout << endl;
}
}
}

int readInt(const char prompt[]){
    int temp = 0;
    cout << prompt;
    cin >> temp;
    while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << prompt;
        cin >> temp;
    }
    return temp;
}

double readDouble(const char prompt[]){
    double temp = 0;
    cout << prompt;
    cin >> temp;
    while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << prompt;
        cin >> temp;
    }
    return temp;
}

void RemoveCar (Car car [MAX_CARS]){
int deleteIndex = readInt("What Car Index would you like removed?: ");
car[deleteIndex].ValidEntry = false;
}


void AddCar(Car car[MAX_CARS]){
  for (int index = 0; index < MAX_CARS; index++){

if (car[index].ValidEntry == false){
cin.ignore(100,'\n');
cout << "Enter Car name: ";
cin.getline(car[index].name, Car::MAX_CHAR_LEN);
car[index].MPG = readDouble("Enter the MPG: ");
car[index].Cylinders = readInt("Enter the Cylinders: ");
car[index].Displacement = readDouble("Enter the Displacement: ");
car[index].Horsepower = readDouble("Enter the Horsepower: ");
car[index].Weight = readDouble("Enter the Weight: ");
car[index].Acceleration = readDouble("Enter the Acceleration: ");
car[index].Model = readInt("Enter the Model: ");
cout << "Enter the Origin: ";
cin >> car[index].Origin;
cout << endl;
car[index].ValidEntry = true;
return;
}
}
}

void DisplayMenu(int choice, Car car[MAX_CARS]){
 if (choice == 1){
   PrintCars(car);
 }else if (choice == 2){
   RemoveCar(car);
 }else if (choice == 3){
   AddCar(car);
 }else if (choice == 4){
  PrintCarByOrigin (car);
 }else if (choice == -1){
  cout << endl;
  cin.ignore(100,'\n');
}else{
 cout << "Invalid input.";

}
}

int main() {
    Car car[MAX_CARS]; 
    int num = readCars(car);
    cout << "Nums: " << num << endl;

int choice = 0;
while(choice != -1){
  cout << "Which option would you like?: " << endl;
  cout << "1.Display the car list" << endl;
  cout << "2.Remove a car from the list" << endl;
  cout << "3.Add a car to list" << endl;
  cout << "4.Display Cars by origin "<< endl;
  cout << "5. Enter -1 to Quit" << endl; 
  cout << "Enter your choice: ";
  cin >> choice;
  DisplayMenu(choice, car);

}
  return 0;
}

