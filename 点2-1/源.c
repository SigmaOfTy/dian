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

int main()
{
	int time = 0, number, elevator = 1, i, number_now = 0, judgement = 1, a, b, c;
	printf("������Ҫ������ݵ�����\n");
	scanf_s("%d", &number);
	int NUMBER = number;
	int enter[15] = { 0 };
	int entrance[15] = { 0 };
	int direction[15] = { 0 };
	int situation[15] = { 0 };
	int enter_prepared[15] = { 0 };
	int entrance_prepared[15] = { 0 };
	int time_prepared[15] = { -1 };
	printf("��������ݴ�ʱ�ڵڼ���");
	scanf_s("%d", &elevator);

	for (i = 1; i <= number; i++)
	{
		printf("���˶���ϵ���");
		scanf_s("%d", &c);
		time_prepared[i] = c;
		printf("�������ϵ���\n");
		scanf_s("%d", &a);
		enter_prepared[i] = a;
		printf("�������µ���\n");
		scanf_s("%d", &b);
		entrance_prepared[i] = b;
	}
	for (; NUMBER != 0;)
	{
		for (i = 1; i <= number; i++)
		{
			if (time_prepared[i] == time)
			{
				enter[i] = enter_prepared[i];
				entrance[i] = entrance_prepared[i];
				direction[i] = entrance[i] - enter[i];
				enter_prepared[i] = entrance_prepared[i] = 0;
				time_prepared[i] = -1;
			}
		}
		for (; max(entrance) != 0 || min(entrance) != 0;)
		{
			for (; judgement == 1;)                //�������ϵ�һ�����е�ѭ��
			{
				if (number_now < 4)                //�ù��̱�ʾ���ݵ�һ������ʱ�ӿͣ���ʱ����ֻ�����ϲ��ܱ����ߣ��ڳ�����ʱ���뱣֤situation��Ϊ0���������ڵ�������У������ڳ�վʱ�Ὣ�ÿ͵���Ϣȫ����0�������ں����жϡ�
				{
					for (i = 1; i <= number; i++)
					{
						if (time_prepared[i] == time)
						{
							enter[i] = enter_prepared[i];
							entrance[i] = entrance_prepared[i];
							direction[i] = entrance[i] - enter[i];
							enter_prepared[i] = entrance_prepared[i] = 0;
							time_prepared[i] = -1;
						}
						if (elevator == enter[i] && direction[i] > 0)
						{
							number_now = number_now + 1;
							enter[i] = 0;
							situation[i] = 1;
							annoucement(elevator, number_now, time);
						}
						if (elevator == entrance[i] && direction[i] > 0 && situation[i] != 0)
						{
							number_now = number_now - 1;
							entrance[i] = direction[i] = 0;
							situation[i] = 0;
							NUMBER = NUMBER - 1;
							annoucement(elevator, number_now, time);
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
							entrance[i] = direction[i] = situation[i] = 0;
							NUMBER = NUMBER - 1;
							annoucement(elevator, number_now, time);
						}
					}
				}
				if (elevator <= max(enter))
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
								annoucement(elevator, number_now, time);
							}
						}
					}
					if (number_now >= 4 && max(situation) == 0)
					{
						break;
					}
				}
				if (elevator > max(enter) && max(situation) == 0)     //�ù���Ϊ�����������н������жϣ�����ֱ�Ϊ1����������û����Ҫ���ҵ��������������� 2��������û����û����Ҫ�������� 3�����ݵ�����ͣ
				{
					break;
				}
				if (number_now == 0 && max(direction) == 0 && min(direction) == 0)
				{
					break;
				}
				if (elevator == 10)
				{
					break;
				}     //�ô���ʾ�������м�ʱ��¥��ı仯
				elevator = elevator + 1;
				time = time + 1;

			}
			for (; judgement == 1;)   //�������µ�һ�����е�ѭ��������Ĺ��̲���ǰ�棩
			{
				if (number_now < 4)
				{
					for (i = 1; i <= number; i++)
					{
						if (time_prepared[i] == time)
						{
							enter[i] = enter_prepared[i];
							entrance[i] = entrance_prepared[i];
							direction[i] = entrance[i] - enter[i];
							enter_prepared[i] = entrance_prepared[i] = 0;
							time_prepared[i] = -1;
						}
						if (elevator == enter[i] && direction[i] < 0)
						{
							number_now = number_now + 1;
							enter[i] = 0;
							situation[i] = -1;
							annoucement(elevator, number_now, time);
						}
						if (elevator == entrance[i] && direction[i] < 0 && situation[i] != 0)
						{
							number_now = number_now - 1;
							entrance[i] = direction[i] = 0;
							situation[i] = 0;
							NUMBER = NUMBER - 1;
							annoucement(elevator, number_now, time);

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
							NUMBER = NUMBER - 1;
							annoucement(elevator, number_now, time);
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
								annoucement(elevator, number_now, time);
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
					break;
				}
				if (number_now == 0 && max(direction) == 0 && min(direction) == 0)
				{
					break;
				}
				if (elevator == 1)
				{
					break;
				}
				elevator = elevator - 1;
				time = time + 1;
			}
			
		}
		time = time + 1;
	}
}