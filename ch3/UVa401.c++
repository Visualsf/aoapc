/*1. 利用一个字符数组存储所有的镜像对应关系
  2. 利用简单数组存储输出结果（镜像必定不是回文，可以用二维数组存储结果）
*/

#include "stdio.h"
#include <ctype.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

string rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
string msg[] = {"not a palindrome", "a regular palindrome", "a mirrored string", "a mirrored palindrome"};

char reverse(char c) {
	if(isalpha(c))
		return rev[c - 'A'];
	else
		return rev[c - '0' + 25];
}

int main(int argc, char const *argv[])
{
	char s[30];
	while(scanf("%s", s) != EOF) {
		int len = strlen(s);
		int mid = (len + 1) / 2;
		int p = 1, m =1;

		for (int i = 0; i < mid; ++i)
		{
			if(s[i] != s[len - 1 - i])
				p = 0;
			if(reverse(s[i]) != s[len - 1 - i])
				m = 0;
		}

		cout << s << " -- is " << msg[m*2 +p] << "." <<endl << endl;
	}
	return 0;
}