/***********************************************************
• 朴素的模式匹配算法
************************************************************/
#include <iostream>
#include <string>
#include <cstring>

typedef unsigned int  INDEX;

using namespace std;

class Find_String
{
private:
	string S;
	int S_len;
	string T;
	int T_len;
public:
	Find_String(string s, string t);
	~Find_String();

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

INDEX Find_String::Index(int pos)
{
	int i = pos;	// 记录主串中当前位置下标
	int j = 0;

	while(i < S_len && j < T_len)
	{
		if (S[i] == T[j])
		{
			++i;
			++j;
		}
		else
		{
			i = i - j + 1;
			j = 0;
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

	pos = fs.Index(5);

	printf("index is:%d\n", pos);

	return 0;
}

