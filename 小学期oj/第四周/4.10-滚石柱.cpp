#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int N = 510; 
struct state{
	int x, y; //坐标 
	int lie; // 状态 
};
char s[N][N];
state st, ed;
int n, m;
int dis[N][N][3]; //记录最小步数 
queue<state> q;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
bool valid(int x, int y){
	return x >= 0 && y >= 0 && x < n && y < m;
}
bool valid(state next){
	if(!valid(next.x, next.y)) return false;
	if(s[next.x][next.y] == '#') return false;
	if(next.lie == 0 && s[next.x][next.y] != '.') return false;
	if(next.lie == 1 && s[next.x][next.y + 1] == '#') return false;
	if(next.lie == 2 && s[next.x + 1][next.y] == '#') return false;
	return true;
}
void get_se(){
	for (int i = 0; i < n ; i++){
		for(int j = 0; j < m; j++){
			if(s[i][j] == 'O'){
				ed.x = i;
				ed.y = j;
				ed.lie = 0;
				s[i][j] = '.';
			}
			else if(s[i][j] == 'X'){
				for(int k = 0; k < 4; k++){
					int x = i + dx[k];
					int y = j + dy[k];
					if(valid(x, y) && s[x][y] == 'X'){
						st.x = min(i, x);
						st.y = min(j, y);
						st.lie = k < 2 ? 1 :2;
						s[i][j] = s[x][y] = '.';
						break;
					}
				}
				if(s[i][j] == 'X'){
					st.x = i;
					st.y = j;
					st.lie = 0;
				}
			}
		}
	}
}
int next_x[3][4] = {{0, 0, -2, 1}, {0, 0, -1, 1}, {0, 0, -1, 2}};
int next_y[3][4] = {{-2, 1, 0, 0}, {-1, 2, 0, 0}, {-1, 1, 0, 0}};
int next_lie[3][4] = {{1, 1, 2, 2}, {0, 0, 1, 1}, {2, 2, 0, 0}};
int bfs(){
	memset(dis, -1, sizeof dis);
	while(q.size()) q.pop();
	dis[st.x][st.y][st.lie] = 0;
	q.push(st);
	while(q.size()){
		state now = q.front();
		q.pop();
		for(int i = 0; i < 4; i++){
			state next;
			next.x = now.x + next_x[now.lie][i];
			next.y = now.y + next_y[now.lie][i];
			next.lie = next_lie[now.lie][i];
			if(!valid(next)) continue;
			if(dis[next.x][next.y][next.lie] == -1){
				dis[next.x][next.y][next.lie] = dis[now.x][now.y][now.lie] + 1;
				q.push(next);
				if(next.x == ed.x && next.y == ed.y && next.lie == ed.lie)
					return dis[next.x][next.y][next.lie];
			}
		}
	}
	return -1;
}

int main(){
	while(~scanf("%d%d", &n, &m) && n){
		for(int i = 0; i < n; i++)
		scanf("%s", s[i]); 
		get_se();
		int ans = bfs();
		if(ans == -1)
			cout << "Impossible" << endl;
		else cout << ans << endl;
	}	
	return 0;
}
