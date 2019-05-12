/**************************************************************
• Robin-Krap（哈希检索）算法
• 即可以对模式串进行哈希运算并将其哈希值与文本中子串的哈希值进行比对。
*********************************************************** **/
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

typedef long int LInt;

class Find_String
{
private:
	const int M = 128;

	string S;
	int S_len;
	string T;
	int T_len;

public:
	Find_String(string s, string t);
	~Find_String();

	int charval(char);
	LInt hashval(string str, int len);
	int solve (LInt data);
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
// ASCII 转 十进制
int Find_String::charval(char c)
{
	return c;
}
// 计算固定长度字符串的hash值
LInt Find_String::hashval(string str, int len)
{
	LInt res = 0;
	for (int i = 0; i < len; ++i)
		res = res * M + charval(str[i]); 
	return res;
}

int Find_String::solve (LInt data)
{
	LInt hash_s;
	for (int i = 0; i <= S_len - T_len; ++i) 
	{
		if (i == 0)
			hash_s = hashval(S, T_len);
		else
			hash_s = (hash_s - charval(S[i-1]) * pow(M, T_len-1)) * M + charval(S[i+T_len-1]); // 利用之前计算的hash值

		if (hash_s == data)
			return i;
	}
	printf("Error!\n");
	return 0;
}

int main()
{
	string str1 = "I'm Iron Man!";
	string str2 = "Man";

	int pos;

	LInt Hash_T;

	Find_String fs(str1, str2);

	Hash_T = fs.hashval(str2, str2.size());

	pos = fs.solve(Hash_T);

	printf("Hash_T is:%ld\n", Hash_T);
	printf("index is:%d\n", pos);

	return 0;
}

