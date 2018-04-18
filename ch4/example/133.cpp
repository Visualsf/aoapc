/*这里还是用到了498的小技巧，离开队伍的人将数组该位置为0,数数时跳过即可*/
#include <stdio.h>
#define maxn 25
int n, k, m, a[maxn];

/*顺时针和逆时针计数可以写成2个函数，这里利用了一个小技巧：
	逆时针走t步，d>0表示逆时针，d<0表示顺时针*/
int go(int p, int d, int t) {
	//每一次都走到一个不为0的位置为止。
	while(t--){
		do{
			p = (p + d + n - 1) % n + 1; //1. 加环中元素数目（n-1）可以回到原位置；2、%n将元素对应到（0，n-1）；3、加1将元素移到（1，n）
		} while(a[p] == 0);
	}

	return p;
}

int main(int argc, char const *argv[])
{
	while(scanf("%d%d%d", &n, &k, &m) != EOF && n){
		for (int i = 1; i <= n; i++)
		{
			a[i] = i;
		}

		int left = n;
		int p1 = n, p2 = 1; //相当于从0开始，p1从1开始计数，因此0位置是p1 = n；p2同理。
		while(left) {
			p1 = go(p1, 1, k);
			p2 = go(p2, -1, m);
			printf("%3d", p1);
			left--;

			if(p1 != p2) {
				printf("%3d", p2);
				left--;
			}

			a[p1] = a[p2] = 0;   //每当有人被选中并且退出后，将该位置的值置为0.
			if(left)
				printf(",");
		}

		printf("\n");
	}
	return 0;
}