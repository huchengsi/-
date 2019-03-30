#include"../head/SqStack.h"
#include<stdio.h>
#include<stdlib.h>
//#include<stdbool.h>
//顺序栈(基于数组的)
Status initStack(SqStack *s,int sizes)  //初始化栈
{

	int *data=(ElemType*)malloc(sizeof(ElemType)*(sizes));  //初始化一个数组的空间
	if (*data == NULL)
		return ERROR;
	s->elem = data;
	s->size = sizes;                                       
	s->top = -1;                                            //0最小，-1为初始
	return SUCCESS;
}
Status isEmptyStack(SqStack *s)   //判断栈是否为空
{
	if (s->top == -1)
		return SUCCESS;
	else
		return ERROR;
	
}
Status getTopStack(SqStack *s,ElemType *e)   //得到栈顶元素
{
	if (s->top == -1)
	{
		printf("空链表无法使用此功能\n");
		return ERROR;
	}
	*e = s->elem[s->top];
	printf("得到值%d\n", *e);
	return SUCCESS;
}
Status clearStack(SqStack *s)   //清空栈
{
	if (s->top == -1)
	{
		printf("清空失败\n");
		return ERROR;
	}
	int a = s->size;
	free(s->elem);
	initStack(s, a);
	printf("清空成功\n");
	return SUCCESS;
}
Status destroyStack(SqStack *s)  //销毁栈
{   
	if (s->top == -1)
	{
		printf("销毁失败\n");
		return ERROR;
	}

	free(s->elem);
	free(s);
	printf("销毁成功\n");
	return SUCCESS;
}
Status stackLength(SqStack *s,int *length)   //检测栈长度
{
	if (s->top == -1)
	{
		printf("可能是一个空栈\n");
		return ERROR;
	}
	*length = s->top;
	printf("长度为%d\n", (*length+1));
	return SUCCESS;
}
Status pushStack(SqStack *s,ElemType data)  //入栈
{
	
	if (s->top == (s->size)-1)    //判断是否超过容纳范围
		return ERROR;
	s->top += 1;                  //栈顶向上
	s->elem[s->top] = data;       
}
Status popStack(SqStack *s,ElemType *data)   //出栈
{
	
	if (s->top == -1||s->top<0)//销毁后s->top成为了一个随机的负数，不知道别的电脑的效果
		return ERROR;
	(*data) = s->elem[s->top];         
	s->top -= 1;             
	return SUCCESS;
}

void push(SqStack *s)
{
	if (s->size < 0)
	{
		printf("可能是未初始化的栈\n");
		return ;
	}

	int a = 0;
	printf("请输入想要入栈的数据\n");
	scanf_s("%d", &a);
	if (pushStack(s, a))                  //调用pushStack，加入栈，做判断
		printf("成功压栈，数据为%d\n",a);
	else
		printf("压栈失败，或许满栈了\n");
}
void pop(SqStack *s,ElemType *e)
{

	if (popStack(s,e))                  
		printf("成功出栈，数据为%d\n",*e);
	else
		printf("出栈失败，是空栈未或初始化的栈\n");
}
void Init(SqStack *s)
{
	int a = 0;                      
	printf("请输入栈的大小\n");
	scanf_s("%d", &a);
	if (initStack(s,a))
		printf("成功初始化栈，栈大小为%d\n", a);
	else
		printf("初始化失败\n");
}


void judge(int a)         //a只有0和1
{
	if (a)
		printf("是\n");
	else
		printf("不是\n");
}
