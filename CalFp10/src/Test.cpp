#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include "matcher.h"

using namespace std;

//float numApproximateStringMatching(string filename, string toSearch);


void test_stringMatching() {

	string toSearch="estrutura de dados";

	string filename1="text1.txt";
	int num1=numStringMatching(filename1,toSearch);

	ASSERT_EQUAL(3,num1);

	string filename2="text2.txt";
	int num2=numStringMatching(filename2,toSearch);

	ASSERT_EQUAL(2,num2);

}


void test_approximateStringMatching() {

	/*string toSearch="estrutur";

	string filename1="text1.txt";
	float dist1=numApproximateStringMatching(filename1,toSearch);

	ASSERT_EQUAL_DELTA(7.76,dist1,0.01);

	string filename2="text2.txt";
	float dist2=numApproximateStringMatching(filename2,toSearch);

	ASSERT_EQUAL_DELTA(7.49,dist2,0.01);*/

}




void runSuite(){
	cute::suite s;
	s.push_back(CUTE(test_stringMatching));
	s.push_back(CUTE(test_approximateStringMatching));

	cute::ide_listener <> lis;
	cute::makeRunner(lis)(s, "CAL 2012/2013 - Aula Pratica 11");
}

int main(){
    runSuite();
    return 0;
}



