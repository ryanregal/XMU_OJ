#include<stdio.h>

int main(){
	int n;
	char p[11];
	while(scanf("%d",&n)!=EOF){
		while(n--){
			scanf("%s",p);
			printf("6");
			for(int i=6;i<=10;i++){
				printf("%c",p[i]);
			}
			printf("\n");
		}
	}
	return 0;
}

