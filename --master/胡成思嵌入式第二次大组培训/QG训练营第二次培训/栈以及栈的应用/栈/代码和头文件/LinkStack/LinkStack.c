#include"../head/LinkStack.h"
#include<stdio.h>
#include<stdlib.h>

//��ջ(���������)
Status initLStack(LinkStack *s)   //��ʼ��
{
	s->top= (LinkStackPtr)malloc(sizeof(StackNode));//��topָ�����ռ�
	if (!s->top)                                    //�ж��Ƿ�ɹ�
		return ERROR;
	s->top = NULL;                                  //���������ȳ�ʼ��ָ��
	s->count = 0;
	return SUCCESS;

}
Status isEmptyLStack(LinkStack *s)  //�ж���ջ�Ƿ�Ϊ��
{
	if (s->count == 0)
		return SUCCESS;
	else
		return ERROR;
}
Status getTopLStack(LinkStack *s,ElemType *e)  //�õ�ջ��Ԫ��
{
	*e = s->top->data;
	printf("%d\n",*e);
}
Status clearLStack(LinkStack *s)   //���ջ
{
	if (s->count < 0||s->count==0)
	{
		printf("�޷�����������δ��������\n");
		return ERROR;
	}
	else
	{

		free(s->top);
		initLStack(s);
		printf("�������ɹ�\n");
		return SUCCESS;
	}

}
Status destroyLStack(LinkStack *s)   //����ջ
{
	int clr;
	if (s->count < 0)
	{
		printf("�޷�����δ��ʼ��������\n");
		return ERROR;
	}
	else
	{
		free(s);
	}
	return SUCCESS;
}
Status LStackLength(LinkStack *s,int *length)    //���ջ����
{
	if (s->count <= 0)
	{
		printf("��ջ����Ϊ����\n");
		return ERROR;
	}
		
	*length = s->count;
	printf("����Ϊ%d\n", *length);

}
Status pushLStack(LinkStack *s,ElemType data)   //��ջ
{
	if (s->top != NULL && s->count < 0)
	{
		return ERROR;
	}
	StackNode *node = (LinkStackPtr)malloc(sizeof(StackNode));//�����½ڵ�
	node->data = data;                
	node->next = s->top;                                     //��ջ����
	s->top = node;                                             //ջ��
	(s->count)++;                  //��¼ջ����

}
Status popLStack(LinkStack *s,ElemType *data)   //��ջ
{
	if (s->count == 0)
	{
		return ERROR;
		printf("�ǿ�ջ/n");
	}
	if (s->top != NULL && s->count < 0)
	{
		return ERROR;
	}
   StackNode *topnode = s->top;        //����һ��ָ��ջ����ָ��
   *data = topnode->data;
   s->top = s->top->next;           //ջ��ָ������һλ
   free(topnode);                    //�ͷ��ڴ�
   (s->count)--;           //��¼ջ����
   return SUCCESS;
}


void Init(LinkStackPtr mystack)//����initlstack��ʼ��ջ��δ��ʼ��ʱcount��ȻΪ����
{
	if (initLStack(mystack))
		printf("�ɹ���ʼ����ջ\n");
	else
		printf("��ʼ��ʧ��\n");
}

void push(LinkStackPtr mystack)//����pushlstack��ջ
{

	ElemType data;
	printf("����������\n");
	scanf_s("%d",&data);
	if (pushLStack(mystack, data))
		printf("�ɹ���ջ������Ϊ%d\n", data);
	else
		printf("��ջʧ��,����û�г�ʼ��\n");
}
void pop(LinkStackPtr mystack)  //����poplstack����ջ
{
	ElemType data;
	if (popLStack(mystack, &data))
		printf("�ɹ���ջ������Ϊ%d\n", data);
	else
		printf("��ջʧ��\n");
}
void judge(int a)
{
	if (a)
		printf("��\n");
	else
		printf("����\n");
}