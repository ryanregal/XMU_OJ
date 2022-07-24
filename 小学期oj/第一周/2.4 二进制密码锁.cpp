#include <iostream>
#include<cstring>
#include<bitset>
#include<algorithm>
using namespace std;

int main(){
    string line;//输入01的字符串
    bitset<32> lock;//当前的状态
    int minTimes=1<<30;//初始化按钮次数为无穷大
    cin>>line;
    bitset<32>sourceLock(line);//当前
    cin>>line;
    bitset<32> targetLock(line);//目标
    int n=line.size();
    
    //p=0代表最左边按钮不按
    for(int p=0;p<2;++p){
        lock=sourceLock;
        int times=0;
        //初始化下一个按钮状态，是否按下
        int nextButton=p;
        //遍历所有位置
        for(int i=0;i<n;++i){
            if(nextButton==1){
                ++times;
                if(i>0) lock.flip(i-1);//左边取反
                lock.flip(i);
                if(i<n-1) lock.flip(i+1);
            }
            //判断当前lock是否与目标targetLock的第i位相同
            if(lock[i]!=targetLock[i]) nextButton=1;//如果不同就在下次循环按下按钮
            else nextButton=0;
        }
        if(lock==targetLock){
            minTimes=min(minTimes,times);//取最小值
        }
    }
    if(minTimes==1<<30){//没有找到
        cout<<"impossible"<<endl;
    }
    else cout<<minTimes<<endl;
    return 0;  
}