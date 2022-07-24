//write by Andy
#include <bits/stdc++.h>
using namespace std;
int B,N,R;  //精力药水、N座塔，R条路
struct AirLine{
    int d,length,cost;
};
vector< vector<AirLine> > maps(110); //邻接表
void add_edge(int s,int d,int length,int cost)
{
    AirLine dTower;
    dTower.d = d;
    dTower.length = length;
    dTower.cost = cost;
    if(s!=d){
        maps[s].push_back(dTower);
    }
}
int minLen;
int totalLen;
int totalCost;
int visited[110];  //是否已经访问过
void dfs(int i,int step,int cost){   //第i座塔,step表示已经length的长度，cost当前消耗的药水
    if(cost>B || step>minLen)  //剪枝
        return;
    if(i==N){
        minLen = min(minLen,step);
        return;
    }
    for(int k=0;k<maps[i].size();k++){
        AirLine pTower = maps[i][k];
        if(!visited[pTower.d]){
            visited[pTower.d] = 1;
            dfs(pTower.d,step+pTower.length,cost+pTower.cost);
            visited[pTower.d] = 0;   //深度优先搜索注意还原pTower
        }
    }
}
int main() {
    cin>>B>>N>>R;
    for(int i=1;i<=R;i++){
        int s,d,l,c; cin>>s>>d>>l>>c;
        add_edge(s,d,l,c);
    }
    //初始化全局变量
    memset(visited,0,110);
    totalCost=0,totalLen=0,minLen= 1<<30 ;
    visited[1]=1;
    dfs(1,0,0);
    cout<<((minLen < (1<<30) )?minLen:-1)<<endl;
    return 0;
}

