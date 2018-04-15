// 这个题目有一个特点，可以边读边处理，因此我们并不需要对整个字符串进行处理，只需要对每个字符进行处理即可

#include <stdio.h>

int main(int argc, char const *argv[])
{
	int c, q = 1;
	while((c = getchar()) != EOF){
		if (c == '"')
		{
			printf("%s", q ? "``" : "''");
			q = !q;
		}
		else
			printf("%c", c);
	}
	return 0;
}