#include"../head/LinkStack.h"
#include<stdio.h>
#include<stdlib.h>
int main()
{
	LinkStack *MySqStack = (LinkStackPtr)malloc(sizeof(LinkStack*));
	int out, length, topdata;

	int x = 1;
	while (1) {

		printf("-------------����ѡ��-----------\n");
		printf("1:���ز˵�");
		printf("          2:�˳����� \n");
		printf("3:������ջ");
		printf("          4:�ж�ջ�Ƿ�Ϊ�� \n");
		printf("5:�õ�ջ��Ԫ��");
		printf("      6:���ջ \n");
		printf("7:����ջ");
		printf("            8:���ջ���� \n");
		printf("9:��ջ ");
		printf("             10:��ջ\n");



		printf("--------------------------------\n");
		printf("�����ּ�ѡ��Ҫִ�еĲ���: ");
		scanf_s("%d", &x);
		setvbuf(stdin, NULL, _IONBF, 100);
		printf("\n");

		if (x == 2) exit(1);  //����2���˳�����

		if ('x' < '1' || 'x' > '11')
		{
			printf("�Ƿ�����");
			break;
		}
		switch (x)
		{
		case 1:  break; //����1������switch��䣬������һ��ѭ��
		case 3:   Init(MySqStack); break;//ok
		case 4:  judge(isEmptyLStack(MySqStack)); break;//
		case 5:  getTopLStack(MySqStack, &topdata); break;//�õ�ջ��ֵ
		case 6: clearLStack(MySqStack); break;//ok
		case 7:  destroyLStack(MySqStack); break;//
		case 8:  LStackLength(MySqStack, &length); break;
		case 9:  pop(MySqStack, &out); break;
		case 10: push(MySqStack); break;//



		default: setvbuf(stdin, NULL, _IONBF, 0); //���������������siwtch��䣬������һ��ѭ��
			printf("�������ֲ���ȷ\n");
			break;
		}
		setvbuf(stdin, NULL, _IONBF, 0);
	}
	while (1);
	return 0;
}