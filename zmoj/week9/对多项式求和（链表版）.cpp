#include<stdio.h>
#include<stdlib.h> 

typedef struct node {
	int coef;//系数 
	int expo;//指数 
	struct node* next;//指针 
}node;

//创建单链表存储多项式 
struct node* create(int m) {
	node* head, * p, * q;
	head = (node*)malloc(sizeof(node));//给头指针head分配内存空间 
	head->next = NULL;
	q = head;//让q等于head的头节点 
	for (int i = 0; i < m; i++) {
		p = (node*)malloc(sizeof(node));//给p分配内存空间 
		scanf("%d%d", &p->coef, &p->expo);//输入系数、指数 
		p->next = q->next;//尾插法
		q->next = p;
		q = q->next;
	}
	return head;
}


void print(node* head) //遍历打印单链表
{
	node* p,q;//定义一个node类型的指针 
	p = (node*)malloc(sizeof(node));//申请空间 
	p = head->next;
	int flag = 0;	
	int judge = 0;//判断全0时
	while (p)//循环语句，如果p的后继节点不为空时开始循环 
	{
		if (p->coef == 0) {
			p = p->next;
			judge = 0;
			continue;
		}
		judge = -1;
		if (flag == 0) {
			if (p->coef == 1) {
				if (p->expo == 0) printf("1");
				else if (p->expo == 1) printf("x");
				else printf("x^%d", p->expo);
			}
			else if (p->coef == -1) {
				if (p->expo == 0) printf("-1");
				else if (p->expo == 1) printf("-x");
				else printf("-x^%d", p->expo);
			}
			else if (p->coef > 0) {
				if (p->expo == 0) printf("%d", p->coef);
				else if (p->expo == 1) printf("%dx", p->coef);
				else printf("%dx^%d", p->coef, p->expo);
			}
			else if (p->coef < 0) {
				if (p->expo == 0) printf("-%d", -1 * p->coef);
				else if (p->expo == 1) printf("-%dx", -1 * p->coef);
				else  printf("-%dx^%d", -1 * p->coef, p->expo);
			}
			flag = 1;
		}
		
		p = p->next;
		if(p==NULL) break;
		if (p->coef == 1) {
			if (p->expo == 0) printf(" + 1");
			else if (p->expo == 1) printf(" + x");
			else printf(" + x^%d", p->expo);
		}
		else if (p->coef == -1) {
			if (p->expo == 0) printf(" - 1");
			else if (p->expo == 1) printf(" - x");
			else printf(" - x^%d", p->expo);
		}
		else if (p->coef > 0) {
			if (p->expo == 0) printf(" + %d", p->coef);
			else if (p->expo == 1) printf(" + %dx", p->coef);
			else printf(" + %dx^%d", p->coef, p->expo);
		}
		else if (p->coef < 0) {
			if (p->expo == 0) printf(" - %d", -1 * p->coef);
			else if (p->expo == 1) printf(" - %dx", -1 * p->coef);
			else  printf(" - %dx^%d", -1 * p->coef, p->expo);
		}
	}
	if (judge == 0) {
		printf("0\n");
		return;
	}
	printf("\n");
}

//将多项式按指数从小到大排序
void srot(node* head) {
	node* p, * q;
	int temp1, temp2;//中间变量 
	for (p = head->next; p != NULL; p = p->next)
	{
		for (q = p->next; q != NULL; q = q->next) {
			if (p->expo > q->expo) {
				temp1 = p->expo;
				p->expo = q->expo;
				q->expo = temp1;
				temp2 = p->coef;
				p->coef = q->coef;
				q->coef = temp2;
			}
			else if(p->expo == q->expo){
				q->coef += p->coef;
				p->coef = 0,p->expo=0;
			}
		}
	}
}

struct node* add(node* head1, node* head2)//两个多项式相加后，存入第一个多项式head1中
{
	node* Pa, * Pb, * p;
	Pa = head1->next;
	Pb = head2->next;
	p = head1;
	while (Pa != NULL && Pb != NULL) {
		if (Pa->expo == Pb->expo) {
			Pa->coef = Pa->coef + Pb->coef;
			p->next = Pa;
			p = p->next;
			Pa = Pa->next;
			Pb = Pb->next;
		}
		else if (Pa->expo < Pb->expo) {
			p->next = Pa;
			p = p->next;
			Pa = Pa->next;
		}
		else {
			p->next = Pb;
			p = p->next;
			Pb = Pb->next;
		}
	}

	if (Pa != NULL)	p->next = Pa;
	else	p->next = Pb;
	return head1;
}

int Destoey(node* head1, node* head2, node* head3) {
	head1 = NULL, head2 = NULL, head3 = NULL;
	return 0;
}

int main() {
	node* head1, * head2, * sum;
	int m, n;
	while (scanf("%d%d", &m, &n) != EOF) {
		head1 = create(m);
		srot(head1);
		head2 = create(n);
		srot(head2);
		sum = add(head1, head2);//调用函数进行求和 
		srot(sum);
		print(sum);//输出结果
		Destoey(head1, head2, sum);
	}
	return 0;
}
