#include<stdio.h>
void annoucement(int a, int b, int c)
{
	printf("电梯所在层数%d\n", a);
	printf("电梯人数%d\n", b);
	printf("电梯运行时间%d\n", c);
}
int max(int a[])
{
	int length, max, i;
	length = 10;
	max = a[0];
	for (i = 0; i <= length; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	return max;
}
int min(int a[])
{
	int length, min, i;
	length = 10;
	min = a[0];
	for (i = 0; i <= length; i++)
	{
		if (a[i] < min)
			min = a[i];
	}
	return min;
}
int main(void)
{
	int time = 0, number, elevator = 1, i, a, b, number_now = 0, judgement = 1;
	printf("请输入要进入电梯的人数\n");
	scanf_s("%d", &number);
int enter[15] = { 0 };
	int entrance[15] = { 0 };
	int direction[15] = { 0 };
	int situation[15] = { 0 };
	for (i = 1; i <= number; i++)
	{
		printf("从哪里上电梯\n");
		scanf_s("%d", &a);
		enter[i] = a;
		printf("从哪里下电梯\n");
		scanf_s("%d", &b);
		entrance[i] = b;
		direction[i] = entrance[i] - enter[i];
	}
	for (; judgement == 1;)   //电梯往上第一次运行的循环
	{
		if (number_now < 4)                //该过程表示电梯第一次上行时接客，这时客人只有向上才能被接走，在出电梯时必须保证situation不为0（即必须在电梯里才行），且在出站时会将旅客的信息全部归0，有利于后续判断。
		{
			for (i = 1; i <= number; i++)
			{
				if (elevator == enter[i] && direction[i] > 0)
				{
					number_now = number_now + 1;
					enter[i] = 0;
					situation[i] = 1;
				}
				if (elevator == entrance[i] && direction[i] > 0&& situation[i]!=0)
				{
					number_now = number_now - 1;
					entrance[i] = direction[i] = 0;
					situation[i] = 0;
				}
			}
		}
		if (number_now >= 4)                              //该过程用于确定向上接的人是往下走的情形，其中在if (elevator == enter[i] && direction[i] < 0 && max(situation) == 0)中要满足max(situation) == 0是为了确定此时电梯中没有向上的人才能接向下的人，否则在我的算法里会出混乱。然后当接了4个向下的人时就会直接结束向上的循环而开始向下。
		{
			for (i = 1; i <= number; i++)
			{
				if (elevator == entrance[i] && direction[i] > 0 && enter[i] == 0 && situation[i] != 0)
				{
					number_now = number_now - 1;
					entrance[i] = direction[i] = situation[i]=0;
				}
			}
		}
		if ( elevator <= max(enter))
		{
			if (number_now < 4)
			{
				for (i = 1; i <= number; i++)
				{
					if (elevator == enter[i] && direction[i] < 0 && max(situation) == 0)
					{
						number_now = number_now + 1;
						enter[i] = 0;
						situation[i] = -1;
					}
				}
			}
			if (number_now >= 4&&max(situation)==0)
			{
				break;
			}
		}
		if (elevator > max(enter) && max(situation) == 0)     //该过程为电梯向上运行结束的判断，含义分别为1、电梯上面没有人要进且电梯里所有人向下 2、电梯里没人且没人需要再坐电梯 3、电梯到顶层停
		{
			annoucement(elevator, number_now, time);
			break;
		}
		if (number_now == 0 && max(direction) == 0&&min(direction)==0)
		{
			annoucement(elevator, number_now, time);
			break;
		}
		if (elevator == 10)
		{
			break;
		}
		annoucement(elevator, number_now, time);       //该处表示电梯运行即时间楼层的变化
		elevator = elevator + 1;
		time = time + 1;
	}
	for (; judgement == 1;)   //电梯往下第一次运行的循环（后面的过程参照前面）
	{
		if (number_now < 4)                                        
		{
			for (i = 1; i <= number; i++)
			{
				if (elevator == enter[i] && direction[i] < 0)
				{
					number_now = number_now + 1;
					enter[i] = 0;
					situation[i] = -1;
				}
				if (elevator == entrance[i] && direction[i] < 0 && situation[i] != 0)
				{
					number_now = number_now - 1;
					entrance[i] = direction[i] = 0;
					situation[i] = 0;
				}
			}
		}
		if (number_now >= 4)
		{
			for (i = 1; i <= number; i++)
			{
				if (elevator == entrance[i] && direction[i] < 0 && enter[i] == 0 && situation[i] != 0)
				{
					number_now = number_now - 1;
					entrance[i] = direction[i] = 0;
					situation[i] = 0;
				}
			}
		}
		if (elevator >= min(enter))
		{
			if (number_now < 4)
			{
				for (i = 1; i <= number; i++)
				{
					if (elevator == enter[i] && direction[i] > 0 && min(situation) == 0)
					{
						number_now = number_now + 1;
						enter[i] = 0;
						situation[i] = 1;
					}
				}
			}
			if (number_now >= 4&&min(situation)==0)
			{
				break;
			}
		}
		if (elevator <= min(enter)&&min(situation) == 0)
		{
			annoucement(elevator, number_now, time);
			break;
		}
		if (number_now == 0 && max(direction)==0&&min(direction)==0)
		{
			annoucement(elevator, number_now, time);
			break;
		}
		if (elevator == 1)
		{
			break;
		}
		annoucement(elevator, number_now, time);
		elevator = elevator -1;
		time = time + 1;
	}
	for (; judgement == 1;)   //电梯往上第二次运行的循环
	{
		if (number_now < 4)
		{
			for (i = 1; i <= number; i++)
			{
				if (elevator == enter[i] && direction[i] > 0)
				{
					number_now = number_now + 1;
					enter[i] = 0;
					situation[i] = 1;
				}
				if (elevator == entrance[i] && direction[i] > 0 && situation[i] != 0)
				{
					number_now = number_now - 1;
					entrance[i] = direction[i] = 0;
					situation[i] = 0;
				}
			}
		}
		if (number_now >= 4)
		{
			for (i = 1; i <= number; i++)
			{
				if (elevator == entrance[i] && direction[i] > 0 && enter[i] == 0 && situation[i] != 0)
				{
					number_now = number_now - 1;
					entrance[i] = direction[i] = 0;
					situation[i] = 0;
				}
			}
		}
		if (max(direction) == 0 && elevator <= max(enter))
		{
			if (number_now < 4)
			{
				for (i = 1; i <= number; i++)
				{
					if (elevator == enter[i] && direction[i] < 0&&max(situation)==0)
					{
						number_now = number_now + 1;
						enter[i] = 0;
						situation[i] = -1;
					}
				}
			}
			if (number_now >= 4 && max(situation) == 0)
			{
				break;
			}
		}
		if ((elevator > max(enter)) && max(situation) == 0)
		{
			annoucement(elevator, number_now, time);
			break;
		}
		if (number_now == 0 && max(direction) == 0 && min(direction) == 0)
		{
			annoucement(elevator, number_now, time);
			break;
		}
		if (elevator == 10)
		{
			break;
		}
		annoucement(elevator, number_now, time);
		elevator = elevator + 1;
		time = time + 1;
	}
	for (; judgement == 1;)   //电梯往下第二次运行的循环
	{
		if (number_now < 4)
		{
			for (i = 1; i <= number; i++)
			{
				if (elevator == enter[i] && direction[i] < 0)
				{
					number_now = number_now + 1;
					enter[i] = 0;
					situation[i] = -1;
				}
				if (elevator == entrance[i] && direction[i] < 0 && situation[i] != 0)
				{
					number_now = number_now - 1;
					entrance[i] = direction[i] = 0;
					situation[i] = 0;
				}
			}
		}
		if (number_now >= 4)
		{
			for (i = 1; i <= number; i++)
			{
				if (elevator == entrance[i] && direction[i] < 0 && enter[i] == 0 && situation[i] != 0)
				{
					number_now = number_now - 1;
					entrance[i] = direction[i] = 0;
					situation[i] = 0;
				}
			}
		}
		if (elevator >= min(enter))
		{
			if (number_now < 4)
			{
				for (i = 1; i <= number; i++)
				{
					if (elevator == enter[i] && direction[i] > 0 && min(situation) == 0)
					{
						number_now = number_now + 1;
						enter[i] = 0;
						situation[i] = 1;
					}
				}
			}
			if (number_now >= 4 && min(situation) == 0)
			{
				break;
			}
		}
		if (elevator <= min(enter) && min(situation) == 0)
		{
			annoucement(elevator, number_now, time);
			break;
		}
		if (number_now == 0 && max(direction) == 0 && min(direction) == 0)
		{
			annoucement(elevator, number_now, time);
			break;
		}
		if (elevator == 1)
		{
			break;
		}
		annoucement(elevator, number_now, time);
		elevator = elevator - 1;
		time = time + 1;
	}
}


   
    
