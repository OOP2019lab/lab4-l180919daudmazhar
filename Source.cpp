
#include "Header.h"
#include <fstream>
#include <string>
using namespace std;

CricketTeam::CricketTeam()  //sets default values for all the variables in class//
{
	CricketTeam::captain = 'NULL';
	CricketTeam::Rank = -1;
	CricketTeam::membernames = nullptr;
	CricketTeam::no_of_members = 11;
	for (int i = 0; i <10; i++) {
		CricketTeam::Scoreinlast10matches[i] = -1;
	}
	CricketTeam::teamName = nullptr;
}



CricketTeam::CricketTeam(string teamname, int no_of_members)
{
	int size = (strlen(teamname.c_str()));    //calculates size of the string//
	CricketTeam::teamName = new char[size]; //makes a dynamic array of the calculated length//
	strcpy_s(CricketTeam::teamName, size + 1, teamname.c_str()); //copies the teamname iinto the class variable teamName//
	CricketTeam::no_of_members = no_of_members;

}

CricketTeam::CricketTeam(string filename)
{

	ifstream read;
	read.open(filename);
	string s;
	getline(read, s, ':'); //stores the string s till it reads a colon//
	getline(read, s, '\n'); //reads the line beyond the colon and overwrites s//
	CricketTeam::teamName = new char[sizeof(s)]; //makes a dynamic array of the size of the s string//

	strcpy_s(CricketTeam::teamName, sizeof(s), s.c_str()); //copy function as used above//
	cout << CricketTeam::teamName;

	getline(read, s, ':'); //reads and stores in string s till colon//
	int count;
	read >> count;
	CricketTeam::no_of_members = count; // stores count in the class variable no_of_members//
	cout << endl << CricketTeam::no_of_members << endl;
	read.ignore();
	membernames = new string[no_of_members];
	for (int i = 0; i < no_of_members; i++)
	{
		getline(read, membernames[i]);
		cout << membernames[i] << endl;
	}
	getline(read, s, ':');
	read >> CricketTeam::Rank;
	cout <<  CricketTeam::Rank << endl;

	getline(read, s, ':');
	getline(read, s, '\n');
	CricketTeam::captain = s;
	cout << CricketTeam::captain << endl;

	getline(read, s, ':');
	for (int i = 0; i < 10; i++)
	{
		read >> CricketTeam::Scoreinlast10matches[i];
		read.ignore();
		cout << CricketTeam::Scoreinlast10matches[i]<<endl;
	}
}

void CricketTeam:: TeamMember(string mname)
{
	string *c = new string[CricketTeam::no_of_members];
	for (int i = 0; i < CricketTeam::no_of_members; i++)
	{
		c[i] = mname;
		cout << mname << endl;

	}
}

char CricketTeam::getTeamName()
{
	return *teamName;
}
void cricketTeam::setcaptain(string name)
{
	captain = name;

}
string CricketTeam::getcaptain()
{
	return captain;
}
void CricketTeam::setrank(int ranking)
{
	Rank = ranking;
}
int CricketTeam::getrank()
{
	return Rank;
}
void  CricketTeam::setno_of_members(int num)
{
	no_of_members = num;
}
int CricketTeam::getno_of_members()
{
	return CricketTeam::no_of_members;
}