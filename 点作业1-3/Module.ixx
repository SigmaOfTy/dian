#include<stdio.h>
void annoucement(int a, int b, int c)
{
	printf("�������ڲ���%d\n", a);
	printf("��������%d\n", b);
	printf("��������ʱ��%d\n", c);
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
	printf("������Ҫ������ݵ�����\n");
	scanf_s("%d", &number);
int enter[15] = { 0 };
	int entrance[15] = { 0 };
	int direction[15] = { 0 };
	int situation[15] = { 0 };
	for (i = 1; i <= number; i++)
	{
		printf("�������ϵ���\n");
		scanf_s("%d", &a);
		enter[i] = a;
		printf("�������µ���\n");
		scanf_s("%d", &b);
		entrance[i] = b;
		direction[i] = entrance[i] - enter[i];
	}
	for (; judgement == 1;)   //�������ϵ�һ�����е�ѭ��
	{
		if (number_now < 4)                //�ù��̱�ʾ���ݵ�һ������ʱ�ӿͣ���ʱ����ֻ�����ϲ��ܱ����ߣ��ڳ�����ʱ���뱣֤situation��Ϊ0���������ڵ�������У������ڳ�վʱ�Ὣ�ÿ͵���Ϣȫ����0�������ں����жϡ�
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
		if (number_now >= 4)                              //�ù�������ȷ�����Ͻӵ����������ߵ����Σ�������if (elevator == enter[i] && direction[i] < 0 && max(situation) == 0)��Ҫ����max(situation) == 0��Ϊ��ȷ����ʱ������û�����ϵ��˲��ܽ����µ��ˣ��������ҵ��㷨�������ҡ�Ȼ�󵱽���4�����µ���ʱ�ͻ�ֱ�ӽ������ϵ�ѭ������ʼ���¡�
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
		if (elevator > max(enter) && max(situation) == 0)     //�ù���Ϊ�����������н������жϣ�����ֱ�Ϊ1����������û����Ҫ���ҵ��������������� 2��������û����û����Ҫ�������� 3�����ݵ�����ͣ
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
		annoucement(elevator, number_now, time);       //�ô���ʾ�������м�ʱ��¥��ı仯
		elevator = elevator + 1;
		time = time + 1;
	}
	for (; judgement == 1;)   //�������µ�һ�����е�ѭ��������Ĺ��̲���ǰ�棩
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
	for (; judgement == 1;)   //�������ϵڶ������е�ѭ��
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
	for (; judgement == 1;)   //�������µڶ������е�ѭ��
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


   
    
