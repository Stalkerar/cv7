#include <stdio.h>
#include <iostream>

using namespace std;

////////////////////////////////////////// Osoba, student - pøetížení metody //////////////////////////////////////////////////
class Subject
{
private:
	int _points;
	string _Name_Subject;
	int _credit;
public:
	Subject(int points, string name, int credit)
	{
		_points = points;
		_Name_Subject = name;
		_credit = credit;
	}
	~Subject()
	{

	}
	void addPoitns(int value)
	{
		_points = _points + value;
	}
	bool Checker()
	{
		if (this->_points > 50)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int GetCredit()
	{
		return _credit;
	}

};

class Person
{
protected:
	string firstname;
	string secondname;
	int years;
public:
	Person(string _firstname, string _secondname, int _years)
	{
		firstname = _firstname;
		secondname = _secondname;
		years = _years;
	}
	string GetName()
	{
		return firstname;
	}
	string GetSecondname()
	{
		return secondname;
	}
	int GetYears()
	{
		return years;
	}
};

class Student : public Person
{
private:
	int id;
	int credit;
	Subject** _subjects;
	int _count;
public:
	Student(int _id, string _firstname, string _secondname, int _years) :Person(_firstname, _secondname, _years)
	{
		id = _id;
		credit = 0;
		_subjects = nullptr;
		_count = 0;
	}
	~Student()
	{

	}
	void addSubject(Subject* sub)
	{
		Subject* tmp_subject = new Subject(*sub);
		_subjects[_count] = tmp_subject;
		_count++;
	}
	Subject* GetSubject(int idx)
	{
		return _subjects[idx];
	}
	string GetName()
	{
		return firstname;
	}
	string GetSecondname()
	{
		return secondname;
	}
	int GetCredit()
	{
		return credit;
	}
	int GetId()
	{
		return id;
	}
	int GetYears()
	{
		return years;
	}
};

class School
{
public:
	School(string name, int capacity)
	{
		_name = name;
		_capacity = capacity;
		_students = new Student * [capacity];
		_count = 0;
	}
	~School()
	{
		delete[] _students;
	}

