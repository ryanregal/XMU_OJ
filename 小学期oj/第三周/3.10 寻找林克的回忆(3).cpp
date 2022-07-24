#include<iostream>
#include<algorithm>
using namespace std;
 
// 打表
// ones记录二进制数1的个数
// LOG记录二进制数最低位1的位置
int ones[1 << 9], LOG[1 << 9];
int row[9], col[9], block[9][9], a[9][9], res = -1;
 
// 得到最低位1所对应的值
inline int lowbit(int x) {
    return x & -x;
}
 
// 求可以填的数
inline int get(int x, int y) {
    return row[x] & col[y] & block[x / 3][y / 3];
}
 
// 算数值
inline int get_score(int x, int y, int t) {
    return (min(min(x, 8 - x), min(y, 8 - y)) + 6) * t;
}
 
inline void draw(int x, int y, int t) {
    int s = 1;
    if(t > 0) a[x][y] = t;
    else {
        s = -1;
        t = -t;
        a[x][y] = 0;
    }
    t--;
    row[x] -= (1 << t) * s;
    col[y] -= (1 << t) * s;
    block[x / 3][y / 3] -= (1 << t) * s;
}
 
void dfs(int count, int score) {
    if(count == 0) {
        res = max(res, score); 
        return;
    }
    // 找出可试数最少的空格
    int minc = 10;
    int x, y;
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++) {
            if(a[i][j] == 0) {
                int temp = ones[get(i, j)];
                if(temp < minc) {
                    minc = temp;
                    x = i;
                    y = j;
                }
            }
        }
    // 从（x，y）处开始深搜
    for(int i = get(x, y); i; i -= lowbit(i)) {
        int temp = LOG[lowbit(i)] + 1;
        draw(x, y, temp);
        dfs(count - 1, score + get_score(x, y, temp));
        draw(x, y, -temp);
    }
}
 
int main(){
    //初始化ones、LOG
    for(int i = 0; i < 1 << 9; i++) {
        ones[i] = 0;
        for(int j = i; j > 0; j -= lowbit(j)) ones[i]++;
    }
    for(int i = 0; i < 9; i++) LOG[1 << i] = i;
    // 初始化row、col、block，1所在的位数表示该位数可用
    // 初始化结果为111111111
    for(int i = 0; i < 9; i++) row[i] = col[i] = (1 << 9) - 1;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++) block[i][j] = (1 << 9) - 1; 
    // 读入数据并计算空格个数
    int count = 0, score = 0;
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++) {
            int temp;
            cin >> temp;
            if(temp != 0) {
                score += get_score(i, j, temp);
                draw(i, j, temp);
            }
            else count++;
        }
    dfs(count, score);
    cout << res << endl;
    return 0;
}