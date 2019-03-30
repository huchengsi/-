#include"../head/LinkStack.h"
#include<stdio.h>
#include<stdlib.h>

//链栈(基于链表的)
Status initLStack(LinkStack *s)   //初始化
{
	s->top= (LinkStackPtr)malloc(sizeof(StackNode));//给top指针分配空间
	if (!s->top)                                    //判断是否成功
		return ERROR;
	s->top = NULL;                                  //类似链表，先初始化指针
	s->count = 0;
	return SUCCESS;

}
Status isEmptyLStack(LinkStack *s)  //判断链栈是否为空
{
	if (s->count == 0)
		return SUCCESS;
	else
		return ERROR;
}
Status getTopLStack(LinkStack *s,ElemType *e)  //得到栈顶元素
{
	*e = s->top->data;
	printf("%d\n",*e);
}
Status clearLStack(LinkStack *s)   //清空栈
{
	if (s->count < 0||s->count==0)
	{
		printf("无法清除空链表或未定义链表\n");
		return ERROR;
	}
	else
	{

		free(s->top);
		initLStack(s);
		printf("清除链表成功\n");
		return SUCCESS;
	}

}
Status destroyLStack(LinkStack *s)   //销毁栈
{
	int clr;
	if (s->count < 0)
	{
		printf("无法销毁未初始化的链表\n");
		return ERROR;
	}
	else
	{
		free(s);
	}
	return SUCCESS;
}
Status LStackLength(LinkStack *s,int *length)    //检测栈长度
{
	if (s->count <= 0)
	{
		printf("空栈或者为定义\n");
		return ERROR;
	}
		
	*length = s->count;
	printf("长度为%d\n", *length);

}
Status pushLStack(LinkStack *s,ElemType data)   //入栈
{
	if (s->top != NULL && s->count < 0)
	{
		return ERROR;
	}
	StackNode *node = (LinkStackPtr)malloc(sizeof(StackNode));//创建新节点
	node->data = data;                
	node->next = s->top;                                     //入栈操作
	s->top = node;                                             //栈顶
	(s->count)++;                  //记录栈长度

}
Status popLStack(LinkStack *s,ElemType *data)   //出栈
{
	if (s->count == 0)
	{
		return ERROR;
		printf("是空栈/n");
	}
	if (s->top != NULL && s->count < 0)
	{
		return ERROR;
	}
   StackNode *topnode = s->top;        //定义一个指向栈顶的指针
   *data = topnode->data;
   s->top = s->top->next;           //栈顶指针下移一位
   free(topnode);                    //释放内存
   (s->count)--;           //记录栈长度
   return SUCCESS;
}


void Init(LinkStackPtr mystack)//调用initlstack初始化栈，未初始化时count居然为负数
{
	if (initLStack(mystack))
		printf("成功初始化链栈\n");
	else
		printf("初始化失败\n");
}

void push(LinkStackPtr mystack)//调用pushlstack入栈
{

	ElemType data;
	printf("请输入数据\n");
	scanf_s("%d",&data);
	if (pushLStack(mystack, data))
		printf("成功入栈，数据为%d\n", data);
	else
		printf("入栈失败,可能没有初始化\n");
}
void pop(LinkStackPtr mystack)  //调用poplstack来出栈
{
	ElemType data;
	if (popLStack(mystack, &data))
		printf("成功出栈，数据为%d\n", data);
	else
		printf("出栈失败\n");
}
void judge(int a)
{
	if (a)
		printf("是\n");
	else
		printf("不是\n");
}