#include <bits/stdc++.h>
using namespace std;
#define M 1000
struct user
{
	string name;
	string sex;
	unsigned int age;
	unsigned long long int phone;
}Person[M];//联系人结构体
struct Addressbooks
{
	struct user persons[M];
	int size;
};//通讯录结构体里面掺杂了一定的联系人结构体

int caidan()
{
	int i;
	system("pause");//按任意键继续
	system("cls");//清屏
		cout<<"Welcome to use!Tips:not more than 1000 users!"<<endl;
		cout<<"****************"<<endl;
		cout<<"**1.添加联系人**"<<endl;
		cout<<"**2.查看通讯录**"<<endl;
		cout<<"**3.修改联系人**"<<endl;
		cout<<"**4.查找联系人**"<<endl;
		cout<<"**5.删除联系人**"<<endl;
		cout<<"**0.退出程序****"<<endl;
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
	cout<<"请输入姓名:"<<endl;
	cin>>name;
	addressbook1->persons[i].name=name;
	cout<<"请输入性别:"<<endl;
	cin>>sex;
	addressbook1->persons[i].sex=sex;
	cout<<"请输入年龄:"<<endl;
	cin>>age;
	addressbook1->persons[i].age=age;
	cout<<"请输入电话:"<<endl;
	cin>>phone;
	addressbook1->persons[i].phone=phone;
}
void add(Addressbooks *addressbook1)
{
	if(addressbook1->size<M)
	{
			cout<<"提示：姓名，性别请不要为“待添加”，年龄，电话请不要为0！"<<endl;
			shuru(addressbook1,addressbook1->size);
			addressbook1->size++;
		cout<<"添加成功"<<endl;	
		return;
	}
	else
	{
		cout<<"添加失败"<<endl;
		return;
	}
		
}
void view(Addressbooks *ads)
{
	if(ads->size==0)
	{
		cout<<"您还未添加联系人哦~快添加你的好朋友们吧！"<<endl;		
		return;
	}
	else
	{
		int j;
		for(int i=0;i<ads->size;i++)
		{
			j=i+1;
			cout<<"联系人"<<j<<": ";
			cout<<"姓名："<<ads->persons[i].name<<"\t";
			cout<<"性别："<<ads->persons[i].sex<<"\t";
			cout<<"年龄："<<ads->persons[i].age<<"\t";
			cout<<"电话："<<ads->persons[i].phone<<endl;
		}
		return;
	}
}
void searchview(Addressbooks *ads,int i)
{
		int j;
		j=i+1;
		cout<<"联系人"<<j<<": ";
		cout<<"姓名："<<ads->persons[i].name<<"\t";
		cout<<"性别："<<ads->persons[i].sex<<"\t";
		cout<<"年龄："<<ads->persons[i].age<<"\t";
		cout<<"电话："<<ads->persons[i].phone<<endl;
		
		return;
}//与search 功能配套
void modify(Addressbooks *ads)//修改
{
	if(ads->size==0)
	{
		cout<<"您还未添加联系人哦~快添加你的好朋友们吧！"<<endl;
		return;
	}
	else
	{
		int j;
		for(int i=0;i<ads->size;i++)
		{
			j=i+1;
			cout<<"联系人代号"<<j<<": ";
			cout<<"姓名："<<ads->persons[i].name<<"\t";
			cout<<"性别："<<ads->persons[i].sex<<"\t";
			cout<<"年龄："<<ads->persons[i].age<<"\t";
			cout<<"电话："<<ads->persons[i].phone<<endl;
			
		}
		cout<<"请选择您需要修改的联系人代号"<<endl;
		int num;
		cin>>num;
		if(num>ads->size||num<0)
		{
			cout<<"您输入有误，无法修改！"<<endl;			
			return;
		}
		if(num>0&&num<=ads->size)
		{
			num-=1;
			if(ads->size<M)
			{
					
				shuru(ads,num);
				cout<<"修改成功！"<<endl;
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
			cout<<"您还未添加联系人哦~快去添加你的朋友们吧！"<<endl;
			return;
		}
		int i;
		cout<<"请输入您需要删除的联系人代号"<<endl;
		view(ads);
		cin>>i;
		i--;
		if(i>=0&&i<ads->size)
		{
			//do
			ads->persons[i].name="待添加";
			ads->persons[i].age=0;
			ads->persons[i].sex="待添加";
			ads->persons[i].phone=0;
			cout<<"删除成功！"<<endl;
			view(ads);
			return;
		}
		else
		{
			cout<<"您输入有误！请重新输入！"<<endl;		
						return;
		}
}
void sousuo(int biaoji,int sum)//总结搜索目标
{
	if(biaoji==1)
		cout<<"本次搜索成功！共检索到"<<sum<<"个目标！"	<<endl;	
	else
		cout<<"搜索失败，请重试！"<<endl;		
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
		cout<<"您还未添加联系人哦~快去添加你的朋友们吧！"<<endl;		
		return;
	}
	cout<<"请输入您要搜索的类型"<<endl;
	cout<<"输入1搜索姓名"<<endl;
	cout<<"输入2搜索性别"<<endl;
	cout<<"输入3搜索年龄"<<endl;
	cout<<"输入4搜索电话"<<endl;
	cin>>i;
	if(i>0&&i<=4)
	{
		if(i==1)
		{
			cin>>name;	
			for(int j=0;j<ads->size&&j<1000;j++)
			{
				if(ads->persons[j].name==name&&name!="待添加")
				{
					cout<<"搜索成功！"<<endl;
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
					cout<<"搜索成功！"<<endl;
					searchview(ads,j);
					biaoji=1;
					sum++;
				}
			}
			sousuo(biaoji,sum);
			return;
		}
		if(i==2&&sex!="待添加")
		{
			cin>>sex;
			for(int j=0;j<ads->size&&j<1000;j++)
			{
				if(ads->persons[j].sex==sex)
				{
					cout<<"搜索成功！"<<endl;
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
					cout<<"搜索成功！"<<endl;
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
		cout<<"输入类型有误！"<<endl;		
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
	//目录
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
