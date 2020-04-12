#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "LQueue.h"
#include "SHURU1.h"
#include "ERROR.h"
using namespace std;
int main()
{
	Lqueue queue, *Q = &queue;//s=top
	int temp, d;
	Node *gg;
	bool dd = 0, first = 0, first_ = 0;//dd 0正常 1异常跳出 first 是否第一次运行（用于初始化 
	void *e; 
	do
	{
		if (first == 0)
		{
			Q->CSH = 0;
			first++;
		}
		dd=0;
		system("cls");
		cout<<"┌────────────────────────────────────┐"<<endl; 
		cout<<"│         链式存储的泛型队列         │"<<endl;
		cout<<"│────────────────────────────────────│"<<endl;
		cout<<"│        菜单(输入数字以继续)        │"<<endl;
		cout<<"├────────────────────────────────────┤"<<endl; 
		cout<<"│1.初始化队列────────────────────────│"<<endl;
		cout<<"├────────────────────────────────────┤"<<endl; 
		cout<<"│2.单个入队──────────────────────────│"<<endl;
		cout<<"├────────────────────────────────────┤"<<endl; 
		cout<<"│3.多个入队──────────────────────────│"<<endl;
		cout<<"├────────────────────────────────────┤"<<endl;
		cout<<"│4.单个出队──────────────────────────│"<<endl;
		cout<<"├────────────────────────────────────┤"<<endl;
		cout<<"│5.多个出队──────────────────────────│"<<endl;
		cout<<"├────────────────────────────────────┤"<<endl;
		cout<<"│6.单个显示──────────────────────────│"<<endl;
		cout<<"├────────────────────────────────────┤"<<endl;
		cout<<"│7.多个显示──────────────────────────│"<<endl;
		cout<<"├────────────────────────────────────┤"<<endl;
		cout<<"│8.队空与否──────────────────────────│"<<endl;
		cout<<"├────────────────────────────────────┤"<<endl;
		cout<<"│9.队你空了──────────────────────────│"<<endl;
		cout<<"├────────────────────────────────────┤"<<endl;
		cout<<"│10.队你没了─────────────────────────│"<<endl;
		cout<<"├────────────────────────────────────┤"<<endl;
		cout<<"│11.退出程序─────────────────────────│"<<endl;
		cout<<"└────────────────────────────────────┘"<<endl; 
		if (SHURU(&d))//检测输入是否合法 
		{
			error_();
			dd = 1;
		}
		if (dd == 1)//出错 重新开始 
			continue;
		if (d == 11)
		{
			break;
		}
		switch (d)
		{
			case 1 ://初始化 
			{
				if (Q->CSH)
				{
					DestoryLQueue(Q);
				}	
				InitLQueue(Q); 
				cout<<"初始化完毕"<<endl; 
				system("PAUSE");
				break;
			}
								
			case 2 ://单个入队
			{
				dd = 0; 
				system("cls");
				if (!Q->CSH)
				{
					cout<<"你都没队列，还入个泡泡茶壶啦！"<<endl; 
					dd = 1;
					system("pause");
					break;
				}
				cout<<"现在的队列有"<<LengthLQueue(Q)<<"个元素"<<endl;
				cout<<"请输入要入队的入队哪种类型？"<<endl;
			    cout<<"1. 整型(绝对值小于1e9) 2. 字符型 3. 浮点型(精确到小数点后2位) 4. 字符串"<<endl;
			    if (SHURU(&d) || d < 1 || d > 4)//检测输入是否合法 
				{	
					error_();
					dd = 1;
					break;
				}
				if (dd == 1) 
				{
					break;
				}
			    switch (d)
			    {
			     	case 1 :
			     	{
						int a1;
						cout<<"请输入你要输入的数据"<<endl; 
						if (SHURU(&a1) || d < 1 || d > 4)//检测输入是否合法 
						{	
							error_();
							dd = 1;
							break;
						}
						if (dd == 1) 
						{
							break;
						}
						if (!EnLQueue(Q, &a1, 4))
						{
							cout<<"输入大失败！！！！"<<endl;
							dd = 1;
							system("pause");
							break;
						}
						if (dd == 1) 
						{
							break;
						}
						cout<<"输入大成功！"<<endl<<endl;
						break;
					}
						
					case 2 : 
					{
						char a2;
						cout<<"请输入你要输入的数据"<<endl; 
						cin>>a2;
						if (!EnLQueue(Q, &a2, 1))
						{
							cout<<"输入大失败！！！！"<<endl;
							dd=1;
							system("pause");
							break;
						}
						if (dd == 1) 
						{
							break;
						}
						cout<<"输入大成功！"<<endl<<endl;
						break;
					}
			        case 3:
			        {
						double a3;
						cout<<"请输入你要输入的数据"<<endl; 
						cin>>a3;
						if (!EnLQueue(Q, &a3, 8))
						{
							cout<<"输入大失败！！！！"<<endl;
							dd = 1;
							system("pause");
							break;
						}
						if (dd == 1) 
						{
							break;
						}
						cout<<"输入大成功！"<<endl<<endl;
						break;
					}
					
			        case 4 : 
			        {
						char a4[51];
						cout<<"请输入你要输入的数据"<<endl; 
						cout<<"字符串最多50个字符"<<endl;
						cin>>a4;
						if (!EnLQueue(Q, &a4, 10))
						{
							cout<<"输入大失败！！！！"<<endl;
							dd = 1;
							system("pause");
							break;
						}
						if (dd == 1) 
						{
							break;
						}
						cout<<"输入大成功！"<<endl<<endl;
						break;	
					}
				}
				if (dd == 1) 
				{
					break;
				}
				system("pause");
				break;	
			}
							
			case 3 ://多个入队 
				dd = 0; 
				system("cls");
				if (!Q->CSH)
				{
					cout<<"你都没队列，还入个泡泡茶壶啦！"<<endl; 
					dd = 1;
					system("pause");
					break;
				}
				cout<<"现在的队列有"<<LengthLQueue(Q)<<"个元素"<<endl;
				cout<<"请输入要入队的入队元素的数量？"<<endl;
				if (SHURU(&temp) || temp < 1)//检测输入是否合法 
				{	
					error_();
					dd = 1;
					break;
				}
				if (dd == 1) 
				{
					break;
				}
				for (int i=1; i<=temp; i++)
				{
					cout<<"请输入要入队的入队哪种类型？"<<endl;
				    cout<<"1. 整型(绝对值小于1e9) 2. 字符型 3. 浮点型(精确到小数点后2位) 4. 字符串"<<endl;
				    if (SHURU(&d) || d < 1 || d > 4)//检测输入是否合法 
					{	
						error_();
						i--;
						continue;
					}
					cout<<"请输入你要输入的数据"<<endl; 
				    switch (d)
				    {
				     	case 1 :
				     	{
							int a1;
							cout<<"请输入你要输入的数据"<<endl; 
							if (SHURU(&a1) || d < 1 || d > 4)//检测输入是否合法 
							{	
								error_();
								dd = 1;
								break;
							}
							if (dd == 1) 
							{
								break;
							}
							if (!EnLQueue(Q, &a1, 4))
							{
								cout<<"输入大失败！！！！"<<endl;
								dd = 1;
								system("pause");
								break;
							}
							if (dd == 1) 
							{
								break;
							}
							cout<<"输入大成功！"<<endl<<endl;
							break;
						}
							
						case 2 : 
						{
							char a2;
							cout<<"请输入你要输入的数据"<<endl; 
							cin>>a2;
							if (!EnLQueue(Q, &a2, 1))
							{
								cout<<"输入大失败！！！！"<<endl;
								dd=1;
								system("pause");
								break;
							}
							if (dd == 1) 
							{
								break;
							}
							cout<<"输入大成功！"<<endl<<endl;
							break;
						}
				        case 3:
				        {
							double a3;
							cout<<"请输入你要输入的数据"<<endl; 
							cin>>a3;
							if (!EnLQueue(Q, &a3, 8))
							{
								cout<<"输入大失败！！！！"<<endl;
								dd = 1;
								system("pause");
								break;
							}
							if (dd == 1) 
							{
								break;
							}
							cout<<"输入大成功！"<<endl<<endl;
							break;
						}
						
				        case 4 : 
				        {
							char a4[51];
							cout<<"请输入你要输入的数据"<<endl; 
							cout<<"字符串最多50个字符"<<endl;
							cin>>a4;
							if (!EnLQueue(Q, &a4, 10))
							{
								cout<<"输入大失败！！！！"<<endl;
								dd = 1;
								system("pause");
								break;
							}
							if (dd == 1) 
							{
								break;
							}
							cout<<"输入大成功！"<<endl<<endl;
							break;	
						}	
							
						default :
						{
							error_();
							dd = 1;
							break;
						} 	
					}
					if (dd == 1) 
					{
						i--;
						continue;
					}
				}
				cout<<endl<<"入队完毕"<<endl; 
				system("pause");
				break;
								
			case 4 ://单个出队 
			{
				if (Q->CSH == 0)
				{
					cout<<"你都没队，还出个泡泡茶壶啦！"<<endl; 
					system("pause");
					break;
				}
				if (IsEmptyLQueue(Q))
				{
					cout<<"队列是空的呢"<<endl;
					system("PAUSE"); 
					break;
				}
				cout<<"被出队的是：";
				gg = Q->front->next;
				LPrint(gg->data, gg->length);
				DeLQueue(Q);	
				system("PAUSE"); 
				break;
			}
			case 5 ://多个出队
			{
				dd=0;
				if (Q->CSH == 0)
				{
					cout<<"你都没队，还出个泡泡茶壶啦！"<<endl; 
					system("pause");
					break;
				}
				if (IsEmptyLQueue(Q))
				{
					cout<<"队列是空的呢"<<endl;
					system("PAUSE"); 
					break;
				}
				cout<<"输入有多少个元素要出队（从队头开始出）最多可输入"<<LengthLQueue(Q)<<"个元素"<<endl;
				if (SHURU(&temp) || temp < 1 || temp > LengthLQueue(Q))//检测输入是否合法 
				{	
					error_();
					dd = 1;
					break;
				}
				if (dd == 1) 
				{
					break;
				}
				gg = Q->front;
				for (int i = 1; i <= temp; i++)
				{
					cout<<"被出队的是：";
					gg = gg->next;
					LPrint(gg->data, gg->length);
					DeLQueue(Q);
				}
				cout<<endl<<"出队完毕"<<endl; 
				system("PAUSE");
				break;
			}
			case 6 ://单个显示
			{
				dd=0;
				if (Q->CSH == 0)
				{
					cout<<"你都没队，还显示个泡泡茶壶啦！"<<endl; 
					system("pause");
					break;
				}
				if (IsEmptyLQueue(Q))
				{
					cout<<"队列是空的呢"<<endl;
					system("PAUSE"); 
					break;
				}
				GetHeadLQueue(Q, &e);
				if (dd == 1)
				{
					break;
				}
				cout<<"队头元素是";
				LPrint(Q->front->next->data, Q->front->next->length);
				system("PAUSE");
				break;
			}
				
			case 7 : //多个显示 
			{
				dd=0; 
				if (Q->CSH == 0)
				{
					cout<<"你都没队，还显示个泡泡茶壶啦！"<<endl; 
					system("pause");
					break;
				}
				if (IsEmptyLQueue(Q))
				{
					cout<<"队列是空的呢"<<endl;
					system("PAUSE"); 
					break;
				}
				cout<<"输入要显示多少个元素（从队头开始输出）最多可输出"<<LengthLQueue(Q)<<"个元素"<<endl;
				while (SHURU(&temp) || temp < 1 || temp > LengthLQueue(Q))
				{
					error_();
					dd = 1;
					break;
				} 
				if (dd == 1)
				{
					break;	
				}
				gg = Q->front;
				cout<<endl;
				for (int i = 1; i <= temp; i++)
				{
					gg = gg->next;
					LPrint(gg->data, gg->length);
				}
				cout<<endl;
				system("PAUSE");
				break; 
			}
			case 8 ://检测队空与否 
			{
				if (Q->CSH == 0)
				{
					cout<<"你都没队列，还空个泡泡茶壶啦！" <<endl;
					system("pause");
					break; 
				}
				if (IsEmptyLQueue(Q))
				{
					cout<<"队是空的呢"<<endl; 
					system("PAUSE");
					break;
				}
				cout<<"队不是空的呢"<<endl;
				system("PAUSE");
				break;
			}
			case 9 : //你队空了 	
			{		
				if (Q->CSH == 0)
				{
					cout<<"你都没队，还空个泡泡茶壶啦！" <<endl;
					system("pause");
					break; 
				}
				if (IsEmptyLQueue(Q))
				{
					cout<<"队是空的呢"<<endl; 
					system("pause");
					break;
				}
				ClearLQueue(Q);
				cout<<"队已经空了呢！！！"<<endl;
				system("pause");
				break;	
			}
				
			case 10 ://你队没了
			{
				if (Q->CSH == 1)
				{
					cout<<"你队没了" <<endl; 
					DestoryLQueue(Q);
					system("pause");
					break; 
				}
				else
				{
					cout<<"你都没队，还销毁个泡泡茶壶啦！"<<endl;
					system("pause");
					break; 
				} 
			}
			
			default : 
			{
				error_();
				break;
			}
				
		}
		
	}while (1);
	if (Q->CSH == 1)
	{
		DestoryLQueue(Q);
	}
	system("pause");
	return 0;
}
