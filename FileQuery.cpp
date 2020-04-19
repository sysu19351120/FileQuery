#include"FileQuery.h"
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<set>
using namespace std;
FileQuery::FileQuery(std::ifstream& is)
{
	string text;
	string file;//file���������ļ�������,����\n
	while (getline(is, text))
	{
		file = file + text;
		istringstream line(text);//�����ı��ֽ�Ϊ����
		string word;
		string word1;
		int word_num = 0;
		while (line >> word)//�����е�ÿ������
		{
			word1 = "";//���word1��
			for (int i = 0; i < word.length(); i++)
			{
				
				if (word[i] < 65|| word[i]>122)//word1��һ������
					continue;
				else
					word1 += word[i];
			}
			for (int i = 0; i < word1.size(); i++)//��������д��ĸ�ĵ���תΪȫ��ΪСд
				if (64 < word1[i] && word1[i] < 91)
					word1[i] = word1[i] + 32;
			if (wm.find(word1)==wm.end())//����һ���������wordʱ��
				wm[word1] = 1;
			else wm[word1] += 1;
			
		}
	}
	string sentence;//sentence����ÿһ�������ԡ���Ϊ��β
	for (int i = 0; i < file.length(); i++)
	{
		if (file[i] != '.' && file[i] != ',')
			sentence += file[i];
		else
		{
			sentence += file[i];
			sentences_.push_back(sentence);//��ÿһ����뵽sentences��
			sentence = "";//�����β��ʱ�����sentence
		}
	}
}
void FileQuery::PrintSentencesOrdered()
{
	for (int k = 0; k < sentences_.size(); k++)
		cout << sentences_[k] << endl;
}
void FileQuery::PrintSentencesFiltered(const std::string& str)
{
	for (int i = 0; i < sentences_.size(); i++)
		if (sentences_[i].find("str") != sentences_[i].npos)//���ҵõ�strʱ���ӡ�þ�����
			cout << sentences_[i] << endl;
}
void FileQuery::PrintWordCount()
{
	map<string, int>::iterator iter;//������iter��������map������
	for (iter = wm.begin(); iter != wm.end(); iter++)
		cout << iter->first << ":" << iter->second<<endl;//firstΪmap��key��secondΪvalue
}
void FileQuery::ReplaceWord(const std::string& old1, const std::string& new1)
{

	for (int i = 0; i < sentences_.size(); i++)
	{
		int start;
		int end ;
		start = sentences_[i].find(old1);
		while (start!=sentences_[i].npos)
		{
			
			sentences_[i].replace(start, old1.size(), new1);
			end = start + new1.size()-1;
			start = sentences_[i].find(old1, end);
		}

	}
}