/***********************************************************
• KMP模式匹配算法
************************************************************/
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

typedef unsigned int  INDEX;

using namespace std;

class Find_String
{
private:
	string S;
	int S_len;
	string T;
	int T_len;

	vector<int> next;
public:
	Find_String(string s, string t);
	~Find_String();

	void get_next();
	void print_next();
	INDEX Index(int pos);
};

Find_String::Find_String(string s, string t)
{
	S = s;
	S_len = s.size();
	T = t;
	T_len = t.size();
}

Find_String::~Find_String()
{
	std::cout << "Bye,SaLangHeiYou" << endl;
}
//* get_next函数使用next【i】记录字串0-i字符的前缀与后缀最大的相同长度 */
void Find_String::get_next()
{
	int i, j;
	i = 1;
	j = 0;
	next.push_back(0);
	while(i < T_len)
	{
		if(T[j] == T[i])
		{
			++j;
			next.push_back(j);
			++i;
		}
		else
		{
			next.push_back(0);
			++i;
			j = 0;
		}
	}
}

void Find_String::print_next()
{
	for (unsigned int i = 0; i < next.size(); ++i)
		printf("%d\n", next[i]);
}

INDEX Find_String::Index(int pos)
{
	int i = pos;	// 记录主串中当前位置下标
	int j = 0;

	while(i < S_len && j < T_len)
	{
		if (j == 0 || S[i] == T[j])
		{
			++i;
			++j;
		}
		else
		{
			j = next[j - 1];
		}
		if (j >= T_len)
		{
			return i - T_len;
		}
	}
	printf("Nothing\n");
	return 0;
}

int main()
{
	string str1 = "I'm Iron Man!";
	string str2 = "Man";
	int pos;

	Find_String fs(str1, str2);

	fs.get_next();
	fs.print_next();
 	pos = fs.Index(5);

	printf("index is:%d\n", pos);

	return 0;
}

