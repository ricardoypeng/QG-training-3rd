/***************************************************************************************
 *    File Name                :    AQueue.cpp
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
//#ifndef AQUEUE_H_INCLUDED
//#define AQUEUE_H_INCLUDED
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "AQueue.h" 
using namespace std;

/**************************************************************
 *    Macro Define Section
 **************************************************************/
//#define MAXQUEUE 10

/**************************************************************
 *    Struct Define Section
 **************************************************************/
//ѭ�����нṹ
/*typedef struct Aqueue
{
    void *data[MAXQUEUE];      //������
    int front;
    int rear;
    size_t length[MAXQUEUE];        //���г���
    bool CSH; //�Ƿ��Ѿ���ʼ�� 0���� 1�� 
} AQueue;

typedef enum
{
    FALSE=0, TRUE=1
} Status;
char type;
char datatype[MAXQUEUE];*/
/**************************************************************
 *    Prototype Declare Section
 **************************************************************/

/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q)
{
	for (int i = 0; i < MAXQUEUE; i++)
	{
		Q->data[i] = (void *)malloc(20);
		Q->length[i] = 0;
	}
	Q->front = 0;
	Q->rear = 0;
	Q->CSH = 1;
	return;
}


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q)
{
	if (!Q->CSH)//δ��ʼ�� 
		return;
	for(int i = 0; i < MAXQUEUE; i++)
	{
		free(Q->data[i]);
		Q->length[i] = 0;
	}
	Q->CSH = 0;
	return;
}



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : �������Ƿ�����
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q)
{
	if(Q->front==(Q->rear+1)%MAXQUEUE)
	{
		return TRUE;
	}	
	return FALSE;
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q)
{
	if(Q->front==Q->rear)
	{
		return TRUE;
	}	
	return FALSE;
}


/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q ����ָ��Q�����Ԫ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadAQueue(AQueue *Q, void *e)
{
	if (IsEmptyAQueue(Q))
		return FALSE;
	int i = Q->front; 
	i = (i + 1) % MAXQUEUE;
	memcpy(e, Q->data[i], Q->length[i]);
	return TRUE;
}		



/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : ���г���count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q)
{
	return (Q->rear - Q->front + MAXQUEUE) % MAXQUEUE;
}	



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ����˻�Ϊ��
 */
Status EnAQueue(AQueue *Q, void *data)
{
	if (IsFullAQueue(Q)) 
		return FALSE;
	Q->rear = (Q->rear+1) % MAXQUEUE;
	memcpy(Q->data[Q->rear], data, Q->length[Q->rear]);
	return TRUE;

}	



/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q)
{
	if (Q->front == Q->rear)
		return FALSE;
	Q->front = (Q->front + 1) % MAXQUEUE;
	return TRUE;
}		



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q)
{
	Q->front = 0;
	Q->rear = 0;
	return;
}	



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
{
	if (Q->front == Q->rear)
		return FALSE;
	int i = Q->front + 1;
	while (i <= (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE ) 
	{
		foo(Q->data[i]);	
		i = (i + 1) % MAXQUEUE;
	}
	printf("\n");
	return TRUE;
}	



/**
 *  @name        : void APrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
 *  @notice      : None
 */
void APrint(void *q, int typeData)
{
        if(typeData == 4)
            cout<<*(int *)q<<endl;
        if(typeData == 1)
            cout<<*(char *)q<<endl;
        if(typeData == 8)
            cout<<*(double *)q<<endl;
        if(typeData == 10)
            printf("%s\n",q);
        return;
}


/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
//#endif // AQUEUE_H_INCLUDED


