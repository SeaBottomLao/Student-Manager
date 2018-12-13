
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int num;//学生总人数
class student {
	friend class studentMessage;
public:
	string name;
	string ID;
	double score[5];//其中1-4代表math，English,Chinese和平均成绩，0号单元为空
	student *next;
	student();

	string getName() { return name; }
	string getID() { return ID; }
	double getMath() { return score[1]; }
	double getEnglish() { return score[2]; }
	double getChinese() { return score[3]; }
	double getaverage() { return score[4]; }
	void display();                          //打印成绩
	void swap();                          //交换对象和对象->next的信息
};

student::student()
{
	cout << "请输入学生学号 : "; cin >> ID;
	cout << "请输入学生姓名 : "; cin >> name;
	cout << "请输入学生的数学、英语和语文成绩 : " << endl;
	int a, b, c;
	cin >> a;
	while (a<0 || a>100)
	{
		cout << "输入成绩有误，请重新输入: " << endl;
		cin >> a;
	}
	cin >> b;
	while (b<0 || b>100)
	{
		cout << "输入成绩有误，请重新输入: " << endl;
		cin >> b;
	}
	cin >> c;
	while (c<0 || c>100)
	{
		cout << "输入成绩有误，请重新输入: " << endl;
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
	void add();                             //向表中添加学生成绩记录
	void search();                          //在表中查找学生成绩记录
	void del();                             //在表中删除学生成绩记录
	void showAll();                         //输出所有同学所有科目的成绩
	void sort();                            //按平均成绩排序

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
			cout << "\n学号输入错误或该学生成绩已经存在！(如需修改，请先删除再重新录入)" << endl;
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
	cout << "\n请输入要查找的学生的学号:"; cin >> a;
	student *t = first;
	while (t) {
		if (t->ID == a)
			break;
		t = t->next;
	}
	if (!t)
	{
		cout << "\n未找到要查找学生！" << endl;
		return;
	}
	cout << "\n查找成功！" << endl;
	cout << " 学号    姓名     数学     英语     语文     平均成绩" << endl;
	t->display();
}
void studentMessage::del()
{
	string a;
	cout << "\n请输入要删除的学生的学号: "; cin >> a;
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
		cout << "\n未找到要删除学生！" << endl;
		return;
	}
	if (!p)
	{
		first = first->next;
		cout << "\n成功删除学生" << a << endl;
		delete t;
	}
	else
	{
		p->next = t->next;
		cout << "成功删除学生" << a << endl;
		delete t;
	}

	num--;
}
void studentMessage::showAll()
{
	cout << "---------------------成绩列表----------------------" << endl;
	cout << " 学号    姓名     数学     英语     语文     平均成绩" << endl;
	student *t = first;
	while (t) {
		t->display();
		t = t->next;
	}
}


void studentMessage::sort()
{
	int a, n = 0;                  //n--排名
	cout << "想要按照什么成绩排序？请输入相应序号(1.数学 2.英语 3.语文 4.平均成绩): ";
	while (1)
	{
		cin >> a;
		if (a != 1 && a != 2 && a != 3 && a != 4)
			cout << "\n输入序号有误，请重新输入 : ";
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
	cout << "\n\t 成绩表如下: " << endl;
	cout << "学号    姓名    成绩    排名" << endl;
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
	cout << "                                       欢迎使用学生成绩管理系统" << endl;
	cout << "                                     1.输出所有学生的信息" << endl;
	cout << "                                     2.添加学生资料" << endl;
	cout << "                                     3.根据学号查找学生成绩" << endl;
	cout << "                                     4.删除指定学生信息" << endl;
	cout << "                                     5.学生成绩排序" << endl;
	cout << "                                     6.退出" << endl;
	cout << "                                     ******************" << endl;
}
int main(){

int h;
studentMessage stuM;
stuM = studentMessage();
while (1)
{
	showmenu();
	cout << "请输入操作对应的序号 : ";
	cin >> h;
	cout << endl;
	switch (h)
	{
	case 1:stuM.showAll(); break;
	case 2: stuM.add(); break;
	case 3: stuM.search(); break;
	case 4: stuM.del(); break;
	case 5: stuM.sort(); break;
	case 6: cout << "\n退出成功！"; return 0;
	default:cout << "\n输入序号有误！请输入正确的序号。" << endl;
	}
}
}