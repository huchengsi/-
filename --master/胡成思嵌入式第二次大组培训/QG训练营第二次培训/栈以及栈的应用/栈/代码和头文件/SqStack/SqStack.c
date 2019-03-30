#include"../head/SqStack.h"
#include<stdio.h>
#include<stdlib.h>
//#include<stdbool.h>
//˳��ջ(���������)
Status initStack(SqStack *s,int sizes)  //��ʼ��ջ
{

	int *data=(ElemType*)malloc(sizeof(ElemType)*(sizes));  //��ʼ��һ������Ŀռ�
	if (*data == NULL)
		return ERROR;
	s->elem = data;
	s->size = sizes;                                       
	s->top = -1;                                            //0��С��-1Ϊ��ʼ
	return SUCCESS;
}
Status isEmptyStack(SqStack *s)   //�ж�ջ�Ƿ�Ϊ��
{
	if (s->top == -1)
		return SUCCESS;
	else
		return ERROR;
	
}
Status getTopStack(SqStack *s,ElemType *e)   //�õ�ջ��Ԫ��
{
	if (s->top == -1)
	{
		printf("�������޷�ʹ�ô˹���\n");
		return ERROR;
	}
	*e = s->elem[s->top];
	printf("�õ�ֵ%d\n", *e);
	return SUCCESS;
}
Status clearStack(SqStack *s)   //���ջ
{
	if (s->top == -1)
	{
		printf("���ʧ��\n");
		return ERROR;
	}
	int a = s->size;
	free(s->elem);
	initStack(s, a);
	printf("��ճɹ�\n");
	return SUCCESS;
}
Status destroyStack(SqStack *s)  //����ջ
{   
	if (s->top == -1)
	{
		printf("����ʧ��\n");
		return ERROR;
	}

	free(s->elem);
	free(s);
	printf("���ٳɹ�\n");
	return SUCCESS;
}
Status stackLength(SqStack *s,int *length)   //���ջ����
{
	if (s->top == -1)
	{
		printf("������һ����ջ\n");
		return ERROR;
	}
	*length = s->top;
	printf("����Ϊ%d\n", (*length+1));
	return SUCCESS;
}
Status pushStack(SqStack *s,ElemType data)  //��ջ
{
	
	if (s->top == (s->size)-1)    //�ж��Ƿ񳬹����ɷ�Χ
		return ERROR;
	s->top += 1;                  //ջ������
	s->elem[s->top] = data;       
}
Status popStack(SqStack *s,ElemType *data)   //��ջ
{
	
	if (s->top == -1||s->top<0)//���ٺ�s->top��Ϊ��һ������ĸ�������֪����ĵ��Ե�Ч��
		return ERROR;
	(*data) = s->elem[s->top];         
	s->top -= 1;             
	return SUCCESS;
}

void push(SqStack *s)
{
	if (s->size < 0)
	{
		printf("������δ��ʼ����ջ\n");
		return ;
	}

	int a = 0;
	printf("��������Ҫ��ջ������\n");
	scanf_s("%d", &a);
	if (pushStack(s, a))                  //����pushStack������ջ�����ж�
		printf("�ɹ�ѹջ������Ϊ%d\n",a);
	else
		printf("ѹջʧ�ܣ�������ջ��\n");
}
void pop(SqStack *s,ElemType *e)
{

	if (popStack(s,e))                  
		printf("�ɹ���ջ������Ϊ%d\n",*e);
	else
		printf("��ջʧ�ܣ��ǿ�ջδ���ʼ����ջ\n");
}
void Init(SqStack *s)
{
	int a = 0;                      
	printf("������ջ�Ĵ�С\n");
	scanf_s("%d", &a);
	if (initStack(s,a))
		printf("�ɹ���ʼ��ջ��ջ��СΪ%d\n", a);
	else
		printf("��ʼ��ʧ��\n");
}


void judge(int a)         //aֻ��0��1
{
	if (a)
		printf("��\n");
	else
		printf("����\n");
}
