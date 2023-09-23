#include<stdio.h>
#include<math.h>
int main(void)
{
	int a,b,e;
	printf("请输入乘客所在层数\n");
	scanf_s("%d", &a);
	printf("请输入乘客要去往的电梯层数\n");
	scanf_s("%d", &b);
	printf("请输入电梯所在层数\n");
	scanf_s("%d", &e);
	int t1 = abs(a - e), t2 = abs(a - b);
	printf("%d 0 0\n", e);
	printf("%d %d 1\n", a, t1);
	printf("%d %d 0\n", b, t1 + t2);
}



