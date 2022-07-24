//补全下列两个函数即可
int lowbit(int n)
{
   return n & -n; //!-n表示n取反+1
  
}
int NumberOf1(int n) {
   int res = 0;
         while(n){
        n -=lowbit(n);
        res +=1;
    }
        return res;
}
