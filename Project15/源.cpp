
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int num;//ѧ��������
class student {
	friend class studentMessage;
public:
	string name;
	string ID;
	double score[5];//����1-4����math��English,Chinese��ƽ���ɼ���0�ŵ�ԪΪ��
	student *next;
	student();

	string getName() { return name; }
	string getID() { return ID; }
	double getMath() { return score[1]; }
	double getEnglish() { return score[2]; }
	double getChinese() { return score[3]; }
	double getaverage() { return score[4]; }
	void display();                          //��ӡ�ɼ�
	void swap();                          //��������Ͷ���->next����Ϣ
};

student::student()
{
	cout << "������ѧ��ѧ�� : "; cin >> ID;
	cout << "������ѧ������ : "; cin >> name;
	cout << "������ѧ������ѧ��Ӣ������ĳɼ� : " << endl;
	int a, b, c;
	cin >> a;
	while (a<0 || a>100)
	{
		cout << "����ɼ���������������: " << endl;
		cin >> a;
	}
	cin >> b;
	while (b<0 || b>100)
	{
		cout << "����ɼ���������������: " << endl;
		cin >> b;
	}
	cin >> c;
	while (c<0 || c>100)
	{
		cout << "����ɼ���������������: " << endl;
		cin >> c;
	}
	score[1] = a;
	score[2] = b;
	score[3] = c;
	score[4] = (a + b + c)/3;
	next = NULL;
}
void student::display()
{
	cout << " " << setw(3) << ID << "     " << setw(3) << name << "      ";
	for (int i = 1; i <= 4; i++)
	{
		cout << setw(3) << score[i] << "      ";
	}
	cout << endl;
}
void student::swap()
{
	int j;
	string na, id;
	double sco[5];
	na = name; name = next->name; next->name = na;
	id = ID; ID = next->ID; next->ID = id;
	for (j = 1; j <= 4; j++)
	{
		sco[j] = score[j];
		score[j] = next->score[j];
		next->score[j] = sco[j];
	}
}
class studentMessage {
private:
	student * first;
	student * last;
public:
	studentMessage();
	student* getFirst() { return first; }
	student* getLast() { return last; }
	int getNum() { return num; }
	void add();                             //��������ѧ���ɼ���¼
	void search();                          //�ڱ��в���ѧ���ɼ���¼
	void del();                             //�ڱ���ɾ��ѧ���ɼ���¼
	void showAll();                         //�������ͬѧ���п�Ŀ�ĳɼ�
	void sort();                            //��ƽ���ɼ�����

};
studentMessage::studentMessage() {
	first = NULL;
	last = NULL;
	num = 0;

}
void studentMessage::add()
{
	student * t = new student;
	student *p = first;
	while (p) {
		if (p->ID == t->ID)
		{
			cout << "\nѧ�����������ѧ���ɼ��Ѿ����ڣ�(�����޸ģ�����ɾ��������¼��)" << endl;
			return;
		}
		p = p->next;
	}
	num++;
	if (first == NULL)
	{
		first = last = t;

	}
	else
	{
		last->next = t;
		last = last->next;
	}
}


void studentMessage::search()
{
	string a;
	cout << "\n������Ҫ���ҵ�ѧ����ѧ��:"; cin >> a;
	student *t = first;
	while (t) {
		if (t->ID == a)
			break;
		t = t->next;
	}
	if (!t)
	{
		cout << "\nδ�ҵ�Ҫ����ѧ����" << endl;
		return;
	}
	cout << "\n���ҳɹ���" << endl;
	cout << " ѧ��    ����     ��ѧ     Ӣ��     ����     ƽ���ɼ�" << endl;
	t->display();
}
void studentMessage::del()
{
	string a;
	cout << "\n������Ҫɾ����ѧ����ѧ��: "; cin >> a;
	student *t = first;
	student *p = NULL;
	while (t) {
		if (t->ID == a)
			break;
		p = t;
		t = t->next;
	}
	if (!t)
	{
		cout << "\nδ�ҵ�Ҫɾ��ѧ����" << endl;
		return;
	}
	if (!p)
	{
		first = first->next;
		cout << "\n�ɹ�ɾ��ѧ��" << a << endl;
		delete t;
	}
	else
	{
		p->next = t->next;
		cout << "�ɹ�ɾ��ѧ��" << a << endl;
		delete t;
	}

	num--;
}
void studentMessage::showAll()
{
	cout << "---------------------�ɼ��б�----------------------" << endl;
	cout << " ѧ��    ����     ��ѧ     Ӣ��     ����     ƽ���ɼ�" << endl;
	student *t = first;
	while (t) {
		t->display();
		t = t->next;
	}
}


void studentMessage::sort()
{
	int a, n = 0;                  //n--����
	cout << "��Ҫ����ʲô�ɼ�������������Ӧ���(1.��ѧ 2.Ӣ�� 3.���� 4.ƽ���ɼ�): ";
	while (1)
	{
		cin >> a;
		if (a != 1 && a != 2 && a != 3 && a != 4)
			cout << "\n��������������������� : ";
		else
			break;
	}
	student *t = first;
	student *p = t;
	while (p->next)
	{
		t = first;
		while (t->next)
		{
			if (t->next->score[a] >= t->score[a])
			{
				t->swap();
			}
			t = t->next;
		}
		p = p->next;
	}
	t = first;
	cout << "\n\t �ɼ�������: " << endl;
	cout << "ѧ��    ����    �ɼ�    ����" << endl;
	while (t) {
		n++;
		cout << " " << t->getID() << "  \t" << t->getName() << "  \t";
		switch (a)
		{
		case 1:cout << t->getMath() << "  \t" << n << endl; break;
		case 2:cout << t->getEnglish() << "  \t" << n << endl; break;
		case 3:cout << t->getChinese() << "  \t" << n << endl; break;
		case 4:cout << t->getaverage() << "  \t" << n << endl; break;
		}
		t = t->next;

	}
}
	
void showmenu(){

	cout << "                                     ****************************" << endl;
	cout << "                                       ��ӭʹ��ѧ���ɼ�����ϵͳ" << endl;
	cout << "                                     1.�������ѧ������Ϣ" << endl;
	cout << "                                     2.���ѧ������" << endl;
	cout << "                                     3.����ѧ�Ų���ѧ���ɼ�" << endl;
	cout << "                                     4.ɾ��ָ��ѧ����Ϣ" << endl;
	cout << "                                     5.ѧ���ɼ�����" << endl;
	cout << "                                     6.�˳�" << endl;
	cout << "                                     ******************" << endl;
}
int main(){

int h;
studentMessage stuM;
stuM = studentMessage();
while (1)
{
	showmenu();
	cout << "�����������Ӧ����� : ";
	cin >> h;
	cout << endl;
	switch (h)
	{
	case 1:stuM.showAll(); break;
	case 2: stuM.add(); break;
	case 3: stuM.search(); break;
	case 4: stuM.del(); break;
	case 5: stuM.sort(); break;
	case 6: cout << "\n�˳��ɹ���"; return 0;
	default:cout << "\n�������������������ȷ����š�" << endl;
	}
}
}