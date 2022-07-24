//code by Andy
#include<bits/stdc++.h>
using namespace std;
const int N9 = 9; 
const int MaxN=1<<N9;  //! 1<<9为512
string str;  
int row[N9],col[N9],cell[3][3];
int ones[MaxN];  //int t=ones[n] 给定一个数n，计算出有t个1
int LOG2[MaxN];  //int t= LOG2[n] 给定一个数n，计算出最低位的1
//! 二进制准备---------------------------------------------
//打表法计算LOG2
void BuildLOG2(){
    for(int i=0;i<N9;i++) LOG2[1<<i] = i;
}
//取n二进制序列最后末一个1000模式的子串
inline int lowbit(int n){
    return n & -n; //!-n表示n取反+1
}
//计算传入的数有多少个是1
int NumberOf1(int n){
    int res = 0;
    while(n){
        n -=lowbit(n);
        res +=1;
    }
    return res;
}
//打表法构建ones数组，用于统计1最少的i就是需要搜索的位置
void Buildones(){
    for(int i=0;i<MaxN;i++) ones[i]=NumberOf1(i);
}
//! --------------------------------------------
//取交集的运算
inline int get(int x,int y){  //返回row[x],col[x]与cell[x][y]的可用集合
    return row[x] & col[y] & cell[x/3][y/3];  //返回同时为1的二进制位
    // 可以使用lowbit取出每一位，就知道哪一位可尝试了 111（7） & 011（3） = 011（3）
}
//把x,y位置二进制数的第n位取反
inline void flipbits(int x,int y,int n){
    row[x] ^= 1<< n;
    col[y] ^= 1<< n;
    cell[x/3][y/3] ^= 1<< n;
}
void init(){  //把全部数都清成1
    for(int i=0;i<N9;i++) row[i]=MaxN-1;  //初始化为111111111
    for(int i=0;i<N9;i++) col[i]=MaxN-1;  //初始化为111111111
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            cell[i][j] = MaxN-1;  //初始化为111111111
}
void printStr2line(string s){
    cout<<s<<endl;
}
//!========================================================================
bool dfs(int cellsLeft){
    if(cellsLeft==0){
        //输出可行解
        printStr2line(str);
        return true;
    }
    //找出可选方案数最小的格子
    int minv = 10;
    int x,y;
    for(int i=0;i<N9;i++)
        for(int j=0;j<N9;j++)
            if(str[i*9+j]=='.'){
                int t = ones[get(i,j)];  //计算出格子最少的行列
                if(t<minv){
                    minv = t; x = i; y = j; //记录为x,y
                }
            }
    //从该方案[x,y,minV]开始枚举，直到找到cellstosolve-1方案为止
    //? get(x,y)的返回值代表行，列，Cell中可选的二进制值
    for(int sk=get(x,y);sk;sk-=lowbit(sk)){
        int t=LOG2[lowbit(sk)];  //得到1的最低位位置
        //修改状态row,col,cell
        flipbits(x,y,t);
        str[x*9+y] = '1'+t;  //修改str对应位置上的数（0-8）映射到（1-9）
        dfs(cellsLeft-1);
        //恢复状态
        str[x*9+y]='.';
        flipbits(x,y,t);
    }
    return false;
}
//! ========================================================================
int main()
{
    BuildLOG2();
    Buildones();
    while(cin>>str,str[0]!='e'){
        init();
        //i,j是九宫格的行列坐标,k是字符串中的线性坐标
        int cellsLeft = 0;
        for(int i=0,k=0;i<N9;i++)
            for(int j=0;j<N9;j++,k++)
                if(str[k]!='.'){
                    int t=str[k]-'1';  //把1-9映射到 0-8
                    flipbits(i,j,t);  //初始化是1，这里取反设置为0，表示该位已经占用
                }
                else cellsLeft++;
        dfs(cellsLeft);   
    }
    return 0;
}

