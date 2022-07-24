#include<bitset>
#include<cstring>
#include<iostream>
#include <memory>
using namespace std;
//bit集合
bitset<6> source[5],lights[5],res[5],line;

//输出结果
void Output(int t){
    cout<<"PUZZLE #"<<t<<endl;
    for(int i=0;i<5;++i){
        for(int j=0;j<6;++j){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main(){
    int T;
    cin>>T;
    for(int t=1;t<=T;++t){
        //进行输入
        for(int i=0;i<5;i++){
            for(int j=0;j<6;j++){
                int x;
                cin>>x;
                source[i].set(j,x);
            }
        }
        //遍历首行的64种情况
        for(int n=0;n<64;++n){
            //初始化lights的状态
            for(int i=0;i<5;i++) lights[i]=source[i];
            //开关状态初始化为n
            line=n;
            for(int i=0;i<5;++i){
                res[i]=line;//存储当前行的开关状态
                for(int j=0;j<6;++j){
                    //判断第j位是否是1
                    if(line.test(j)){
                        if(j>0) lights[i].flip(j-1);//改左灯
                        lights[i].flip(j);//改开关位置的灯
                        if(j<5)lights[i].flip(j+1);//改右灯
                    }
                }
                if(i<4) lights[i+1]^=line;//改下一行灯
                line=lights[i];//第i+1行开关方案和第i行灯情况相同
            }
            //none判断第五行是否为0
            if(lights[4].none()){
                Output(t);
                break;
            }
        }
    }
    return 0;   
}














