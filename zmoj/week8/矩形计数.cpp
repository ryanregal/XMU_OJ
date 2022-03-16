#include <stdio.h>
#include <string.h>
#define LL long long

int main()
{
    int T,n,m;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        LL ans=(n*(1+n)/2)*(m*(1+m)/2);
        printf("%lld\n",ans);
    }
    return 0;
}


