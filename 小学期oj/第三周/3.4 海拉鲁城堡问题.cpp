/*
 * @Author: ryanregal 1822327087@qq.com
 * @Date: 2022-07-04 09:17:04
 * @LastEditors: ryanregal 1822327087@qq.com
 * @LastEditTime: 2022-07-04 09:17:26
 * @FilePath: \xmuoj\第三周\3.4 海拉鲁城堡问题.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
//x是行， y是列 
 
#include<iostream>
using namespace std;
 
const int N = 55;
int m, n, cntroom, roomarea, maxarea;
int room[N][N];
bool st[N][N];
 
void dfs(int x, int y){
 
	st[x][y] = true;
	++ roomarea;
//	cout << x * n + y << endl;
//	cout << roomarea << endl;
	int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
	for(int i = 0; i < 4; ++ i){
		int nx = dx[i] + x, ny = dy[i] + y;
		//cout << 'a' << endl;
		//cout << nx << ' ' << ny << endl;
		if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
		//cout << 'b' << endl;
		if(st[nx][ny]) continue;
		//cout << (room[x][y] >> i & 1) << endl;
		if(room[x][y] >> i & 1) continue;
		dfs(nx, ny);
	}
}
 
int main(){
  cin >> m >> n;
  for(int i = 0; i < m; ++ i){
  	 for(int j = 0; j < n; ++ j){
  	 	cin >> room[i][j];
	   }
  }	
  
  for(int i = 0; i < m; ++ i){
  	 for(int j = 0; j < n; ++ j){
  	 	 if(!st[i][j]){
  	 		++ cntroom; roomarea = 0;
  	 		dfs(i, j);
  	 	//	cout << cntroom <<' ' << roomarea << endl;
  	 		maxarea = max(maxarea, roomarea);
		   }
	   }
  }	
 
  
  cout << cntroom << endl;
  cout << maxarea;
}