#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "AQueue.h"
#include "SHURU1.h"
#include "ERROR.h"
using namespace std;
int main()
{
	Aqueue queue, *Q = &queue;//s=top
	int temp, d, gg;
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
		cout<<"��         ˳��洢�ķ��Ͷ���         ��"<<endl;
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
		cout<<"��8.������񩤩���������������������������������������������������"<<endl;
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
					DestoryAQueue(Q);
				}	
				InitAQueue(Q); 
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
				if (IsFullAQueue(Q))
				{
					cout<<"�����Ѿ�����ѽ��"<<endl;
					dd = 1;
					system("pause");
					break;
				}
				cout<<"���ڵĶ�����"<<LengthAQueue(Q)<<"��Ԫ��,�������"<<MAXQUEUE - LengthAQueue(Q) - 1<<"��Ԫ��"<<endl;
				cout<<"������Ҫ��ӵ�����������ͣ�"<<endl;
			    cout<<"1. ����(����ֵС��1e9) 2. �ַ��� 3. ������(��ȷ��С�����2λ) 4. �ַ���"<<endl;
			    if (SHURU(&d))//��������Ƿ�Ϸ� 
				{	
					error_();
					dd = 1;
					break;
				}
			    switch (d)
			    {
			     	case 1 :
			     	{
						int a1;
						cout<<"��������Ҫ���������"<<endl;
						if (SHURU(&a1))//��������Ƿ�Ϸ� 
						{	
							error_();
							dd = 1;
							break;
						}
						if (dd == 1) 
						{
							break;
						}
						Q->length[Q->rear + 1] = 4;
						if (!EnAQueue(Q, &a1))
						{
							cout<<"�����Ѿ�����ѽ��"<<endl;
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
						cout<<"��������Ҫ���������"<<endl<<endl;
						cin>>a2;
						Q->length[Q->rear + 1] = 1;
						if (!EnAQueue(Q, &a2))
						{
							cout<<"�����Ѿ�����ѽ��"<<endl;
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
					
			        case 3 :
			        {
						double a3;
						cout<<"��������Ҫ���������"<<endl<<endl;
						cin>>a3;
						Q->length[Q->rear + 1] = 8;
						if (!EnAQueue(Q, &a3))
						{
							cout<<"�����Ѿ�����ѽ��"<<endl;
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
						Q->length[Q->rear + 1] = 10;
						if (!EnAQueue(Q, &a4))
						{
							cout<<"�����Ѿ�����ѽ��"<<endl;
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
					break;
				}
				system("pause");
				break;		
			}
			
			case 3 ://������ 
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
				if (IsFullAQueue(Q))
				{
					cout<<"�����Ѿ�����ѽ��"<<endl;
					dd = 1;
					system("pause");
					break;
				} 
				cout<<"���ڵĶ�����"<<LengthAQueue(Q)<<"��Ԫ��,�������"<<MAXQUEUE - LengthAQueue(Q) - 1<<"��Ԫ��"<<endl;
				cout<<"������Ҫ��ӵ����Ԫ�ص�������"<<endl;
				if (SHURU(&temp) || temp < 1 || temp > MAXQUEUE-LengthAQueue(Q) - 1)//��������Ƿ�Ϸ� 
				{	
					error_();
					dd = 1;
					break;
				}
				for (int i=1; i<=temp; i++)
				{
					cout<<"������Ҫ��ӵ�����������ͣ�"<<endl;
				    cout<<"1. ����(����ֵС��1e9) 2. �ַ��� 3. ������(��ȷ��С�����2λ) 4. �ַ���"<<endl;
				    if (SHURU(&d) || d<1 || d > 4)//��������Ƿ�Ϸ� 
					{	
						error_();
						i--;
						continue;
					}
				    switch (d)
				    {
				     	case 1 :
				     	{
							int a1;
							cout<<"��������Ҫ���������"<<endl;
							if (SHURU(&a1))//��������Ƿ�Ϸ� 
							{	
								error_();
								dd = 1;
								break;
							}
							if (dd == 1) 
							{
								break;
							}
							Q->length[Q->rear + 1] = 4;
							if (!EnAQueue(Q, &a1))
							{
								cout<<"�����Ѿ�����ѽ��"<<endl;
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
							cout<<"��������Ҫ���������"<<endl<<endl;
							cin>>a2;
							Q->length[Q->rear + 1] = 1;
							if (!EnAQueue(Q, &a2))
							{
								cout<<"�����Ѿ�����ѽ��"<<endl;
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
						
				        case 3 :
				        {
							double a3;
							cout<<"��������Ҫ���������"<<endl<<endl;
							cin>>a3;
							Q->length[Q->rear + 1] = 8;
							if (!EnAQueue(Q, &a3))
							{
								cout<<"�����Ѿ�����ѽ��"<<endl;
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
							Q->length[Q->rear + 1] = 10;
							if (!EnAQueue(Q, &a4))
							{
								cout<<"�����Ѿ�����ѽ��"<<endl;
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
						i--;
						continue;
					}
				}
				if (dd == 1) 
				{
					break;
				}
				cout<<endl<<"������"<<endl; 
				system("pause");
				break;
			}
								
			case 4 ://�������� 
			{
				if (Q->CSH == 0)
				{
					cout<<"�㶼û�ӣ����������ݲ������"<<endl; 
					system("pause");
					break;
				}
				if (IsEmptyAQueue(Q))
				{
					cout<<"�����ǿյ���"<<endl;
					system("PAUSE"); 
					break;
				}
				cout<<"�����ӵ��ǣ�";
				APrint(Q->data[(Q->front + 1) % MAXQUEUE], Q->length[(Q->front + 1) % MAXQUEUE]);
				DeAQueue(Q);	
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
				if (IsEmptyAQueue(Q))
				{
					cout<<"�����ǿյ���"<<endl;
					system("PAUSE"); 
					break;
				}
				cout<<"�����ж��ٸ�Ԫ��Ҫ���ӣ��Ӷ�ͷ��ʼ������������"<<LengthAQueue(Q)<<"��Ԫ��"<<endl;
				if (SHURU(&temp) || temp < 1 || temp > LengthAQueue(Q))//��������Ƿ�Ϸ� 
				{	
					error_();
					dd = 1;
					break;
				}
				if (dd == 1) 
				{
					break;
				}
				for (int i = 1; i <= temp; i++)
				{
					cout<<"�����ӵ��ǣ�";
					APrint(Q->data[(Q->front + 1) % MAXQUEUE],Q->length[(Q->front + 1) % MAXQUEUE]);
					DeAQueue(Q);
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
				if (IsEmptyAQueue(Q))
				{
					cout<<"�����ǿյ���"<<endl;
					system("PAUSE"); 
					break;
				}
				GetHeadAQueue(Q, &e);
				if (dd == 1)
				{
					break;
				}
				cout<<"��ͷԪ����";
				APrint(Q->data[(Q->front + 1) % MAXQUEUE],Q->length[(Q->front + 1) % MAXQUEUE]);
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
				if (IsEmptyAQueue(Q))
				{
					cout<<"�����ǿյ���"<<endl;
					system("PAUSE"); 
					break;
				}
				cout<<"����Ҫ��ʾ���ٸ�Ԫ�أ��Ӷ�ͷ��ʼ������������"<<LengthAQueue(Q)<<"��Ԫ��"<<endl;
				while (SHURU(&temp) || temp < 1 || temp > LengthAQueue(Q))
				{
					error_();
					dd = 1;
					break;
				} 
				if (dd == 1)
				{
					break;	
				} 
				gg = Q->front + 1;
				cout<<endl;
				for (int i = 1; i <= temp; i++)
				{
					APrint(Q->data[gg % MAXQUEUE], Q->length[gg % MAXQUEUE]);
					gg = (gg + 1) % MAXQUEUE;
				}
				cout<<endl;
				system("PAUSE");
				break; 
			}
			
			case 8 ://��������� IsFullAQueue IsEmptyAQueue
			{
				if (Q->CSH == 0)
				{
					cout<<"�㶼û���У����ո����ݲ������" <<endl;
					system("pause");
					break; 
				}
				if (IsEmptyAQueue(Q))
				{
					cout<<"���ǿյ���"<<endl; 
					system("PAUSE");
					break;
				}
				if (IsFullAQueue(Q))
				{
					cout<<"����������"<<endl; 
					system("PAUSE");
					break;
				}
				cout<<"�Ӳ��ǿ�Ҳ����������"<<endl;
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
				if (IsEmptyAQueue(Q))
				{
					cout<<"���ǿյ���"<<endl; 
					system("pause");
					break;
				}
				ClearAQueue(Q);
				cout<<"���Ѿ������أ�����"<<endl;
				system("pause");
				break;	
			}
			
			case 10 ://���û��
			{
				if (Q->CSH == 1)
				{
					cout<<"���û��" <<endl; 
					DestoryAQueue(Q);
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
		DestoryAQueue(Q);
	}
	system("pause");
	return 0;
}
