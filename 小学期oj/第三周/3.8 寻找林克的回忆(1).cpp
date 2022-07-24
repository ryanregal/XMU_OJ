#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;

const int N=9;
int g[N][N];
bool st_row[N][N+1],st_col[N][N+1],st_block[3][3][N+1];

bool dfs(int x,int y){
    if(y==9) x++,y=0;
    if(x==9){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++) cout<<g[i][j];
            cout<<endl;
        }
        return true;
    }

    if(g[x][y]!=0) return dfs(x,y+1);
    for(int t=1;t<=9;t++){
        if(!st_row[x][t] && !st_col[y][t] && !st_block[x/3][y/3][t]){
            st_row[x][t] =st_col[y][t] =st_block[x/3][y/3][t]=true;
            g[x][y]=t;
            if(dfs(x,y+1)) return true;
            g[x][y]=0;
            st_row[x][t]=st_col[y][t]=st_block[x/3][y/3][t]=false;
        }
    }
    return false;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL),std::cout.tie(NULL);
    memset(st_row,0,sizeof(st_row));
    memset(st_col,0,sizeof(st_col));
    memset(st_block,0,sizeof(st_block));   

    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++){
            char ch;
            cin>>ch;
            int t=ch-'0';
            g[i][j]=t;
            if(t!=0){
                st_row[i][t]=st_col[j][t]=st_block[i/3][j/3][t]=true;
            }
        }
    
    dfs(0,0);
    return 0;
}
