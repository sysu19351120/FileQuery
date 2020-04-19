#ifndef FILEQUERY
#define FILEQUERY
#include<iostream>
#include<vector>
#include<set>
#include<map>
class FileQuery
{
public:
	FileQuery(std::ifstream &fie);//读取文件，滤除回车换行符号，并提取句子（逗号或句号结尾），存储在sentences_中
	void PrintSentencesOrdered();// 按字典顺序，打印所有的句子，每行打印一个
	void PrintSentencesFiltered(const std::string& str);// 如果一个句子包含了str(如“epoch, the”) 里面的任一个单词，打印该句子
	void PrintWordCount() ;// 打印每个单词出现的次数(大小写不敏感)
	void ReplaceWord(const std::string& old1, const std::string& new1);// 将所有old单词换成new单词

private:
	std::vector<std::string> sentences_;//保存每一句话
	std::map<std::string,int>wm;//wm为一个字典，string对应单词，set对应单词所在行号的集合
};
#endif