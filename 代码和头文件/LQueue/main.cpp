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
	bool dd = 0, first = 0, first_ = 0;//dd 0���� 1�쳣���� first �Ƿ��һ�����У����ڳ�ʼ�� 
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
		cout<<"����������������������������������������������������������������������������"<<endl; 
		cout<<"��         ��ʽ�洢�ķ��Ͷ���         ��"<<endl;
		cout<<"����������������������������������������������������������������������������"<<endl;
		cout<<"��        �˵�(���������Լ���)        ��"<<endl;
		cout<<"����������������������������������������������������������������������������"<<endl; 
		cout<<"��1.��ʼ�����Щ�������������������������������������������������"<<endl;
		cout<<"����������������������������������������������������������������������������"<<endl; 
		cout<<"��2.������ө�����������������������������������������������������"<<endl;
		cout<<"����������������������������������������������������������������������������"<<endl; 
		cout<<"��3.�����ө�����������������������������������������������������"<<endl;
		cout<<"����������������������������������������������������������������������������"<<endl;
		cout<<"��4.�������ө�����������������������������������������������������"<<endl;
		cout<<"����������������������������������������������������������������������������"<<endl;
		cout<<"��5.������ө�����������������������������������������������������"<<endl;
		cout<<"����������������������������������������������������������������������������"<<endl;
		cout<<"��6.������ʾ������������������������������������������������������"<<endl;
		cout<<"����������������������������������������������������������������������������"<<endl;
		cout<<"��7.�����ʾ������������������������������������������������������"<<endl;
		cout<<"����������������������������������������������������������������������������"<<endl;
		cout<<"��8.�ӿ���񩤩���������������������������������������������������"<<endl;
		cout<<"����������������������������������������������������������������������������"<<endl;
		cout<<"��9.������˩�����������������������������������������������������"<<endl;
		cout<<"����������������������������������������������������������������������������"<<endl;
		cout<<"��10.����û�˩���������������������������������������������������"<<endl;
		cout<<"����������������������������������������������������������������������������"<<endl;
		cout<<"��11.�˳����򩤩�������������������������������������������������"<<endl;
		cout<<"����������������������������������������������������������������������������"<<endl; 
		if (SHURU(&d))//��������Ƿ�Ϸ� 
		{
			error_();
			dd = 1;
		}
		if (dd == 1)//���� ���¿�ʼ 
			continue;
		if (d == 11)
		{
			break;
		}
		switch (d)
		{
			case 1 ://��ʼ�� 
			{
				if (Q->CSH)
				{
					DestoryLQueue(Q);
				}	
				InitLQueue(Q); 
				cout<<"��ʼ�����"<<endl; 
				system("PAUSE");
				break;
			}
								
			case 2 ://�������
			{
				dd = 0; 
				system("cls");
				if (!Q->CSH)
				{
					cout<<"�㶼û���У���������ݲ������"<<endl; 
					dd = 1;
					system("pause");
					break;
				}
				cout<<"���ڵĶ�����"<<LengthLQueue(Q)<<"��Ԫ��"<<endl;
				cout<<"������Ҫ��ӵ�����������ͣ�"<<endl;
			    cout<<"1. ����(����ֵС��1e9) 2. �ַ��� 3. ������(��ȷ��С�����2λ) 4. �ַ���"<<endl;
			    if (SHURU(&d) || d < 1 || d > 4)//��������Ƿ�Ϸ� 
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
						cout<<"��������Ҫ���������"<<endl; 
						if (SHURU(&a1) || d < 1 || d > 4)//��������Ƿ�Ϸ� 
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
							cout<<"�����ʧ�ܣ�������"<<endl;
							dd = 1;
							system("pause");
							break;
						}
						if (dd == 1) 
						{
							break;
						}
						cout<<"�����ɹ���"<<endl<<endl;
						break;
					}
						
					case 2 : 
					{
						char a2;
						cout<<"��������Ҫ���������"<<endl; 
						cin>>a2;
						if (!EnLQueue(Q, &a2, 1))
						{
							cout<<"�����ʧ�ܣ�������"<<endl;
							dd=1;
							system("pause");
							break;
						}
						if (dd == 1) 
						{
							break;
						}
						cout<<"�����ɹ���"<<endl<<endl;
						break;
					}
			        case 3:
			        {
						double a3;
						cout<<"��������Ҫ���������"<<endl; 
						cin>>a3;
						if (!EnLQueue(Q, &a3, 8))
						{
							cout<<"�����ʧ�ܣ�������"<<endl;
							dd = 1;
							system("pause");
							break;
						}
						if (dd == 1) 
						{
							break;
						}
						cout<<"�����ɹ���"<<endl<<endl;
						break;
					}
					
			        case 4 : 
			        {
						char a4[51];
						cout<<"��������Ҫ���������"<<endl; 
						cout<<"�ַ������50���ַ�"<<endl;
						cin>>a4;
						if (!EnLQueue(Q, &a4, 10))
						{
							cout<<"�����ʧ�ܣ�������"<<endl;
							dd = 1;
							system("pause");
							break;
						}
						if (dd == 1) 
						{
							break;
						}
						cout<<"�����ɹ���"<<endl<<endl;
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
							
			case 3 ://������ 
				dd = 0; 
				system("cls");
				if (!Q->CSH)
				{
					cout<<"�㶼û���У���������ݲ������"<<endl; 
					dd = 1;
					system("pause");
					break;
				}
				cout<<"���ڵĶ�����"<<LengthLQueue(Q)<<"��Ԫ��"<<endl;
				cout<<"������Ҫ��ӵ����Ԫ�ص�������"<<endl;
				if (SHURU(&temp) || temp < 1)//��������Ƿ�Ϸ� 
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
					cout<<"������Ҫ��ӵ�����������ͣ�"<<endl;
				    cout<<"1. ����(����ֵС��1e9) 2. �ַ��� 3. ������(��ȷ��С�����2λ) 4. �ַ���"<<endl;
				    if (SHURU(&d) || d < 1 || d > 4)//��������Ƿ�Ϸ� 
					{	
						error_();
						i--;
						continue;
					}
					cout<<"��������Ҫ���������"<<endl; 
				    switch (d)
				    {
				     	case 1 :
				     	{
							int a1;
							cout<<"��������Ҫ���������"<<endl; 
							if (SHURU(&a1) || d < 1 || d > 4)//��������Ƿ�Ϸ� 
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
								cout<<"�����ʧ�ܣ�������"<<endl;
								dd = 1;
								system("pause");
								break;
							}
							if (dd == 1) 
							{
								break;
							}
							cout<<"�����ɹ���"<<endl<<endl;
							break;
						}
							
						case 2 : 
						{
							char a2;
							cout<<"��������Ҫ���������"<<endl; 
							cin>>a2;
							if (!EnLQueue(Q, &a2, 1))
							{
								cout<<"�����ʧ�ܣ�������"<<endl;
								dd=1;
								system("pause");
								break;
							}
							if (dd == 1) 
							{
								break;
							}
							cout<<"�����ɹ���"<<endl<<endl;
							break;
						}
				        case 3:
				        {
							double a3;
							cout<<"��������Ҫ���������"<<endl; 
							cin>>a3;
							if (!EnLQueue(Q, &a3, 8))
							{
								cout<<"�����ʧ�ܣ�������"<<endl;
								dd = 1;
								system("pause");
								break;
							}
							if (dd == 1) 
							{
								break;
							}
							cout<<"�����ɹ���"<<endl<<endl;
							break;
						}
						
				        case 4 : 
				        {
							char a4[51];
							cout<<"��������Ҫ���������"<<endl; 
							cout<<"�ַ������50���ַ�"<<endl;
							cin>>a4;
							if (!EnLQueue(Q, &a4, 10))
							{
								cout<<"�����ʧ�ܣ�������"<<endl;
								dd = 1;
								system("pause");
								break;
							}
							if (dd == 1) 
							{
								break;
							}
							cout<<"�����ɹ���"<<endl<<endl;
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
				cout<<endl<<"������"<<endl; 
				system("pause");
				break;
								
			case 4 ://�������� 
			{
				if (Q->CSH == 0)
				{
					cout<<"�㶼û�ӣ����������ݲ������"<<endl; 
					system("pause");
					break;
				}
				if (IsEmptyLQueue(Q))
				{
					cout<<"�����ǿյ���"<<endl;
					system("PAUSE"); 
					break;
				}
				cout<<"�����ӵ��ǣ�";
				gg = Q->front->next;
				LPrint(gg->data, gg->length);
				DeLQueue(Q);	
				system("PAUSE"); 
				break;
			}
			case 5 ://�������
			{
				dd=0;
				if (Q->CSH == 0)
				{
					cout<<"�㶼û�ӣ����������ݲ������"<<endl; 
					system("pause");
					break;
				}
				if (IsEmptyLQueue(Q))
				{
					cout<<"�����ǿյ���"<<endl;
					system("PAUSE"); 
					break;
				}
				cout<<"�����ж��ٸ�Ԫ��Ҫ���ӣ��Ӷ�ͷ��ʼ������������"<<LengthLQueue(Q)<<"��Ԫ��"<<endl;
				if (SHURU(&temp) || temp < 1 || temp > LengthLQueue(Q))//��������Ƿ�Ϸ� 
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
					cout<<"�����ӵ��ǣ�";
					gg = gg->next;
					LPrint(gg->data, gg->length);
					DeLQueue(Q);
				}
				cout<<endl<<"�������"<<endl; 
				system("PAUSE");
				break;
			}
			case 6 ://������ʾ
			{
				dd=0;
				if (Q->CSH == 0)
				{
					cout<<"�㶼û�ӣ�����ʾ�����ݲ������"<<endl; 
					system("pause");
					break;
				}
				if (IsEmptyLQueue(Q))
				{
					cout<<"�����ǿյ���"<<endl;
					system("PAUSE"); 
					break;
				}
				GetHeadLQueue(Q, &e);
				if (dd == 1)
				{
					break;
				}
				cout<<"��ͷԪ����";
				LPrint(Q->front->next->data, Q->front->next->length);
				system("PAUSE");
				break;
			}
				
			case 7 : //�����ʾ 
			{
				dd=0; 
				if (Q->CSH == 0)
				{
					cout<<"�㶼û�ӣ�����ʾ�����ݲ������"<<endl; 
					system("pause");
					break;
				}
				if (IsEmptyLQueue(Q))
				{
					cout<<"�����ǿյ���"<<endl;
					system("PAUSE"); 
					break;
				}
				cout<<"����Ҫ��ʾ���ٸ�Ԫ�أ��Ӷ�ͷ��ʼ������������"<<LengthLQueue(Q)<<"��Ԫ��"<<endl;
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
			case 8 ://���ӿ���� 
			{
				if (Q->CSH == 0)
				{
					cout<<"�㶼û���У����ո����ݲ������" <<endl;
					system("pause");
					break; 
				}
				if (IsEmptyLQueue(Q))
				{
					cout<<"���ǿյ���"<<endl; 
					system("PAUSE");
					break;
				}
				cout<<"�Ӳ��ǿյ���"<<endl;
				system("PAUSE");
				break;
			}
			case 9 : //��ӿ��� 	
			{		
				if (Q->CSH == 0)
				{
					cout<<"�㶼û�ӣ����ո����ݲ������" <<endl;
					system("pause");
					break; 
				}
				if (IsEmptyLQueue(Q))
				{
					cout<<"���ǿյ���"<<endl; 
					system("pause");
					break;
				}
				ClearLQueue(Q);
				cout<<"���Ѿ������أ�����"<<endl;
				system("pause");
				break;	
			}
				
			case 10 ://���û��
			{
				if (Q->CSH == 1)
				{
					cout<<"���û��" <<endl; 
					DestoryLQueue(Q);
					system("pause");
					break; 
				}
				else
				{
					cout<<"�㶼û�ӣ������ٸ����ݲ������"<<endl;
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
