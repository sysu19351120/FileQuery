#ifndef FILEQUERY
#define FILEQUERY
#include<iostream>
#include<vector>
#include<set>
#include<map>
class FileQuery
{
public:
	FileQuery(std::ifstream &fie);//��ȡ�ļ����˳��س����з��ţ�����ȡ���ӣ����Ż��Ž�β�����洢��sentences_��
	void PrintSentencesOrdered();// ���ֵ�˳�򣬴�ӡ���еľ��ӣ�ÿ�д�ӡһ��
	void PrintSentencesFiltered(const std::string& str);// ���һ�����Ӱ�����str(�硰epoch, the��) �������һ�����ʣ���ӡ�þ���
	void PrintWordCount() ;// ��ӡÿ�����ʳ��ֵĴ���(��Сд������)
	void ReplaceWord(const std::string& old1, const std::string& new1);// ������old���ʻ���new����

private:
	std::vector<std::string> sentences_;//����ÿһ�仰
	std::map<std::string,int>wm;//wmΪһ���ֵ䣬string��Ӧ���ʣ�set��Ӧ���������кŵļ���
};
#endif