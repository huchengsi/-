#include"../head/SqStack.h"
#include<stdio.h>
#include<stdlib.h>
int flag = 1;
int main()
{
	SqStack *MySqStack=(SqStack*)malloc(sizeof(SqStack));
	int out,length,topdata;
	
	int x = 1;
	while (1) {

		printf("-------------操作选项-----------\n");
		printf("1:返回菜单");
		printf("          2:退出程序 \n");
		printf("3:创建空栈");
		printf("          4:判断栈是否为空 \n");
		printf("5:得到栈顶元素");
		printf("      6:清空栈 \n");
		printf("7:销毁栈");
		printf("            8:检测栈长度 \n");
		printf("9:出栈 ");
		printf("             10:入栈\n");
		


		printf("--------------------------------\n");
		printf("按数字键选择要执行的操作: ");
		scanf_s("%d", &x);
		setvbuf(stdin, NULL, _IONBF, 100);
		printf("\n");

		if (x == 2) exit(1);  //输入2，退出程序

		if ('x' < '1' || 'x' > '11')
		{
			printf("非法输入");
			break;
		}
		switch (x)
		{
		case 1:  break; //输入1，跳出switch语句，进入下一次循环
		case 3:  Init(MySqStack); break;//ok
		case 4:  judge(isEmptyStack(MySqStack)); break;
		case 5:  getTopStack(MySqStack, &topdata); break;//得到栈顶值
		case 6:  clearStack(MySqStack); break;//清除
		case 7:  destroyStack(MySqStack); break;//销毁
		case 8:  stackLength(MySqStack, &length); break;//得到长度
		case 9:  pop(MySqStack,&out); break;//出
		case 10: push(MySqStack); break;//入
	


		default: setvbuf(stdin, NULL, _IONBF, 0); //数字输入错误，跳出siwtch语句，进入下一次循环
			printf("输入数字不正确\n");
			break;
		}
		setvbuf(stdin, NULL, _IONBF, 0);
	}
	while (1);
	return 0;
}