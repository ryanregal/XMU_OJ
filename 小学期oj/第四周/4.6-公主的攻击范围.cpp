#include<bits/stdc++.h>
using namespace std;
//定义方向向量
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
const int N=1010;
//战斗区域
char g[N][N];
//计算从1的点出发抵达每个0的最短距离
int d[N][N],n,m;
//pair类型变量保存x,y
typedef pair<int,int> PII;
queue<PII>q;  //BFS使用的队列

//读入数据
void Build(int n,int m){
    memset(d,-1,sizeof(d));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            char c = getchar();
            while (c!='0' && c!='1'){
                c = getchar();
            }
            if(c=='1'){
                d[i][j]=0;
                q.push(make_pair(i,j));  //压入队列，多源广搜
            }
        }
}
//输出
void Print(int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cout<<d[i][j]<<' ';
        cout<<endl;
    }
}

void bfs(){
    while(q.size()){  
        auto t=q.front();
        q.pop();

        int x=t.first,y=t.second;
        for(int i=0;i<4;i++){
            int a=x+dx[i],b=y+dy[i];
            if(a>=0 && a<n && b>=0&&  b<m && d[a][b]==-1){  //判断是否合法
                d[a][b]=d[x][y]+1;
                q.push({a,b});
            }
        }
    }
}

int main(void){
    cin>>n>>m;
    Build(n,m);
    bfs();
    Print(n,m);
    return 0;    
}
