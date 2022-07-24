#include<iostream>
#include<cstdio>
#include<algorithm>
#include<math.h>
#include<queue>
#include<cstring>
#include<string>
using namespace std;
typedef pair<int,int> pii;
const int maxn=1e5+5;
int dis[maxn];
int vis[maxn];
int head[maxn];
int cnt=0;
struct node
{
	int to,next,w;	
}e[maxn*4];
void add(int u,int v,int w) //链式前向星存图或者也可以理解为头插法的邻接表
{
	e[cnt].to=v;			
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt++;
}
priority_queue<pii,vector<pii>,greater<pii> >q;//堆优化
void dij(int x)	//x为起点
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));				//标记函数为了防止重复遍历
	dis[1]=0;
	q.push({0,x});
	while(!q.empty())
	{
		pii p=q.top();
		q.pop();
		int diss=p.first,id=p.second;
		if(vis[id])	continue;
		vis[id]=1;
		for(int i=head[id];i!=-1;i=e[i].next)
		{
			int j=e[i].to;
			if(!vis[j]&&dis[j]>diss+e[i].w)
			{
				dis[j]=diss+e[i].w;
				q.push({dis[j],j});
			}
		}
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	memset(head,-1,sizeof(head));	//这个一定要记得加,要不然会一直进行
	int a,b,c;
	while(m--)
	{
		cin>>a>>b>>c;
		add(a,b,c);
	}
	dij(1);
	if(dis[n]==0x3f3f3f3f)
		cout<<-1<<endl;
	else
		cout<<dis[n]<<endl;
}
