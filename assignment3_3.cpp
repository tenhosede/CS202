#include<iostream>
#include<cstdlib>

using namespace std;

class DArr {
public:
  int *arr;
  int size;
  void displayElements() {
    cout << "Element Values: " << endl;
    for (int i=0;i<size;i++) {
      cout << *(arr+i);
      if (i < size -1)
	cout << ", ";
    }
    cout << endl;
  }
  int* getMax() {
    int index = 0;
    for (int i=0;i<size;i++){
      if (*(arr+i) > *(arr+index))
	index = i;
    }
    return arr+index;
  }

  DArr() {
    cout << "Please enter Array size: ";
    cin >> size;
    arr = new int[size];
    cout << "Constructor: allocating " << size * 4 << " bytes of memory" << endl;
    for (int i=0;i<size;i++){
      arr[i] = rand()%1000; 
    }
  }
  ~DArr() {
    cout << "Destructor: freeing " << size * 4 << " bytes of memory" << endl;
    delete [] arr;
  }

};


int main() {
  DArr d1;
  d1.displayElements();
  cout << "Max Element: " << *(d1.getMax()) << " at the address of " << d1.getMax() << endl;
}
