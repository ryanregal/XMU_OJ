#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 16, M = N * N;

// 存放原矩阵
// 读入时每行后面会自动加一个 '\0'，所以每个串要开到 N + 1
char str[N][N + 1];
// 存放每一层的原始矩阵状态，方便恢复现场
char str2[M + 1][N][N + 1];
// ones 表示二进制数中几个1  map 表示二进制数中最后一个 1 的位置   
int ones[1 << N], map[1 << N];
// 存放每个点可以放置的数
int state[N][N];
// 存放每一层的每一个点可以放置数的状态，方便恢复现场
int state2[M + 1][N][N], state3[M + 1][N][N];

inline int lowbit(int x) {
    return x & -x;
}

// 改变格子填放后，行、列、4*4 宫格的状态
void draw(int x, int y, int c) {
    str[x][y] = c + 'A';
    
    for (int i = 0; i < N; i ++) {
        // 将 x 行对应的每一个空位的可选项中去除 c
        // ~(1 << c) 表示将 二进制数的倒数第 c 位变为1，其余位取反
        // state[x][i] & ~(1 << c) 只将倒数第 c 位变为 1，其余位不变
        state[x][i] &= ~(1 << c);
        state[i][y] &= ~(1 << c);
    }
    
    // 找到该矩阵中左上角点在整个矩阵中对应的坐标
    int sx = x / 4 * 4, sy = y / 4 * 4;
    
    for (int i = 0; i < 4; i ++) {
        for (int j = 0; j < 4; j ++) {
            state[sx + i][sy + j] &= ~(1 << c);
        }
    }
    
    // 将 (x, y) 的状态标记为以放置 c
    state[x][y] = 1 << c;
}

