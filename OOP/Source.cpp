#include <iostream>
#include <string>

using namespace std;

class Departaments {
private:
	friend class Student;
	string Name;
public:
	Departaments() {}

	Departaments(string _Name) {
		this->Set_Name(_Name);
	}

	void Set_Name(string _Name) {
		this->Name = _Name;
	}

	string Get_DepartamentName() {
		return Name;
	}
};

class Lessons {
private:
	friend class Student;
	string Name;
public:
	Lessons() {}

	Lessons(string _Name) {
		this->Set_Name(_Name);
	}

	void Set_Name(string _Name) {
		this->Name = _Name;
	}

	string Get_Name() {
		return Name;
	}
};

class Human {
public:
	string Name;
	string LastName;
	int	Age;

	Human() {
		this->Name = "����";
		this->LastName = "������";
		this->Age = 0;
	}

	Human(string _Name, string _LastName, int _Age) {
		this->Name = _Name;
		this->LastName = _LastName;
		this->Age = _Age;
	}

	virtual void ChangeInfo(string _Name, string _LastName, int _Age) = 0;

	void Get_Info() {
		cout << this->Name << " " << this->LastName << " " << this->Age << " ����(���)" << endl;
	}
};

class Student : public Human {
private:
	int score[4];
	Lessons *LessonsList;
	Departaments *DepartamentName;
public:

	Student(
		string _Name,
		string _LastName,
		int _Age,
		Lessons *_LessonsList,
		Departaments *_DepartamentName
	) : Human(
		_Name,
		_LastName,
		_Age
	) {
		this->DepartamentName = _DepartamentName;
		this->LessonsList = _LessonsList;
	}

	void Set_Score() {
		cout << "������� ������ ��� ��������:" << endl;
		this->Get_Info();
		for (int i = 0; i < 4; i++) {
			cout << LessonsList[i].Get_Name() << " | ";
			cin >> this->score[i];
			if (this->score[i] > 5 || this->score[i] <= 0) {
				cout << "������ �����";
				this->score[i] = 0;
			}
			cout << endl;
		}
	}

	void Get_Score() {
		for (int i = 0; i < 4; i++) {
			cout << LessonsList[i].Get_Name() << "|" << this->score[i] << endl;
		}
	}

	void Get_RefDoc() {
		cout << "������� �� �������� �� ������� : " << this->DepartamentName->Get_DepartamentName() << endl;
		this->Get_Info();
		this->Get_Score();
	}

	void Get_AvScore(string _DepartamentName) {
		int AvSc = 0, i;
		for (i = 0; i < 4; i++) {
			AvSc += score[i];
		}
		AvSc /= (i + 1);

		if (this->DepartamentName->Get_DepartamentName() == _DepartamentName) {
			this->Get_Info();
			cout << "������� ����: " << AvSc << endl;
		}
	}

	void ChangeInfo(string _Name, string _LastName, int _Age) {
		cout << "�������������� � Student " << endl;
		this->Name = _Name;
		this->LastName = _LastName;
		this->Age = _Age;
	}
};

class Teacher : public Human {
private:
	Departaments *DepartamentName;
public:
	Teacher(string _Name,
		string _LastName,
		int _Age,
		Departaments *_DepartamentName
	) : Human(
		_Name,
		_LastName,
		_Age
	) {
		this->DepartamentName = _DepartamentName;
	}

	void ChangeInfo(string _Name, string _LastName, int _Age) {
		cout << "�������������� � Teacher" << endl;
		this->Name = _Name;
		this->LastName = _LastName;
		this->Age = _Age;
	}
};
int main() {

	setlocale(LC_CTYPE, "rus");
	Lessons *LessonsList = new Lessons[4];
	string LessonsName[]{ "������� ����", "����������", "����������", "���������" };

	for (int i = 0; i < 4; i++) {
		LessonsList[i].Set_Name(LessonsName[i]);
	}

	Departaments DepartamentsList[3];
	string DepartamentName[]{ "������� ����� ������", "������� �������", "������� ����������� � �������������� �������" };

	for (int i = 0; i < 3; i++) {
		DepartamentsList[i].Set_Name(DepartamentName[i]);
	}

	Student *Students[4];
	Students[0] = new Student("�������", "������", 25, LessonsList, &DepartamentsList[0]);
	Students[0]->Set_Score();
	Students[1] = new Student("������", "��������", 23, LessonsList, &DepartamentsList[1]);
	Students[1]->Set_Score();
	Students[2] = new Student("��������", "���������", 24, LessonsList, &DepartamentsList[2]);
	Students[2]->Set_Score();
	Students[3] = new Student("������", "������", 22, LessonsList, &DepartamentsList[1]);
	Students[3]->Set_Score();

	Teacher Teacher("������", "������", 37, &DepartamentsList[1]);

	Human *Human;
	Human = &Teacher;
	Human->ChangeInfo("�����", "�����", 37);
	Human = Students[0];
	Human->ChangeInfo("�����", "��������", 25);

	system("pause");
	system("cls");

	Students[1]->Get_RefDoc();
	system("pause");
	system("cls");

	cout << "������������ ��������� ������� : " << DepartamentsList[1].Get_DepartamentName() << endl;
	for (int i = 0; i < 4; i++) {
		Students[i]->Get_AvScore(DepartamentsList[1].Get_DepartamentName());
	}
	system("pause");

	return 0;
}