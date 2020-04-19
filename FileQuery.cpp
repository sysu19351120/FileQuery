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
	string file;//file保存整个文件的内容,不包\n
	while (getline(is, text))
	{
		file = file + text;
		istringstream line(text);//将行文本分解为单词
		string word;
		string word1;
		int word_num = 0;
		while (line >> word)//对行中的每个单词
		{
			word1 = "";//清空word1；
			for (int i = 0; i < word.length(); i++)
			{
				
				if (word[i] < 65|| word[i]>122)//word1是一个单词
					continue;
				else
					word1 += word[i];
			}
			for (int i = 0; i < word1.size(); i++)//将包含大写字母的单词转为全部为小写
				if (64 < word1[i] && word1[i] < 91)
					word1[i] = word1[i] + 32;
			if (wm.find(word1)==wm.end())//当第一次遇到这个word时候
				wm[word1] = 1;
			else wm[word1] += 1;
			
		}
	}
	string sentence;//sentence保存每一个句子以。，为结尾
	for (int i = 0; i < file.length(); i++)
	{
		if (file[i] != '.' && file[i] != ',')
			sentence += file[i];
		else
		{
			sentence += file[i];
			sentences_.push_back(sentence);//将每一句插入到sentences中
			sentence = "";//到达结尾的时候清空sentence
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
		if (sentences_[i].find("str") != sentences_[i].npos)//当找得到str时则打印该句内容
			cout << sentences_[i] << endl;
}
void FileQuery::PrintWordCount()
{
	map<string, int>::iterator iter;//迭代器iter用来遍历map的内容
	for (iter = wm.begin(); iter != wm.end(); iter++)
		cout << iter->first << ":" << iter->second<<endl;//first为map的key，second为value
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