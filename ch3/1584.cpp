#include <stdio.h>
#include <string.h>
#define MAX 105

int less(char* s, int p, int q) {
	int n = strlen(s);

	for (int i = 0; i < n; ++i)
	{
		if(s[(p+i)%n] != s[(q+i)%n])
			return s[(p+i)%n] < s[(q+i)%n];
	}

	return 0;
}

int main(int argc, char const *argv[])
{
	int n;
	char s[MAX];

	scanf("%d", &n);
	while(n--) {
		scanf("%s", s);
		int ans = 0;
		int len = strlen(s);
		for (int i = 1; i < len; ++i)
		{
			if(less(s, i, ans))
				ans = i;
		}

		for(int i = 0; i < len; i++) {
			putchar(s[(ans + i) % len]);
		}
		putchar('\n');
	}
	return 0;
}