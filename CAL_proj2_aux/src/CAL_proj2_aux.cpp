#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
	ofstream myOutFile;

	string fileName = "";
	int minNum;
	int maxNum;
	int numberOfFriendships;

	cout << endl << "What is the number of friendships you wish to create?\n";
	cin >> numberOfFriendships;
	cout << endl << "What is the minimum value?\n";
	cin >> minNum;
	cout << endl << "What is the maximum value?\n";
	cin >> maxNum;
	cout << endl << "What is the name of the file?\n";
	cin >> fileName;

	myOutFile.open(fileName.c_str());
	if (myOutFile.is_open())
	{
		for (int i = 0; i < numberOfFriendships; i++)
		{
			int randomNum = rand() % maxNum + minNum;
			int randomNum2 = rand() % (maxNum - randomNum) + randomNum + 1;
			myOutFile << randomNum << endl << randomNum2;
			if (i != numberOfFriendships - 1)
				myOutFile << endl;
		}
	}
	myOutFile.close();
	return 0;
}
