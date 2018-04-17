// 同UVa272一样可以通过getchar读取每一个字符，通过常量素组存储整个键盘字符串

#include <stdio.h>

int main(int argc, char const *argv[])
{
	char s[] = "`1234567890-=QWERTYUIOP[]ASDFGHJKL;'ZXCVBNM,./";
	int i, c;
	while((c = getchar()) != EOF) {
		for( i = 1; s[i] && s[i] != c ; i++);
		if(s[i])
			putchar(s[i-1]);
		else
			putchar(c);
	}
	return 0;
}