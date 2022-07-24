#include<bits/stdc++.h>
using namespace std;
//Head 与 next 数组存储的是ver数组的下标，0表示指向空
//ver 数组存储的是每条边的终点
//使用数组实现邻接表，无向图
const int N = 1010;   //顶点数
const int M = 10100;  //边数
const int maxCapcity = 108;  //油箱容量
int oilPrice[N],expenses[N][maxCapcity];
int head[N],Next[2*M],ver[2*M],dist[2*M],tot=-1;
bool visited[N][maxCapcity];
void add(int x,int y,int z)
{
    ver[++tot] = y;    //这条边到达的点
    Next[tot] = head[x];  //链接
    head[x] = tot;    //标记x起点
    dist[tot] = z;  //权值
}
void printU(int u)
{
    //! 访问从u出发的所有边，当next[i]=0时遍历结束
    cout<<u<<":";
    for(int i=head[u];i;i=Next[i]){
        int v = ver[i];
        int d = dist[i];
        cout<<"("<<u<<","<<v<<","<<d<<")";
    }
}
//状态空间
struct node
{
    int city,fuel,money;
    node(int x,int y,int z):city(x),fuel(y),money(z){};
    friend bool operator<(node a,node b)
    {
        return a.money > b.money;
    }
};
priority_queue<node> q;
//是否需要买油
bool buyOneOil(int city,int fuel,int c)
{
    //如果油还在油箱限制内，且这次买油一定更好的话
    if(fuel+1<=c && !visited[city][fuel+1] &&
        (expenses[city][fuel+1]>expenses[city][fuel]+oilPrice[city]))
    return true;
    else return false;
}
//判断下一条路是否合法
bool isNextRoad(int fuel,int cityid,int d,int money)
{
    //剩余油大于路径花费油，下一个状态未被访问过、并且花费更便宜
    if(fuel>=d && !visited[cityid][fuel-d] && 
        expenses[cityid][fuel-d]>money)
        return true;
    else
        return false;
}
//全局遍历列表
int n,m;

//Dijkstra算法
int BFS(int currentCapcity,int start,int target)
{
    while (!q.empty())
    {
        q.pop();
    }
    memset(visited,false,sizeof(visited));
    memset(expenses,0x3f,sizeof(expenses));
    //从起点开始搜索
    expenses[start][0] = 0;
    q.push(node(start,0,0));   //起点，剩余油量，权值
    while(!q.empty())
    {
        node qHead = q.top();
        q.pop();
        int city = qHead.city;
        int fuel = qHead.fuel;
        int money = qHead.money;
        visited[city][fuel] = true;
        //到达终点
        if(city==target) return money; 
        if(buyOneOil(city,fuel,currentCapcity))
        {
            //加上一升油
            expenses[city][fuel+1] = expenses[city][fuel]+oilPrice[city];
            //购买一升油的状态
            q.push(node(city,fuel+1,expenses[city][fuel+1]));
        }
        for(int i=head[city];i;i=Next[i])   //遍历相邻城市
        {
            int nextCity = ver[i],d=dist[i];    //此路径耗油量为d
            if(isNextRoad(fuel,nextCity,d,money))  //判断
            {
                expenses[nextCity][fuel-d] = money;  //耗油费
                q.push(node(nextCity,fuel-d,money));
            }
        }
    }
     return -1;
}
int main()
{
    cin>>n>>m;
    //代表N个城市的单位油价，第i个数即为第i个城市的油价pi
    for(int i=0;i<n;i++)
        cin>>oilPrice[i];
    //每行包括三个整数u,v,d，表示城市u与城市v之间存在道路，且赛车从u到v需要消耗的油量为d
    for(int i=1;i<=m;i++)
    {
        int u,v,d;
        cin>>u>>v>>d;
        add(u,v,d);
        add(v,u,d);  //无向图
    }
    int questions;
    cin>>questions;
    while (questions--)
    {
        //油箱容量，起始城市，目标城市
        int c,s,e;
        cin>>c>>s>>e;
        int expenses = BFS(c,s,e);
        if(expenses==-1)
            printf("impossible\n");
        else
            printf("%d\n",expenses);
    }
    return 0;
}
