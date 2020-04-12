/***************************************************************************************
 *    File Name                :    LQueue.cpp
 *    CopyRight                :	RicardoY.Peng
 *
 *    SYSTEM                    :   Windows 10
 *    Create Data                :    2020.4.12
 *    Author/Corportation        :   RicardoY.Peng
 *
 *
 *--------------------------------Revision History--------------------------------------
 *    No    version        Data            Revised By            Item            Description
 *
 *
 ***************************************************************************************/

/**************************************************************
 *    Multi-Include-Prevent Section
 **************************************************************/
//#ifndef LQUEUE_H_INCLUDED
//#define LQUEUE_H_INCLUDED
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "LQueue.h" 
using namespace std;

/**************************************************************
 *    Struct Define Section
 **************************************************************/
//链式队列结构
/*
typedef struct node
{
    void *data;   					//数据域指针
	size_t length;                
    struct node *next;            //指向当前结点的下一结点
} Node;

typedef struct Lqueue
{
    Node *front;                   //队头
    Node *rear;                    //队尾
    size_t length;            //队列长度
} LQueue;

typedef enum
{
    FALSE=0, TRUE=1
} Status;*/
		

/**************************************************************
 *    Prototype Declare Section
 **************************************************************/


/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q)
{
	Node *p = (Node *)malloc(sizeof(Node));
	if (NULL == p)
	{
		return;
	}
	Q->CSH = 1;
	p->length = 0;
	p->next = NULL;
	Q->front = p;
	Q->rear = p;
	return;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q)
{
	if (IsEmptyLQueue(Q))
	{
		return; 
	}	
	ClearLQueue(Q);
	Q->CSH = 0;
	Node *p,*pp;
	p = Q->front->next;
	free(Q->front);
	do
	{
		pp = p;
		p = p->next;
		free(pp);
	}while(p != NULL);
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q)
{
	if(Q->front==Q->rear)
	{
		return TRUE;
	}	
	return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void *e)
{
	if (IsEmptyLQueue(Q))
	{
		return FALSE;
	}	
	e = Q->front->next->data;
	return TRUE;
} 

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q)
{
	int length;
	Node *p = (Node *)malloc(sizeof(Node));
	p = Q->front;
	for (length = 0; p != Q->rear; length++)
	{
		p = p->next;
	} 
	return length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data, int typeData)
{	
	int t = typeData;
	if (t == 10)//10作为string类型的识别数 实际上字节数为8 
	{
		t = 8;
	}
	Node *p = (Node *)malloc(sizeof(Node));
	if (p == NULL)
	{
		return FALSE;
	}
	p->data = (void *)malloc(t);
	p->data = data;
	p->length = typeData;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return TRUE;
} 

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q)
{
	if (IsEmptyLQueue(Q))
	{
		return FALSE;
	}
	Node *p, *q;
	p = Q->front;
	q = p->next;
	free(p);
	Q->front = q;
	return TRUE;
} 

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q)
{
	if (IsEmptyLQueue(Q))
	{
		return;
	}
	Node *p, *q;
	Q->rear = Q->front;
	p = Q->front->next; 
	while (p != NULL) 
	{
		q = p;
		p = p->next;
		free(q);
	}
	free(p);
	return;
} 

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q, int typeData))
{
	if (IsEmptyLQueue(Q))
	{
		return FALSE;
	}	
	Node* p = (Node *)malloc(40); 
	p = Q->front->next; 
	int i = 1;
	while (p != NULL)
	{
		if (i % 5 == 0)
		{
			printf("\n"); 
		}
		foo(p->data, p->length);
		p = p->next;
		i++;
	}
	printf("\n");
	return TRUE;
} 

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 
 *  @notice      : None
 */
void LPrint(void *q, int typeData)
{
	if(typeData == 4)
	{
		cout<<*(int *)q<<endl;
	}
    if(typeData == 1)
    {
    	cout<<*(char *)q<<endl;
	}  
    if(typeData == 8)
    {
    	cout<<*(double *)q<<endl;
	}
    if(typeData == 10)
    {
    	printf("%s\n",q);
	}
    return;
} 

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
//#endif // LQUEUE_H_INCLUDED


