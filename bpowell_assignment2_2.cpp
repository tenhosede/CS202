#include<iostream>

using namespace std;

const int DEF_CAP = 10;
int SPOONS_PER_CUP = 1; // has to be changeable in stage 2


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

protected:
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

/*
MilkCoffeMachine class: Creates a coffee machine that has a name, variable capacities, and tracks resources. 

constructors:
MilkCoffeMachine() constructor assigns a generic name and default capacities
MilkCoffeeMachine(string, int, int, int, bool) assigns the specified name, and respective water, coffee, and milk capacity. If bool == true, fills all resources to capacity

public functions:

void addWater(int cupsWater) adds cupsWater to curr_water, simulates adding water to machine

void addMilk(int spoonsMilk) adds spoonsMilk to curr_milk, simulates adding Milk to machine 

void displayCM() displays the name of the coffee machine and current values of curr_water and curr_coffee, showing available resources

 */

class MilkCoffeeMachine : public CoffeeMachine {
private:
  int milk_capacity;
  int curr_milk;
  void fillFull(){
    curr_milk = milk_capacity;
    addWater(water_capacity);
    addCoffee(coffee_capacity);
  }
public:
  void addMilk(int spoonsMilk){
    if (curr_milk + spoonsMilk <= milk_capacity)
      curr_milk += spoonsMilk;
    else
      curr_milk = milk_capacity;
  } 
  MilkCoffeeMachine() {
    curr_milk = 0;
    milk_capacity = DEF_CAP;
  }
  MilkCoffeeMachine(string name, int water_capacity, int coffee_capacity, int milk_capacity, bool ff) {
    this->name = name;
    this->water_capacity = water_capacity;
    this->coffee_capacity = coffee_capacity;
    this->milk_capacity = milk_capacity;
    if (ff) 
      fillFull();
    else {
      curr_water = 0;
      curr_coffee = 0;
      curr_milk = 0;
    }
  }
  void makeCups(int numCups) {
    int cupsMade = 0; // keeps track of cups made
    while (numCups > cupsMade) {
      if ((curr_water >= 1) && (SPOONS_PER_CUP <= curr_coffee) && (SPOONS_PER_CUP <= curr_milk)) { //if i have enough resources, make me a cuppa joe
	makeSingleCup();
	curr_milk -= SPOONS_PER_CUP;;
	cupsMade++;
      }
      else { // if not enough resources left, tell me how many i couldn't make
	cout << "Order could not be completed...   " << (numCups - cupsMade) << " not produced..." << endl << endl; 
	break;
      }    
    }
  }
  void displayCM() {
    cout << "Current state of CM: " << name << endl;
    cout << "WATER: " << curr_water << "/" << water_capacity << "  (CUPS)" << endl;
    cout << "COFFEE: " << curr_coffee << "/" << coffee_capacity << "  (SPOONS)" << endl;
    cout << "MILK: " << curr_milk << "/ " << milk_capacity << "  (SPOONS)" << endl << endl;
  }
};


void test1(MilkCoffeeMachine & cm) { 
  cout << endl << "TEST 1" << endl;
  cm.displayCM(); cm.makeCups(5); cm.displayCM();
}

void test2(MilkCoffeeMachine & cm) {
  cout << endl << "TEST 2" << endl;
  cm.displayCM();
  cm.makeCups(14);
}
void test3(MilkCoffeeMachine & cm) { 
  cout << endl << "TEST 3" << endl; 
  cm.displayCM(); 
  cm.makeCups(12); 
  cm.displayCM(); 
  cm.makeCups(5);
}


int main() {
  //Stage 2 code:
  MilkCoffeeMachine cm1;
  cm1.addWater(8);
  cm1.addCoffee(8);
  cm1.addMilk(8);

  test3(cm1);

  MilkCoffeeMachine cm2("Blend", 15, 30, 30, true);
  SPOONS_PER_CUP = 3;

  test3(cm2);

  // Stage 1 code:
  /*
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
  */
}
