#include<iostream>
#include"FileQuery.h"
#include"Shape.h"
#include<fstream>
#include<string>
using namespace std;
void TestTextQuery();
void TestShape();
int main()
{

	TestTextQuery();
	TestShape();
	return 0;
}
void TestTextQuery()
{
	cout << "test the textquery:" << endl;
	string filename = "TwoCities.txt";
	ifstream file1(filename);
	FileQuery f1(file1);
	f1.PrintSentencesOrdered();
	f1.PrintSentencesFiltered("the");
	f1.PrintWordCount();
	f1.ReplaceWord("the", "a");
	f1.PrintSentencesOrdered();
}
void TestShape()
{
	cout << "test the textshape:" << endl;
	Square s1(1.5);
	Circle s2(3.5);
	cout <<"the area of s1 is:"<< s1.GetArea() << endl;
	cout << "the area of s2 is:" << s2.GetArea() << endl;
}