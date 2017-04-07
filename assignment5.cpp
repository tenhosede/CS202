#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int ARR_SIZE=1000000;
const int ID_MIN=10000;
const int ID_MAX=99999;

class Student {
public:
  int id;
  string name;
};

void display(Student students[], int length) {
  for (int i=0;i<length;i++)
    cout << "ID#" << i << " " << students[i].id << ", ";
  cout << "\b\b" << endl;

}

void sortBubble(Student students[], int numvalues)
//sorts using a bubblesort algorithm
{
  Student temp;
    bool sortdone = false;
    bool sorted = false;
    
    while (!sortdone)
      {
	for(int i = 0; i < numvalues - 1; i++)
	  {
	    if (students[i].id > students[i+1].id)
	      {  
		temp = students[i];
		students[i] = students[i+1];
		students[i+1] = temp;
		sorted = true;	    
	      }
	    
	  }
	if (sorted)
	  sortdone = false;
	else 
	  sortdone = true;
      
	sorted = false;
      }
}

int compare(const void *a, const void *b) {
  return ((*(Student*)a).id - (*(Student*)b).id);
}
int random(int max, int min){
  return ((rand() % (max-min))+min);
}


int main() {
  char selection;
  Student *students;
  students = new Student[ARR_SIZE];
  //  clock_t startTime;
  time_t startTimer;
  time_t stopTimer;
  int seconds;
  int hours;
  int min;
  int sec;


  srand(time(NULL));

  
  for (int i=0;i<ARR_SIZE;i++)
    students[i].id = random(ID_MAX, ID_MIN);

  do{
  cout << "Enter 1 for quicksort or 2 for bubble sort:";
  cin >> selection;
  } while (selection != '1' && selection != '2');

  if (selection == '1') {
    cout << "Started quicksort!" << endl;
    time(&startTimer); 
    //    startTime = clock();
    qsort (students, ARR_SIZE, sizeof(Student), compare);
    //    startTime = clock() - startTime;
    time(&stopTimer);
  }
  else if (selection == '2') {
    cout << "Started bubblesort!" << endl;
    //    startTime = clock();
    time(&startTimer); 
    sortBubble(students, ARR_SIZE);
    //    startTime = clock() - startTime;
    time(&stopTimer);
  }

  seconds = difftime(stopTimer,startTimer);


  hours = seconds/3600;
  seconds = seconds%3600;
  min = seconds/60;
  seconds = seconds%60;
  sec = seconds;

  //  cout << "seconds: " << seconds << endl;
  cout << "Finished!" << endl;
  cout << "This algorithm took " << hours << "h " << min << "m "<< sec << "s" << endl;
  delete [] students;
}

