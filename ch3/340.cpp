/*1. 统计A直接对比两个数组对应位置即可
2. 统计B可以先统计对于同一个数字而言，在两个数组中出现的次数，出现次数较小者B减去A即为题目中所求的B
*/
#include <stdio.h>
#define MAX 1000

int main(int argc, char const *argv[])
{
	int n, a[MAX], b[MAX];
	int kase = 0;

	while(scanf("%d", &n) != EOF && n) {
		printf("Game %d:\n", ++kase);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
		}

		for(;;) {
			int A = 0, B = 0;
			
			for (int i = 0; i < n; ++i)
			{
				scanf("%d", &b[i]);
				if(a[i] == b[i]) A++;
			}

			if(b[0] == 0) break;

			for (int i = 1; i < 10; ++i)
			{
				int c1 = 0, c2 = 0;
				for (int j = 0; j < n; ++j)
				{
					if(a[j] == i) c1++;
					if(b[j] == i) c2++;
				}

				if(c1 < c2)
					B += c1;
				else
					B += c2;
			}

			printf("    (%d,%d)\n", A, B - A);
		}
	}
	return 0;
}