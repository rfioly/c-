#include <bits/stdc++.h>
using namespace std;
#define M 1000
struct user
{
	string name;
	string sex;
	unsigned int age;
	unsigned long long int phone;
}Person[M];//��ϵ�˽ṹ��
struct Addressbooks
{
	struct user persons[M];
	int size;
};//ͨѶ¼�ṹ�����������һ������ϵ�˽ṹ��

int caidan()
{
	int i;
	system("pause");//�����������
	system("cls");//����
		cout<<"Welcome to use!Tips:not more than 1000 users!"<<endl;
		cout<<"****************"<<endl;
		cout<<"**1.�����ϵ��**"<<endl;
		cout<<"**2.�鿴ͨѶ¼**"<<endl;
		cout<<"**3.�޸���ϵ��**"<<endl;
		cout<<"**4.������ϵ��**"<<endl;
		cout<<"**5.ɾ����ϵ��**"<<endl;
		cout<<"**0.�˳�����****"<<endl;
		cout<<"****************"<<endl;
		cin>>i;
		if(i>5||i<0)
			return 6;
		return i;
}
void shuru(Addressbooks *addressbook1,int i)
{
		string name;
		string sex;
		unsigned int age;
		unsigned long long int phone;
	cout<<"����������:"<<endl;
	cin>>name;
	addressbook1->persons[i].name=name;
	cout<<"�������Ա�:"<<endl;
	cin>>sex;
	addressbook1->persons[i].sex=sex;
	cout<<"����������:"<<endl;
	cin>>age;
	addressbook1->persons[i].age=age;
	cout<<"������绰:"<<endl;
	cin>>phone;
	addressbook1->persons[i].phone=phone;
}
void add(Addressbooks *addressbook1)
{
	if(addressbook1->size<M)
	{
			cout<<"��ʾ���������Ա��벻ҪΪ������ӡ������䣬�绰�벻ҪΪ0��"<<endl;
			shuru(addressbook1,addressbook1->size);
			addressbook1->size++;
		cout<<"��ӳɹ�"<<endl;	
		return;
	}
	else
	{
		cout<<"���ʧ��"<<endl;
		return;
	}
		
}
void view(Addressbooks *ads)
{
	if(ads->size==0)
	{
		cout<<"����δ�����ϵ��Ŷ~�������ĺ������ǰɣ�"<<endl;		
		return;
	}
	else
	{
		int j;
		for(int i=0;i<ads->size;i++)
		{
			j=i+1;
			cout<<"��ϵ��"<<j<<": ";
			cout<<"������"<<ads->persons[i].name<<"\t";
			cout<<"�Ա�"<<ads->persons[i].sex<<"\t";
			cout<<"���䣺"<<ads->persons[i].age<<"\t";
			cout<<"�绰��"<<ads->persons[i].phone<<endl;
		}
		return;
	}
}
void searchview(Addressbooks *ads,int i)
{
		int j;
		j=i+1;
		cout<<"��ϵ��"<<j<<": ";
		cout<<"������"<<ads->persons[i].name<<"\t";
		cout<<"�Ա�"<<ads->persons[i].sex<<"\t";
		cout<<"���䣺"<<ads->persons[i].age<<"\t";
		cout<<"�绰��"<<ads->persons[i].phone<<endl;
		
		return;
}//��search ��������
void modify(Addressbooks *ads)//�޸�
{
	if(ads->size==0)
	{
		cout<<"����δ�����ϵ��Ŷ~�������ĺ������ǰɣ�"<<endl;
		return;
	}
	else
	{
		int j;
		for(int i=0;i<ads->size;i++)
		{
			j=i+1;
			cout<<"��ϵ�˴���"<<j<<": ";
			cout<<"������"<<ads->persons[i].name<<"\t";
			cout<<"�Ա�"<<ads->persons[i].sex<<"\t";
			cout<<"���䣺"<<ads->persons[i].age<<"\t";
			cout<<"�绰��"<<ads->persons[i].phone<<endl;
			
		}
		cout<<"��ѡ������Ҫ�޸ĵ���ϵ�˴���"<<endl;
		int num;
		cin>>num;
		if(num>ads->size||num<0)
		{
			cout<<"�����������޷��޸ģ�"<<endl;			
			return;
		}
		if(num>0&&num<=ads->size)
		{
			num-=1;
			if(ads->size<M)
			{
					
				shuru(ads,num);
				cout<<"�޸ĳɹ���"<<endl;
				view(ads);		
				return;
			}
		}
	}
}
void del(Addressbooks *ads)
{	
	if(ads->size<=0)
		{
			cout<<"����δ�����ϵ��Ŷ~��ȥ�����������ǰɣ�"<<endl;
			return;
		}
		int i;
		cout<<"����������Ҫɾ������ϵ�˴���"<<endl;
		view(ads);
		cin>>i;
		i--;
		if(i>=0&&i<ads->size)
		{
			//do
			ads->persons[i].name="�����";
			ads->persons[i].age=0;
			ads->persons[i].sex="�����";
			ads->persons[i].phone=0;
			cout<<"ɾ���ɹ���"<<endl;
			view(ads);
			return;
		}
		else
		{
			cout<<"�������������������룡"<<endl;		
						return;
		}
}
void sousuo(int biaoji,int sum)//�ܽ�����Ŀ��
{
	if(biaoji==1)
		cout<<"���������ɹ�����������"<<sum<<"��Ŀ�꣡"	<<endl;	
	else
		cout<<"����ʧ�ܣ������ԣ�"<<endl;		
	return;
}
void search(Addressbooks *ads)
{
	int i,biaoji,sum;
		string name;
		string sex;
		unsigned int age;
		unsigned long long int phone;
	biaoji=0;
	sum=0;
	if(ads->size<=0)
	{
		cout<<"����δ�����ϵ��Ŷ~��ȥ�����������ǰɣ�"<<endl;		
		return;
	}
	cout<<"��������Ҫ����������"<<endl;
	cout<<"����1��������"<<endl;
	cout<<"����2�����Ա�"<<endl;
	cout<<"����3��������"<<endl;
	cout<<"����4�����绰"<<endl;
	cin>>i;
	if(i>0&&i<=4)
	{
		if(i==1)
		{
			cin>>name;	
			for(int j=0;j<ads->size&&j<1000;j++)
			{
				if(ads->persons[j].name==name&&name!="�����")
				{
					cout<<"�����ɹ���"<<endl;
					searchview(ads,j);
					biaoji=1;
					sum++;
				}
			}
			sousuo(biaoji,sum);
			return;
		}
		if(i==3&&age!=0)
		{
			cin>>age;
			for(int j=0;j<ads->size&&j<1000;j++)
			{
				if(ads->persons[j].age==age)
				{
					cout<<"�����ɹ���"<<endl;
					searchview(ads,j);
					biaoji=1;
					sum++;
				}
			}
			sousuo(biaoji,sum);
			return;
		}
		if(i==2&&sex!="�����")
		{
			cin>>sex;
			for(int j=0;j<ads->size&&j<1000;j++)
			{
				if(ads->persons[j].sex==sex)
				{
					cout<<"�����ɹ���"<<endl;
					searchview(ads,j);
					biaoji=1;
					sum++;
				}
				
			}
			sousuo(biaoji,sum);
			return;
		}
		if(i==4&&phone!=0)
		{
			cin>>phone;
			for(int j=0;j<ads->size&&j<1000;j++)
			{
				if(ads->persons[j].phone==phone)
				{
					cout<<"�����ɹ���"<<endl;
					searchview(ads,j);
					biaoji=1;
					sum++;
				}
			}
			sousuo(biaoji,sum);
			return;
		}
	}
	else
	{
		cout<<"������������"<<endl;		
		return;
	}	
	return;
}
int main()
{
	int i=0;
	int flag=1;
	Addressbooks addressbook;
	addressbook.size=0;
	//Ŀ¼
	while(1)
	{
		i=caidan();
		switch(i)
		{
			case 1:add(&addressbook);break;
			case 2:view(&addressbook);break;
			case 3:modify(&addressbook);break;
			case 4:search(&addressbook);break;
			case 5:del(&addressbook);break;
			case 0:flag=0;break;
			default:cout<<"wrong number,please repeat"<<endl;break;
		}
		if(flag==0)
			break;
	}
	cout<<"thank you for your using"<<endl;
	return 0;
}
