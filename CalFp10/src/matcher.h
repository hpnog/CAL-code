#include <fstream>
#include <iostream>

using namespace std;

void computerPrefixFunction (string toSearch, int pi[]) {
	int m = toSearch.length();
	pi[0] = 0;
	int k = 0;

	for (int q = 1; q < m; q++)
	{
		while (k > 0 && toSearch[k] != toSearch[q])
			k = pi[k];
		if (toSearch[k] == toSearch[q])
			k++;
		pi[q] = k;

	}

	return;
}

int numStringMatching(string filename, string toSearch) {
	ifstream inputFile;
	inputFile.open(filename.c_str());

	int counter = 0;

	while (!inputFile.eof())
	{
		string input;
		getline(inputFile, input);

		int n = input.length();
		int m = toSearch.length();
		int pi[toSearch.length()];
		computerPrefixFunction(toSearch, pi);
		int q = 0;

		for (int i = 0; i < n; i++)
		{
			while (q > 0 && toSearch[q] != input[i])
				q = pi[q - 1];

			if (input[i] == toSearch[q])
				q++;

			if (q == m) {
				cout << "Pattern occurs with shift " << i - m + 1 << endl;
				q = pi[q - 1];
				counter++;
			}
		}
	}

	inputFile.close();
	return counter;
}
