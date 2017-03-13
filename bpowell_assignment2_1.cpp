#include<iostream>

using namespace std;

const int DEF_CAP = 10;
const int SPOONS_PER_CUP = 1;


/*
CoffeMachine class: Creates a coffee machine that has a name, variable capacities, and tracks resources. 

constructors:
CoffeMachine() constructor assigns a generic name and default capacities
CoffeeMachine(string) assigns the specified name and default capacities
CoffeeMachine(string, int, int) assigns the specified name, and respective water capacity and coffee capacity

public functions:

void makeCups(int numCups) makes numCups cups of coffee and keeps track of the resource reduction

void addWater(int cupsWater) adds cupsWater to curr_water, simulates adding water to machine

void addCoffee(int spoonsCoffee) adds spoonsCoffee to curr_coffee, simulates adding coffee to machine 

void displayCM() displays the name of the coffee machine and current values of curr_water and curr_coffee, showing available resources
*/

class CoffeeMachine {
public:
  
  CoffeeMachine(){
    name = "UNTITLED";
    curr_water = 0;
    curr_coffee = 0;
    water_capacity = DEF_CAP;
    coffee_capacity = DEF_CAP;
    cout << "Creating Coffee Machine " << name << " with empty resources" << endl;
  }
  CoffeeMachine(string name){
    this->name = name;
    curr_water = 0;
    curr_coffee = 0;
    water_capacity = DEF_CAP;
    coffee_capacity = DEF_CAP;
    cout << "Starting up Coffee Machine " << name << " with empty resources." << endl;
  }
  CoffeeMachine(string name, int water_capacity, int coffee_capacity){
    this->name = name;
    this->water_capacity = water_capacity;
    this->coffee_capacity = coffee_capacity;
    curr_water = 0;
    curr_coffee = 0;
    cout << "Starting up Coffee Machine " << name << " with empty resources and defined capacities." << endl;

  }

  ~CoffeeMachine(){
    cout << "Shutting down Coffee Machine " << name << " with the following resources" << endl;
    cout << "water: " << curr_water << endl;
    cout << "coffee: " << curr_coffee << endl;
  }  

  string name;
  void makeCups(int numCups) {
    cout << "Ordered " << numCups << " cups of coffee (DECAF)" << endl;  
    if ((numCups > curr_water) || ((numCups*SPOONS_PER_CUP) > curr_coffee))
      cout << "Not enough resources to complete order" << endl;
    else{
      for (int i = 0; i < numCups; i++)
	makeSingleCup();
    }
    cout << endl;
  }
  void addWater(int cupsWater){ 
    if (curr_water + cupsWater >= water_capacity)
      curr_water = water_capacity;
    else
      curr_water = curr_water + cupsWater;
  }
  void addCoffee(int spoonsCoffee) {
    if (curr_coffee + spoonsCoffee > coffee_capacity)
      curr_coffee = coffee_capacity;
    else
      curr_coffee = curr_coffee + spoonsCoffee;
  }
  void displayCM(){ 
    cout << "Current state of CM: DECAF" << endl;
    cout << "WATER: " << curr_water << "/" << water_capacity << "(CUPS)" << endl;
    cout << "COFFEE: " << curr_coffee << "/" << coffee_capacity << "(SPOONS)" << endl << endl;
  }

private:
  int water_capacity;
  int coffee_capacity;
  int curr_water;
  int curr_coffee;
  void makeSingleCup(){
    curr_water--;
    curr_coffee -= SPOONS_PER_CUP;
    cout << "... made cup of coffee... " << name << endl;
  }
};


void test1(CoffeeMachine & cm) { 
  cout << endl << "TEST 1" << endl;
  cm.displayCM(); cm.makeCups(5); cm.displayCM();
}

void test2(CoffeeMachine & cm) {
  cout << endl << "TEST 2" << endl;
  cm.displayCM();
  cm.makeCups(14);
}
void test3(CoffeeMachine & cm) { 
  cout << endl << "TEST 3" << endl; 
  cm.displayCM(); 
  cm.makeCups(12); 
  cm.displayCM(); 
  cm.makeCups(5);
}


int main() {
  CoffeeMachine cm1;
  cm1.addWater(8);
  cm1.addCoffee(8);
  test1(cm1);
 
  CoffeeMachine cm2("DECAF");
  cm2.addWater(10);
  cm2.addCoffee(10);
  test2(cm2);

  CoffeeMachine cm3("DECAF" , 15, 20);
  cm3.addWater(14);
  cm3.addCoffee(20);
  test3(cm3);
}
