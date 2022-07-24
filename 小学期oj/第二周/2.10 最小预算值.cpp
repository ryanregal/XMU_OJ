#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int N, M; 
int money[100005];

bool budgetIsEnough(int budget) {
	int dayTotal = 0, cnt = 1; 
	for (int i = 0;  i < N; i++) {
		if (money[i] > budget)
			return false;
		if (money[i] + dayTotal > budget) {
			dayTotal = money[i];  
			cnt++;
			if (cnt > M)
				return false;
		}
		else
			dayTotal += money[i];
	}
	return true;
}

int binSearch(int l, int r) {
	while (l < r) {
		int budget = l + r >> 1;
		if (budgetIsEnough(budget))
			r = budget;
		else
			l = budget + 1;
	}
	return l;
}

int main() {
	scanf("%d%d", &N, &M);
	int minCost = 1 << 32;
	int totalCost = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &money[i]);
		minCost = min(minCost, money[i]);
		totalCost += money[i];
	}
	cout << binSearch(minCost, totalCost) << endl;

	return 0;
}