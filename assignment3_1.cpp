#include<iostream>

using namespace std;



int main() {
  int asize = 0;
  int *p_min;
  int *p_max;
  int *p;

  cout << "Please enter the size of the array: " << endl;
  cin >> asize;
  p = new int[asize];

  p_max = p;
  p_min = p; 

  for (int i=0;i<asize;i++) {
    cout << "Iteration number: " << i << endl;
    cout << "Please enter the value for entry " << i << ": ";
    cin >> *(p + i);
    if (*(p + i) > *p_max) {
      p_max = (p+i);
      cout << "Updating p_max to address " << p_max << ", now pointing to value: " << *p_max << endl;
    }
    if (*(p + i) < *p_min) {
      p_min = p+i;
      cout << "Updating p_min to address " << p_min << ", now pointing to value: " << *p_min << endl;
    }
    cout << "Read number: " << *(p+i) << endl;
    cout << "Current array elements: ";
    for (int j=0;j<i+1;j++){
      cout << *(p+j);
      if (j < i)
	cout << ",";
    }
    cout << endl;
    cout << "Current minimum = " << *p_min << " at address " << p_min << endl;
    cout << "Current maximum = " << *p_max << " at address " << p_max << endl << endl;
  }

  delete [] p;
}

