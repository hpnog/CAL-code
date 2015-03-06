#include "Defs.h"
#include "Factorial.h"
#include "Change.h"
#include "Sum.h"
#include "Partitioning.h"

void factorialSimpleTest()
{
        ASSERT_EQUAL(120,factorialRecurs(5));
        ASSERT_EQUAL(3628800,factorialRecurs(10));
//        ASSERT_EQUAL(120,factorialDinam(5));
//        ASSERT_EQUAL(3628800,factorialDinam(10));
}

void factorialArrayTest()
{
//	int valueArray[8] = {1,1,2,6,24,120,720,5040};
//	int* valueResults = factorialDinamArray(7);
//
//	for(int i = 0; i < 8; i++)
//		ASSERT_EQUAL(valueArray[i],valueResults[i]);
}

void changeArrayTest()
{
  ASSERT_EQUAL("1;2;1,2;2,2;5;",calcChange(5));
	ASSERT_EQUAL("1;2;1,2;2,2;5;1,5;2,5;1,2,5;2,2,5;5,5;1,5,5;2,5,5;1,2,5,5;2,2,5,5;5,5,5;1,5,5,5;",calcChange(16));
}


void calcSumArrayTest()
{
//	int sequence[5] = {4,7,2,8,1};
//	int sequence2[9] = {6,1,10,3,2,6,7,2,4};
//
//	ASSERT_EQUAL("1,4;9,1;11,2;18,1;22,0;",calcSum(sequence, 5));
//	ASSERT_EQUAL("1,1;5,3;11,3;16,1;20,3;24,3;31,1;35,1;41,0;",calcSum(sequence2, 9));
}

void partitioningTest()
{
//	ASSERT_EQUAL(3025,s_recursive(9,3));
//	ASSERT_EQUAL(22827,s_recursive(10,6));
//	ASSERT_EQUAL(3025,s_dynamic(9,3));
//	ASSERT_EQUAL(22827,s_dynamic(10,6));
//	ASSERT_EQUAL(22827,s_dynamic(10,6));
//	ASSERT_EQUAL(5,b_recursive(3));
//	ASSERT_EQUAL(1382958545,b_recursive(15));
//	ASSERT_EQUAL(5,b_dynamic(3));
//	ASSERT_EQUAL(203,b_dynamic(6));
//	ASSERT_EQUAL(1382958545,b_dynamic(15));
}


void runSuite(){
        cute::suite s;
        //TODO add your test here
        s.push_back(CUTE(factorialSimpleTest));
        s.push_back(CUTE(factorialArrayTest));
        s.push_back(CUTE(changeArrayTest));
        s.push_back(CUTE(calcSumArrayTest));
        s.push_back(CUTE(partitioningTest));
        ide_listener <> lis;
        makeRunner(lis)(s, "The Suite");
}

int main(){
    runSuite();
    return 0;
}



