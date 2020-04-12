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
//��ʽ���нṹ
/*
typedef struct node
{
    void *data;   					//������ָ��
	size_t length;                
    struct node *next;            //ָ��ǰ������һ���
} Node;

typedef struct Lqueue
{
    Node *front;                   //��ͷ
    Node *rear;                    //��β
    size_t length;            //���г���
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
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
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
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
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
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
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
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
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
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
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
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data, int typeData)
{	
	int t = typeData;
	if (t == 10)//10��Ϊstring���͵�ʶ���� ʵ�����ֽ���Ϊ8 
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
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
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
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
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
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
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
 *    @description : ��������
 *    @param         q ָ��q
 
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


