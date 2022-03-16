/*
icebear:二维前缀和问题
容斥原理：(边长为R的正方形) 
  i     j 
  ∑    ∑  A[x,y] = S[i,j]-S[i-R,j]-S[i,j-R]+S[i-R,j-R];
i-R+1 j-R+1
①计算二维前缀和
②枚举所有子矩阵计算max 
*/
 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 5005;
int arr[N][N];
int main () {
    int n, r;
    cin >> n >> r;
    int x, y;
    for(int i = 0; i < n; i++) {
        scanf("%d%d",&x, &y);
        scanf("%d", &arr[x+1][y+1]);
    }
    //计算前缀和
    for(int i = 1; i <= 5000; i++) {
        int sum = 0;
        for(int j = 1; j <= 5000; j++) {
            sum += arr[i][j];
            arr[i][j] = sum + arr[i-1][j];
        }
    }
    int maxValue = -1;
    //枚举左上角顶点
    for(int i = 1; i <= 5001-r; i++) {
        for(int j = 1; j <= 5001-r; j++) {
            int temp = arr[i+r-1][j+r-1] + arr[i-1][j-1] - arr[i-1][j+r-1] - arr[i+r-1][j-1];
            maxValue = max(maxValue, temp);
        }
    }
    cout << maxValue << endl;
    return 0;
}
