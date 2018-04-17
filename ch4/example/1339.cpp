/*这题因为字母可以重排，所以每个字母的位置并不重要，我们只需要统计每个字母出现的次数，然后再进行一次排序即可*/
#include "stdio.h"
#include <string.h>
#include <stdlib.h>

int cmp(const void * a, const void * b) {
	return *(int*)a - *(int*)b;
}

int main(int argc, char const *argv[])
{
	char s1[200],s2[200];
	while(scanf("%s %s", s1, s2) != EOF) {
		int cnt1[26] = {0};
		int cnt2[26] = {0};
		int len = strlen(s1);
		for (int i = 0; i < len; ++i)
		{
			int tmp = s1[i] - 'A';
			cnt1[tmp]++;
			tmp = s2[i] - 'A';
			cnt2[tmp]++;
		}
		qsort(cnt1, 26, sizeof(int), cmp);
		qsort(cnt2, 26, sizeof(int), cmp);

		int ok = 1;
		for (int i = 0; i < 26; ++i)
		{
			if(cnt1[i] != cnt2[i])
				ok = 0;
		}

		if(ok)
			printf("YES\n");
		else
			printf("NO\n");

	}
	return 0;
}