bool dfs(int cnt) {
    // 如果所有格子都填放完成，则直接返回即可
    if (!cnt) return true;
    
    // 保存原来的状态，方便回溯
    int kcnt = cnt;
    memcpy(str2[kcnt], str, sizeof str);
    memcpy(state2[kcnt], state, sizeof state);
    
    // 枚举所有空白格，若只能填一个数，则直接填
    // 若不能填，则直接返回
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            if (str[i][j] == '-') {
                // state[i][j] 表示该位置可以放置的数
                int s = state[i][j];
                // 若一个数都不能放
                if (!s) {
                    // 恢复现场
                    memcpy(str, str2[kcnt], sizeof str);
                    memcpy(state, state2[kcnt], sizeof state);
                    return false;
                }
                
                // 若改格只能放置一个数
                if (ones[s] == 1) {
                    draw(i, j, map[s]);
                    cnt --;
                }
            }
        }
    }
    
    // 枚举每一行，若某个字母不能填在任何一个空位，直接返回
    // 若某个空格只能填一个字母，则直接填
    for (int i = 0; i < N; i ++) {
        // sor  表示该行可填放的数字
        // sand 表示该行每个空位可以填放的字符
        int sor = 0, sand = (1 << N) - 1;
        // 表示该行已填放的数字
        int drawn = 0;
        for (int j = 0; j < N; j ++) {
            int s = state[i][j];
            sand &= ~(s & sor);
            sor |= s;
            // s & sor 表示该格子可以填放同时前面有格子也可以填的数
            // sand & ~(s & sor) 二进制数中 1 所在的位置，就是只可以填那个数
            
            
            if (str[i][j] != '-') drawn |= s;
        }
        
        // 若某个字母不能填放在该行的任意一个位置
        if (sor != (1 << N) - 1) {
            memcpy(str, str2[kcnt], sizeof str);
            memcpy(state, state2[kcnt], sizeof state);
            return false;
        }
        
        for (int j = sand; j; j -= lowbit(j)) {
            int t = lowbit(j);
            // 若改行没有填放过 t
            if (!(drawn & t)) {
                for (int k = 0; k < N; k ++) {
                    // 找出填放 t 的那个格子
                    if (state[i][k] & t) {
                        draw(i, k, map[t]);
                        cnt --;
                        break;
                    }
                }
            }
        }
    }
    
    // 枚举每一列，若某个字母不能填在任何一个空位，直接返回
    // 若某个空格只能填一个字母，则直接填
    for (int i = 0; i < N; i ++) {
        int sor = 0, sand = (1 << N) - 1;
        int drawn = 0;
        for (int j = 0; j < N; j ++) {
            int s = state[j][i];
            sand &= ~(s & sor);
            sor |= s;
            
            if (str[j][i] != '-') drawn |= s;
        }
        
        if (sor != (1 << N) - 1) {
            memcpy(str, str2[kcnt], sizeof str);
            memcpy(state, state2[kcnt], sizeof state);
            return false;
        }
        
        for (int j = sand; j; j -= lowbit(j)) {
            int t = lowbit(j);
            if (!(drawn & t)) {
                for (int k = 0; k < N; k ++) {
                    if (state[k][i] & t) {
                        draw(k, i, map[t]);
                        cnt --;
                        break;
                    }
                }
            }
        }
    }
    
    // 枚举每一个 4*4 宫格，若某个字母不能填在任何一个空位，直接返回
    // 若某个空格只能填一个字母，指直接填
    for (int i = 0; i < N; i ++) {
        int sor = 0, sand = (1 << N) - 1;
        int drawn = 0;
        for (int j = 0; j < N; j ++) {
            int sx = i / 4 * 4, sy = i % 4 * 4;
            // 找到该点在该矩阵中偏移量
            int dx = j / 4, dy = j % 4;
            int s = state[sx + dx][sy + dy];
            sand &= ~(s & sor);
            sor |= s;
            
            if (str[sx + dx][sy + dy] != '-') drawn |= s;
        }
        
        if (sor != (1 << N) - 1) {
            memcpy(str, str2[kcnt], sizeof str);
            memcpy(state, state2[kcnt], sizeof state);
            return false;
        }
        
        for (int j = sand; j; j -= lowbit(j)) {
            int t = lowbit(j);
            if (!(drawn & t)) {
                for (int k = 0; k < N; k ++) {
                    int sx = i / 4 * 4, sy = i % 4 * 4;
                    int dx = k / 4, dy = k % 4;
                    if (state[sx + dx][sy + dy] & t) {
                        draw(sx + dx, sy + dy, map[t]);
                        cnt --;
                        break;
                    }
                }
            }
        }
    }
    
    // 如果经过上面的步骤，已经填放完毕，则不用进行下面的步骤
    if (!cnt) return true;
    
    // 找可以填放数最少的空格
    // 记住填放数最少的空格的坐标，以及可以填放的数
    int x, y, s = 20;
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            if (str[i][j] == '-' && ones[state[i][j]] < s) {
                s = ones[state[i][j]];
                x = i, y = j;
            }
        }
    }
    
    memcpy(state3[kcnt], state, sizeof state);
    
    // 枚举每一个可以填放的数
    for (int i = state[x][y]; i; i -= lowbit(i)) {
        memcpy(state, state3[kcnt], sizeof state);
        draw(x, y, map[lowbit(i)]);
        if (dfs(cnt - 1)) return true;
    }
    
    // 恢复现场
    memcpy(state, state2[kcnt], sizeof state);
    memcpy(str, str2[kcnt], sizeof str);
    
    return false;
}

int main() {
    // 初始化 map 和 ones 数组
    for (int i = 0; i < N; i ++ ) map[1 << i] = i;
    for (int i = 0; i < 1 << N; i ++ )
    {
        for (int j = i; j; j -= lowbit(j))
            ones[i] ++ ;
    }
    
    // 当扫描到数据时，才继续读入后续数据
    while (~scanf("%s", *str))
    {
        for (int i = 1; i < N; i ++ ) cin >> str[i];
        
        // 初始化每个格子的状态，是能够放置任意字符
        for (int i = 0; i < N; i ++ )
            for (int j = 0; j < N; j ++ )
                state[i][j] = (1 << N) - 1;
        
        // 存放空白格子数
        int cnt = 0;
        
        // 将已经放置字符的格子对应的状态进行更新
        for (int i = 0; i < N; i ++ )
            for (int j = 0; j < N; j ++ )
                if (str[i][j] != '-')
                    draw(i, j, str[i][j] - 'A');
                else cnt ++ ;

        dfs(cnt);

        for (int i = 0; i < N; i ++ ) cout << str[i] << endl;
        cout << endl;
    }

    return 0;
}