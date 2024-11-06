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
    cout << "���� 1 �����ϵ�ˣ����� 2 �鿴��ϵ�ˣ����� 3 �޸���ϵ�ˣ����� 4 ɾ����ϵ�ˣ����������ַ���������" << endl;
    cin >> n;
    return n;
}

void input(AdsBook*& head, AdsBook*& p, AdsBook*& q) {
    p = new AdsBook();
    string name;
    unsigned int age;
    unsigned long long int phone;
    cout << "����������" << endl;
    cin >> name;
    cout << "����������" << endl;
    cin >> age;
    cout << "������绰" << endl;
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
    cout << "��ӳɹ�" << endl;
}

void view(AdsBook* head) {
    AdsBook* t = head;
    while (t!= nullptr) 
	{
        cout << "������" << t->person.name << " ���䣺" << t->person.age << " �绰��" << t->person.phone << endl;
        t = t->next;
    }
    return;
}

void modify(AdsBook*& head) {
    AdsBook* t = head;
    string name;
    cout << "����������" << endl;
    cin >> name;
    while (t!= nullptr) {
        if (t->person.name == name) {
            cout << "������" << t->person.name << " ���䣺" << t->person.age << " �绰��" << t->person.phone << endl;
            break;
        }
        t = t->next;
    }
    if (t!= nullptr && t->person.name == name) {
        cout << "���������ɹ�" << endl;
        unsigned int newAge;
        unsigned long long int newPhone;
        cout << "�������µ�����" << endl;
        cin >> newAge;
        cout << "�������µĵ绰" << endl;
        cin >> newPhone;
        t->person.age = newAge;
        t->person.phone = newPhone;
        cout << "�޸ĳɹ�" << endl;
    } else {
        cout << "����ʧ��" << endl;
    }
}
void del(AdsBook*& head) 
{
    AdsBook* t = head;
    string name;
    cout << "����������" << endl;
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
    	cout<<"ɾ��ʧ��"<<endl;
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
    cout << "�������" << endl;
    AdsBook* current = head;
    while (current!= nullptr) 
	{
        AdsBook* next = current->next;
        delete current;
        current = next;
    }
    return 0;
}
