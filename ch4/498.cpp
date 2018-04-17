/*
这里是训练分函数写功能的能力
*/

#include <stdio.h>
#include <string.h>
#define MAX 100

int left, chance; //left：需要匹配的字母数目；chance：剩余的匹配机会
char s1[MAX], s2[MAX];
int win, lose;

/*保存已经猜过的字母可以通过一个数组来保存，这里面采取的是一个更加有意思的办法
	将匹配过的字符置为空格*/

int guess(char ch) {
	int bad = 1; //判断是否匹配上

	for (int i = 0; i < strlen(s1); ++i)
	{
		if(ch == s1[i]) {
			bad = 0;
			s1[i] = ' ';
			left--;
		}
	}

	/*先判断是否匹配错误，未匹配上机会减一
		再判断机会是否为0，为0则lose
		再判断是否还有剩余需要匹配字段，若有则win*/
	if(bad)
		chance--;
	if(!chance)
		lose = 1;
	if(!left)
		win = 1;
}

int main(int argc, char const *argv[])
{
	int n;
	while(scanf("%d %s %s", &n, s1, s2) != EOF && n != -1) {
		printf("Round %d\n", n);

		win = lose = 0;
		left = strlen(s1);
		chance = 7;

		for (int i = 0; i < strlen(s2); ++i)
		{
			guess(s2[i]);
			if(win || lose) break;
		}

		if(win)
			printf("You win.\n");
		else if(lose)
			printf("You lose.\n");
		else
			printf("You chickened out.\n");
	}


	return 0;
}