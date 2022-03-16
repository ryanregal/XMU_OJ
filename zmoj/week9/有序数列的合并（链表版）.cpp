#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>

//oj不通过 
typedef struct Node {
	int data;
	struct Node* next;
}Node, * List;

void InitList(List plist)//初始化
{
	plist->next = NULL;
}

int Insert_tail(List plist, int val)//尾插法给两个单链表插入数据 
{
	Node* p = (Node*)malloc(sizeof(Node));//创建新结点 
	p->data = val;//赋值 
	Node* q;
	for (q = plist; q->next != NULL; q = q->next);//找尾结点
	//将p插入在q后面 
	p->next = q->next;//p->next = NULL;
	q->next = p;
	return 0;
}

void Merge(List plistC, List plistA, List plistB)//两个递增有序单链表合并
{
	Node* ptrA = plistA->next;
	Node* ptrB = plistB->next;
	Node* q = plistC;
	while (plistB->next != NULL && plistA->next != NULL)
	{
		ptrA = plistA->next;
		ptrB = plistB->next;
		if (ptrA->data <= ptrB->data)//小的数据取出，用尾插法插入C中 
		{
			plistA->next = ptrA->next;//A表指针后移 
			//将p插入在q后面 
			ptrA->next = q->next;//p->next = NULL;
			q->next = ptrA;
			q = q->next;
		}
		else
		{
			plistB->next = ptrB->next;//B表指针后移 
			//将p插入在q后面 
			ptrB->next = q->next;//p->next = NULL;
			q->next = ptrB;
			q = q->next;
		}
	}
	if (plistA->next == NULL)//当A表遍历完 
	{
		while (plistB->next != NULL) {
			ptrB = plistB->next;
			plistB->next = ptrB->next;//B表指针后移 
			ptrB->next = q->next;//尾插法插入 
			q->next = ptrB;
			q = q->next;
		}
	}
	else {//当B表遍历完 
		while (plistA->next != NULL)
		{
			ptrA = plistA->next;
			plistA->next = ptrA->next;//A表指针后移 
			ptrB->next = q->next;//尾插法插入 
			q->next = ptrA;
			q = q->next;
		}
	}
}

void Show(List plist)//打印函数，输出所有节点
{
	for (Node* p = plist->next; p != NULL; p = p->next) {
		printf("%d", p->data);
		if (p->next != NULL) printf(" ");
	}
	printf("\n");
}

void Destroy(List plist)//摧毁链表节点，防止内存泄漏。
{
	assert(plist != NULL);
	Node* p;
	while (plist->next != NULL){
		p = plist->next;
		plist->next = p->next;
		free(p);
	}
}

int main()
{
	Node head1;
	Node head2;
	Node head3;
	char text[100000];
	char text2[100000];

	while (gets(text)) {
		int Anum = 0, Bnum = 0, Acount = 0, Bcount = 0;
		InitList(&head1);
		InitList(&head2);
		InitList(&head3);
		char* tok;
		tok = strtok(text, " ");
		while (tok) {
			Anum = atoi(tok);
			Insert_tail(&head1, Anum);
			Acount++;
			tok = strtok(NULL, " ");
		}
		gets(text2);
		tok = strtok(text2, " ");
		while (tok) {
			Bnum = atoi(tok);
			Insert_tail(&head2, Bnum);
			Bcount++;
			tok = strtok(NULL, " ");
		}
		Merge(&head3, &head1, &head2);
		Show(&head3);
		memset(text, 0, sizeof(text));
		memset(text2, 0, sizeof(text2));
		Destroy(&head1);
		Destroy(&head2);
		Destroy(&head3);
	}
	return 0;
}
