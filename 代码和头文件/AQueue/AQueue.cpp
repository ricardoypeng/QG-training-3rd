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
//循环队列结构
/*typedef struct Aqueue
{
    void *data[MAXQUEUE];      //数据域
    int front;
    int rear;
    size_t length[MAXQUEUE];        //队列长度
    bool CSH; //是否已经初始化 0不是 1是 
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
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
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
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q)
{
	if (!Q->CSH)//未初始化 
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
 *    @description : 检查队列是否已满
 *    @param         Q 队列指针Q
 *    @return         : 满-TRUE; 未满-FALSE
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
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
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
 *    @description : 查看队头元素
 *    @param         Q 队列指针Q，存放元素e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
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
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q)
{
	return (Q->rear - Q->front + MAXQUEUE) % MAXQUEUE;
}	



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
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
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
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
 *    @description : 清空队列
 *    @param         Q 队列指针Q
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
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
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
 *    @description : 操作函数
 *    @param         q 指针q
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


