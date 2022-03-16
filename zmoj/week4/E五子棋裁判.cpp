#include<stdio.h>
#include<stdlib.h>
int x, y, n = 0, size;

int judge(int **a, int size)
{
	for (x = 0; x < size; x++)
		for (y = 0; y < size; y++) {
			if (a[x][y] == 0)
				continue;
			else if (
				((y+4)<size && a[x][y] == a[x][y + 1] && a[x][y] == a[x][y + 2] && a[x][y] == a[x][y + 3] && a[x][y] == a[x][y + 4]) ||//ÅÐ¶Ïºá
				((x+4)<size && a[x][y] == a[x + 1][y] && a[x][y] == a[x + 2][y] && a[x][y] == a[x + 3][y] && a[x][y] == a[x + 4][y]) ||//ÅÐ¶Ï×Ý
				((x-4)>=0 && (y+4)<size && a[x][y] == a[x - 1][y + 1] && a[x][y] == a[x - 2][y + 2] && a[x][y] == a[x - 3][y + 3] && a[x][y] == a[x - 4][y + 4]) ||//ÅÐ¶ÏÓÒÐ±
				((x+4)<size && (y+4)<size &&a[x][y] == a[x + 1][y + 1] && a[x][y] == a[x + 2][y + 2] && a[x][y] == a[x + 3][y + 3] && a[x][y] == a[x + 4][y + 4]))//ÅÐ¶Ï×óÐ±
			{
				if (a[x][y] == 1)
					return 1;//´ú±íºÚÆåÓ® 
				else if (a[x][y] == -1)
					return -1;//´ú±í°×ÆåÓ® 
			}
			else
				continue;
		}
	return 0;
}

int main()
{
	int game;
	int judge(int **a, int size); 
	scanf("%d", &game);
	while (game--) {
		scanf("%d", &size);
		int a[size][size];
		for (int i = 0; i < size; i++) {
			for(int j=0;j<size;j++) a[i][j]=0;
		}
		//½«Æå×Ó´æÈëÆåÅÌ 
		for (int i = 0; i < size; i++) {
			char row[size];
			scanf("%s",row);
			for (int j = 0; j < size; j++) {
				if (row[j] == 'B') {
					a[i][j] = 1;
				}
				else if (row[j] == 'W') {
					a[i][j] = -1;
				}
			}
		}
		int *temp[size];
		for(int i=0;i<size;i++) temp[i]=a[i];
		n = judge(temp, size);
		if (n==1) printf("Black\n");
		else if (n == -1) printf("White\n");
		else if (n == 0) printf("Not so fast\n");
	}
	return 0;
}


