#include <iostream>
#include<string.h>
using namespace std;

class Human;
class Employee;
class Empl_Hour;
class Empl_Month;

double monthly_salary(const Empl_Hour& obj);
double monthly_salary(const Empl_Month& obj);

#define delimiter "\n/----------------------------------------------------------------------------/\n"

class Human {
	string last_name;
	string first_name;
	unsigned int age;

public:
	const string& get_last_name()const {
		return last_name;
	}
	const string& get_first_name()const {
		return first_name;
	}
	unsigned int get_age()const {
		return age;
	}
	void set_last_name(const string& last_name) {
		this->last_name = last_name;
	}
	void set_first_name(const string& first_name) {
		this->first_name = first_name;
	}
	void set_age(unsigned int age) {
		this->age = age;
	}

	//                  Constructors

	Human(const string& last_name, const string& first_name, unsigned int age) {
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor: \t" << this << endl;

	}
	~Human()
	{
		cout << "HDestructor: \t" << this << endl;
	}

	//                   Methods

	virtual void print() const {
		cout << last_name << " " << first_name << ", " << age;
		print_year_suffix(age);
		cout << endl;
	}
protected:
	void print_year_suffix(unsigned int age) const {
		if (age % 20 >= 5 && age % 20 <= 20) cout << " ���";
		else if (age % 10 >= 5 && age % 10 == 0) cout << " ���";
		else if (age % 10 > 1 && age % 10 < 5) cout << " ����";
		else cout << " ���";
	}
};

class Employee : public Human{
	string department;			//�����
	string position;			//���������
	unsigned int experience;	//����
	string education;			//�����������
public:
	const string& get_department() const {
		return department;
	}
	const string& get_position()const {
		return position;
	}
	unsigned int get_experience() const {
		return experience;
	}
	const string& get_education() {
		return education;
	}
	void set_department(const string& department) {
		this->department = department;
	}
	void set_position(const string& position) {
		this->position = position;
	}
	void set_experience(unsigned int experience) {
		this->experience = experience;
	}
	void set_education(const string& education) {
		this->education = education;
	}

//				Constructors
	Employee(const string& last_name, const string& first_name, unsigned int age,
		const string& department, const string& position, unsigned int experience, const string& education
	) :Human(last_name, first_name, age)
	{
		set_department(department);
		set_position(position);
		set_experience(experience);
		set_education(education);
		cout << "EConstructor:\t" << this << endl;
	}
	~Employee()
	{
		cout << "EDestructor:\t" << this << endl;
	}
//				Methods
	void print()const {
		Human::print();
		cout << "�����: " << department << ", ���������: " << position << ", ���� ������: " << experience;
		print_year_suffix(experience);
		cout << ", �����������: " << education << endl;
	}

};

class Empl_Hour : public Employee {
	unsigned int hours_count;			//���������� ������������ �����
	double cost_of_an_hour;				//��������� ������ ���� ������ ����������
public:
	unsigned int get_hours_count() const {
		return hours_count;
	}
	double get_cost_of_an_hour() const {
		return cost_of_an_hour;
	}
	void set_hours_count(unsigned int hours_count) {
		this->hours_count = hours_count;
	}
	void set_cost_of_an_hour(double cost_of_an_hour) {
		this->cost_of_an_hour = cost_of_an_hour;
	}
//						Constructors
	Empl_Hour
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& department, const string& position, unsigned int experience, const string& education,
		unsigned int hours_count, double cost_of_an_hour
	) :Employee(last_name, first_name, age, department, position, experience, education)
	{
		set_hours_count(hours_count);
		set_cost_of_an_hour(cost_of_an_hour);
		cout << "EHConstructors:\t" << this << endl;
	}
	~Empl_Hour() {
		cout << "EHDestructor:\t" << this << endl;
	}

	//                                           Methods

	void print()const {
		Employee::print();
		cout << "���������� ������������ �����: " << hours_count <<
			", ��������� ������ ���� ������: " << cost_of_an_hour << " ���.";
		cout << endl;

	}

};

class Empl_Month : public Employee {
	unsigned int salary;			//�����
public:
	unsigned int get_salary() const {
		return salary;
	}
	void set_salary(unsigned int salary) {
		this->salary = salary;
	}
	//						Constructors
	Empl_Month
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& department, const string& position, unsigned int experience, const string& education,
		unsigned int salary
	) :Employee(last_name, first_name, age, department, position, experience, education)
	{
		set_salary(salary);
		cout << "EMConstructors:\t" << this << endl;
	}
	~Empl_Month() {
		cout << "EMDestructor:\t" << this << endl;
	}

	//                                           Methods

	void print()const {
		Employee::print();
		cout << "�����: " << salary << " ���.";
		cout << endl;

	}
};

double monthly_salary(const Empl_Hour& obj) {
	return (obj.get_cost_of_an_hour() * obj.get_hours_count());
}

double monthly_salary(const Empl_Month& obj) {
	return obj.get_salary();
}


void main() {
	setlocale(LC_ALL, "Russian");
	Human* group[] =
	{
		//				�������		���		�������	�����	    ���������	���� ������	   �����������   ������ �����
		new Empl_Hour ("���������", "�������", 50,	 "���",   "������������",   21,			"������",		504, 30000),
		new Empl_Hour("�������", "�������",   27,	 "���",   "����������",      11,		"������",		200, 2000),
		new Empl_Month("�������", "����������", 25,	 "���",   "����������� �����", 5,		 "������",			100000),
		new Empl_Month("�������","��������",  61,	"���",    "��������",        22,	"������� �����������",	 120000),
		new Empl_Month("������", "��������",  39,	"���",    "��������� ����",  13,			"��������",		 100500)
	};
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++) {
		group[i]->print();
		
		cout << delimiter << endl;
	}
	
	
	
	
}