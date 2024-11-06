#include <iostream>
#include <string>

using namespace std;

struct People {
    string name;
    unsigned int age;
    unsigned long long int phone;
};

struct AdsBook {
    People person;
    AdsBook* next;
};

int initialization() 
{
    system("pause");
	system("cls");
	int n;
    cout << "输入 1 添加联系人，输入 2 查看联系人，输入 3 修改联系人，输入 4 删除联系人，输入其他字符结束程序" << endl;
    cin >> n;
    return n;
}

void input(AdsBook*& head, AdsBook*& p, AdsBook*& q) {
    p = new AdsBook();
    string name;
    unsigned int age;
    unsigned long long int phone;
    cout << "请输入姓名" << endl;
    cin >> name;
    cout << "请输入年龄" << endl;
    cin >> age;
    cout << "请输入电话" << endl;
    cin >> phone;

    p->person.name = name;
    p->person.age = age;
    p->person.phone = phone;
    p->next = nullptr;

    if (head == nullptr) {
        head = p;
    } else {
        q->next = p;
    }
    q = p;
    cout << "添加成功" << endl;
}

void view(AdsBook* head) {
    AdsBook* t = head;
    while (t!= nullptr) 
	{
        cout << "姓名：" << t->person.name << " 年龄：" << t->person.age << " 电话：" << t->person.phone << endl;
        t = t->next;
    }
    return;
}

void modify(AdsBook*& head) {
    AdsBook* t = head;
    string name;
    cout << "请输入姓名" << endl;
    cin >> name;
    while (t!= nullptr) {
        if (t->person.name == name) {
            cout << "姓名：" << t->person.name << " 年龄：" << t->person.age << " 电话：" << t->person.phone << endl;
            break;
        }
        t = t->next;
    }
    if (t!= nullptr && t->person.name == name) {
        cout << "本次搜索成功" << endl;
        unsigned int newAge;
        unsigned long long int newPhone;
        cout << "请输入新的年龄" << endl;
        cin >> newAge;
        cout << "请输入新的电话" << endl;
        cin >> newPhone;
        t->person.age = newAge;
        t->person.phone = newPhone;
        cout << "修改成功" << endl;
    } else {
        cout << "搜索失败" << endl;
    }
}
void del(AdsBook*& head) 
{
    AdsBook* t = head;
    string name;
    cout << "请输入姓名" << endl;
    cin >> name;
    while (t!= nullptr) 
	{
        if (t->person.name == name&&t==head) 
        {
			head=t->next;
			break;
        }
		else if(t->next->person.name == name)
		{
			t->next=t->next->next;
			break;
		}
		 
		t=t->next;  
    }
    if(t==nullptr)
    	cout<<"删除失败"<<endl;
}
int main() {
    AdsBook* head = nullptr;
    AdsBook* p = nullptr;
    AdsBook* q = nullptr;
    int i;
    while (true) {
        i = initialization();
        int flag = 0;
        if (i == 1) 
		{
            input(head, p, q);
        } else if (i == 2) 
		{
            view(head);
        } else if (i == 3) 
		{	
            modify(head);
        } else if(i==4)
		{
            del(head);
        }else 
        	flag = 1;
        if (flag == 1) {
            break;
        }
    }
    cout << "程序结束" << endl;
    AdsBook* current = head;
    while (current!= nullptr) 
	{
        AdsBook* next = current->next;
        delete current;
        current = next;
    }
    return 0;
}
