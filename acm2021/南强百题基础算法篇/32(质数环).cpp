#include <algorithm>
#include <cstring>
#include <iostream>
#define For(i,a,b) for (int i=a;i<=b;i++)
using namespace std;
bool p[100],used[100];//p储存is质数，默认初始化为false
int n, a[100], now;//a储存输入数组

void dfs(int deep) {//deep从2开始
	if (deep == n + 1 && p[a[1] + a[n]]) {
		//结束条件抵达搜索个数n，并且头尾元素和为质数,输出
		For(i, 1, n) {
			printf("%d", a[i]);
			if (i != n) printf(" ");
		}
		puts("");
		return;
	}
	//深度优先搜索
	//递归填数：判断第i个数填入是否合法。
	//若合法：填数，判断是否到达目标（填入20个数字），是则打印结果，否则递归进入下一层填写下一个数字。
	//若是不合法：选择下一种可能进行尝试。
	For(i, 2, n) {
		if (p[i + a[deep - 1]] && !used[i])
		{
			used[i] = true;//记录已遍历的数
			a[deep] = i;//更新a数组值
			dfs(deep + 1);
			used[i] = false;//回退时要将used清理成false（以便进行下一组深度递归）
		}
	}
}

int main() {
	//打表法判断是否是质数，范围<19+17=36
	p[2] = p[3] = p[5] = p[7] = p[11] = p[13] = p[17] = p[19] = p[23] = p[29] = p[31] = true;
	bool isf = false;//判断是否要输出空行
	while (~scanf("%d", &n)) {//-1的补码表示全是1，按位取反后全是0，即为假，其它输入情况下判断条件为非0
		a[1] = 1;
		if (isf) puts("");
		isf = true;
		printf("Case %d:\n", ++now);
		memset(used, false, sizeof(used));
		dfs(2);
	}
	return 0;
}

