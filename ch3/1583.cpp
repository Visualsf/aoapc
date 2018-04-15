/*
1. 生成元从定义上来说，生成元比原来的数要小，只需要遍历所有比n小的数即可，不过这样时间复杂度较高。
2. 使用一个数组存储100000以内的所有生成元，直接查表得到结果。
*/
#include <stdio.h>
#include <string.h>
#define MAX 100005

int ans[MAX];

int main(int argc, char const *argv[])
{
	int T, n;

	memset(ans, 0, sizeof(ans));

	for (int i = 1; i < MAX; ++i)
	{
		int x = i, y = i;
		while(x != 0) {
			y += x % 10;
			x /= 10;
		}
		if(ans[y] == 0 || i < ans[y])
			ans[y] = i;
	}

	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		printf("%d\n", ans[n]);
	}
	return 0;
}