	int addStudent(Student* student)
	{
		Student* tmpstudent = new Student(student->GetId(), student->GetName(), student->GetSecondname(), student->GetYears());
		this->_students[_count] = tmpstudent;
		this->_count++;
		return _count;
	}
	int addStudent(Person* person)
	{
		Student* tmpstudent = new Student(_count, person->GetName(), person->GetSecondname(), person->GetYears());
		addStudent(tmpstudent);
		return _count;
	}
	int addStudent(string ini_firstname,string ini_secondname,int years)
	{
		Student* tmpstudent = new Student(_count, ini_firstname, ini_secondname, years);
		addStudent(tmpstudent);
		return _count;
	}
	Student* GetStudent(int indx)
	{
		return this->_students[indx];
	}
	int GetCount()
	{
		return this->_count;
	}
	int GetCapacity()
	{
		return this->_capacity;
	}
	void printAllStudent()
	{
		for (int a = 0; a < _count; a++)
		{
			cout << GetStudent(a)->GetName() << " " << GetStudent(a)->GetSecondname() << " " << GetStudent(a)->GetYears() << " ";
		}
	}
private:
	int _capacity, _count;
	Student** _students;
	string _name;
};

class Employee : public Person
{
private:
	int salary;
public:
	Employee(int _salary, string _firstname, string _secondname, int years) : Person(_firstname, _secondname, years)
	{
		salary = _salary;
	}
	void increase_salary(int value)
	{
		salary = salary + value;
	}
	int GetSalary()
	{
		return salary;
	}
};

class Teacher : public Employee
{
private:
	Subject** _subjects;
	string katedra;
	int count;
public:
	Teacher(string _katedra, int _salary, string _firstname, string _secondname, int years) : Employee(_salary, _firstname, _secondname, years)
	{
		katedra = _katedra;
		count = 0;
		_subjects = new Subject * [10];
	}
	void addSubject(Subject* subject)
	{
		_subjects[count] = subject;
		count++;
	}
};
/////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////// Geometrické tvary - polymorfismus ////////////////////////////////////////////////

class Shapes
{
private:
	double _sirka;
	double _vyska;
	Shapes** collection;
	int count;
public:
	Shapes(int sirka, int vyska)
	{
		_sirka = sirka;
		_vyska = vyska;
		collection = (Shapes**)malloc(sizeof(Shapes)*10);
		count = 0;
	}
	virtual double GetArea(); // Zde mam problem 
	double GetSirka()
	{
		return _sirka;
	}
	double GetVyska()
	{
		return _vyska;
	}
	void addShape(Shapes* sh1)
	{
		Shapes* tmp_shape = new Shapes(*sh1);
		collection[count] = tmp_shape;
		count++;
	}
	void SortArr()
	{
		//double tmp_value;
		double checker = 0;
		//Shapes** tmp_shapes = (Shapes**)malloc(sizeof(Shapes) * 10);
		Shapes* tmp_shape;
		
			
		for (int i = 0; i < count - 1; i++) 
		{
			for (int j = 0; j < count - i - 1; j++) 
			{
				if (collection[j + 1]->GetArea() < collection[j]->GetArea())
				{
					tmp_shape = collection[j + 1];
					collection[j + 1] = collection[j];
					collection[j] = tmp_shape;
				}
			}
		}
		
	}
	Shapes GetShape(int idx)
	{
		return *collection[idx];
	}
	void PrintArr()
	{
		for (int a = 0; a < count; a++)
		{
			cout << GetShape(a).GetVyska() << " ";
		}
	}
	
};

class Rectangle :public Shapes
{
public:
	Rectangle(int sirka, int vyska) : Shapes(sirka, vyska)
	{

	}
	double GetArea()
	{
		double value = GetSirka() * GetSirka();
		return value;
	}
};

class Triangle :public Shapes
{
private:
	int _a;
	int _b;
	int _c;
public:
	Triangle(int a, int b, int c) : Shapes(a, b)
	{
		_a = a;
		_b = b;
		_c = c;
	}
	double GetArea()
	{
		double value;
		double s = (_a + _b + _c) / 2;
		value = sqrt(s * (s - _a) * (s - _b) * (s - _c));

		return value;
	}

};

class Circle :public Shapes
{
public:
	Circle(int prumer) : Shapes(prumer, prumer)
	{

	}
	double GetArea()
	{
		double value = (3.14 * (GetVyska() * GetVyska())) / 4;
		return value;
	}
	
};










///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	///////////////////// Osoba, student - pøetížení metody ///////////////////////////////
	School* sch1 = new School("VSB", 100);

	Student* std1 = new Student(1, "Pavel", "Novotny", 1998);
	Student* std2 = new Student(2, "Jiri", "Modry", 1997);
	Student* std3 = new Student(3, "Andre", "Sachasvili", 1999);

	Person* prs1 = new Person("Pepa", "Stefo", 1996);

	Teacher* tch1 = new Teacher("Informatika", 30000, "Karel", "Kral", 1945);
	Employee* ucetni = new Employee(25000, "Jana", "Nova", 1975);

	Subject* sub1 = new Subject(0, "APPS", 15);

	sch1->addStudent(std1);
	sch1->addStudent(std2);
	sch1->addStudent(std3);

	sch1->addStudent(prs1);
	sch1->addStudent("J", "C", 1901);


	sch1->printAllStudent(); // funkce pro dokazani spravnosti fungovani programu
	
	putchar('\n');
	////////////////////////////////////////////////////////////////////////////////////////////
	Shapes* sh1 = new Shapes(1,1);

	Circle* cr1 = new Circle(5);
	Triangle* tr1 = new Triangle(2,3,4);
	Rectangle* rc1 = new Rectangle(10, 5);

	sh1->addShape(cr1);
	sh1->addShape(tr1);
	sh1->addShape(rc1);

	sh1->PrintArr();
	sh1->SortArr();
	sh1->PrintArr();
	return 0;
}
