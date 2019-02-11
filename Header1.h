#include <iostream>
#include <string>
using namespace std;


class CricketTeam{
public:	
string * membernames;
int no_of_members;
char *teamName;
int Scoreinlast10matches[10];
int Rank;
string captain;


public:
CricketTeam();
CricketTeam(string teamname, int no_of_members);
CricketTeam(string filename);
void TeamMember(string name);
void Score(int score);
float AvgScore(int Scoreinlast10matches[10]);
void PrintLastScore (int last_score);
void PrintTeamInfo ();

};