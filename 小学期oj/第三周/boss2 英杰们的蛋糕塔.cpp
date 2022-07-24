/*
 * @Author: ryanregal 1822327087@qq.com
 * @Date: 2022-07-04 09:18:54
 * @LastEditors: ryanregal 1822327087@qq.com
 * @LastEditTime: 2022-07-04 09:19:01
 * @FilePath: \xmuoj\第三周\boss2 英杰们的蛋糕塔.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <cmath>
using namespace std;
int V, N, res = 1000000;
int mins[21] = {0}, minv[21] = {0};
 
void cake(int pos, int r, int h, int v, int s) {
    //剪枝
    if(v > V || s >= res) return;
    if((V - v) * 2 / (r + 1) >= res - s) return;
    //判断是否最小情况都不能满足
    if(v + minv[N - pos] > V) return;
    if(s + mins[N - pos] > res) return;
    //完成N层
    if(pos == N) {
        if(v == V && s < res) res = s;
        return;
    }
    //深搜
    for(int i = r; i >= N - pos; i--) {
        if(i * i > V - v) continue; 
        if(pos == 0) {
            s = i * i;
            h = V / i / i;
        }
        for(int j = h; j >= N - pos; j--) {
            cake(pos + 1, i - 1, j - 1, v + i * i * j, s + 2 * i * j);
        }
    }
    return;
}
 
int main(){
	scanf("%d%d", &V, &N);
    //从最上层到第i层的最小体积和最小面积
    for(int i = 1; i <= N; i++) {
        mins[i] = mins[i - 1] + 2 * i * i;
        minv[i] = minv[i - 1] + i * i * i;
    }
    int temp = sqrt(V / N);
    cake(0, temp, V / N / N, 0, 0);
    if(res == 1000000) printf("0");
    else printf("%d", res);    
	return 0;
}