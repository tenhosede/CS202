#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <iomanip>

using namespace std;

const int CAND_NBR = 6;

struct Candidate {
 string first;
 string last;
 int votes;
 double pScore;
};

void readFile(Candidate[]);
void displayList(Candidate[]);
void sortByVotes(Candidate[]);
void displayCandidate(Candidate);
Candidate getWinner(Candidate[]);
Candidate getLast(Candidate[]);
void calculateScores(Candidate[]);


int main() {
	
  Candidate candidates[CAND_NBR];
  readFile(candidates);
  displayList(candidates);
  calculateScores(candidates);
  displayList(candidates);
  sortByVotes(candidates);
  displayList(candidates);
  cout << "Winner: " << endl;
  displayCandidate(getWinner(candidates));
  cout << "Lowest score: " << endl;
  displayCandidate(getLast(candidates));
}



void readFile(Candidate candidates[]) {
 string line;
 ifstream infile;
 int candidate_index=0;
 infile.open("elections.txt");
 string voteString; 

 while (!infile.eof()) {
 getline(infile,line);

 candidates[candidate_index].first = line.substr(2, line.find(',') -2);
 candidates[candidate_index].last = line.substr(line.find("L=") + 2,(line.find(',',line.find(',')+1)-line.find("L=")-2));
 voteString = line.substr((line.find("V=")+ 2),line.find('\n')); 
 candidates[candidate_index].votes = atoi(voteString.c_str());
 candidates[candidate_index].pScore = 0.0;
 candidate_index++;
 }
 infile.close();
}
void displayList(Candidate candidates[]) {
  const int colWidth = 15;
  cout << fixed << setprecision(2);
  cout << "  ALL CANDIDATES:" << endl;
  cout << right << setw(colWidth) <<"First:" << setw(colWidth) << "Last:" << setw(colWidth) << "Votes:" << setw(colWidth) << "% Score:" << endl;
  for (int i=0;i<CAND_NBR;i++) {
    if (candidates[i].first == "")
      break;
    cout << setw(colWidth) << candidates[i].first << setw(colWidth) << candidates[i].last << setw(colWidth) << candidates[i].votes << setw(colWidth) << candidates[i].pScore << endl;
  }
  cout << endl;
}
void sortByVotes(Candidate candidates[]) {
  Candidate temp;
  bool sortdone = false;
  bool sorted = false;
  
  while (!sortdone)
    {
      for(int i = 0; i < CAND_NBR - 1; i++)
	{
	  if (candidates[i].votes > candidates[i+1].votes)
	    {
	      temp = candidates[i];
		candidates[i] = candidates[i+1];
		candidates[i+1] = temp;
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
 void displayCandidate(Candidate cand) {
   cout << left << "FIRST: " << cand.first << endl;
   cout << "LAST: " << cand.last << endl;
   cout << "VOTES: " << cand.votes << endl;
   cout << "% GAINED: " << cand.pScore << endl << endl;
}
Candidate getWinner(Candidate candidates[]) {
  int winner = 0;
  for (int i=1;i<(CAND_NBR);i++){
    if (candidates[i].pScore > candidates[winner].pScore)
      winner = i;
  }
  return candidates[winner];
}
Candidate getLast(Candidate candidates[]) {
  int loser = 0;
  for (int i=1;i<(CAND_NBR);i++){
    if (candidates[i].pScore < candidates[loser].pScore)
      loser = i;
  }
  return candidates[loser];

}
void calculateScores(Candidate candidates[]) {
  double totalVotes = 0;
  for (int i=0;i<CAND_NBR;i++)
    totalVotes += static_cast<double>(candidates[i].votes);
  for (int i=0;i<CAND_NBR;i++)
    candidates[i].pScore = (candidates[i].votes/totalVotes)*100;


}
