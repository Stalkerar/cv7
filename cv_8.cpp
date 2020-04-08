#include <stdio.h>
#include <iostream>

using namespace std;

////////////////////////////////////////// Osoba - student,ucitel,zamestanec //////////////////////////////////////////////////
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
		Student* tmpstudent = new Student(student->GetId(),student->GetName(),student->GetSecondname(),student->GetYears());
		this->_students[_count] = tmpstudent;
		this->_count++;
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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////// Geometrické tvary - rozšíøení o tøetí dimenzi //////////////////////////////////////////////
class Shapes
{
protected:
	double _sirka;
	double _vyska;
public:
	Shapes(int sirka, int vyska)
	{
		_sirka = sirka;
		_vyska = vyska;
	}
	double GetArea();
	double GetPerimeter();
	double GetObjem();
	double GetPovrch(); 
};
class Point :public Shapes
{
public:
	Point(int x, int y) : Shapes(x, y)
	{

	}
	double GetArea()
	{
		return 0;
	}
	double GetPerimeter()
	{
		return 0;
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
		double value = _sirka * _vyska;
		return value;
	}
	double GetPerimeter()
	{
		double value = (2 * _sirka) + (2 * _vyska);
		return value;
	}


};
class Kvadr : public Rectangle
{
protected:
	int hloubka;
public:
	Kvadr(int a, int b, int c) : Rectangle(a, b)
	{
		hloubka = c;
	}
	double GetObjem()
	{
		double value = _sirka * _vyska * hloubka;
		return value;
	}
	double GetPovrch()
	{
		double value = 2 * (_sirka * _vyska + _sirka * hloubka + _vyska * hloubka);
		return value;
	} 
};



class Square :public Shapes
{
public:
	Square(int strana) : Shapes(strana, strana)
	{

	}
	double GetArea()
	{
		double value = _vyska * _vyska;
		return value;
	}
	double GetPerimeter()
	{
		double value = 4 * _vyska;
		return value;
	}
};

class Krychle : public Square
{
public:
	Krychle(int strana) : Square(strana)
	{

	}
	double GetObjem()
	{
		double value = _vyska * _vyska * _vyska;
		return value;
	}
	double GetPovrch()
	{
		double value = 6 * (_vyska * _vyska);
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
	double GetPerimeter()
	{
		double value = _a + _b + _c;
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
		double value = (3.14 * (_vyska * _vyska)) / 4;
		return value;
	}
	double GetPerimeter()
	{
		double value = 3.14 * _vyska;
		return value;
	}
};

class Ball : public Circle
{
public:
	Ball(int prumer) : Circle(prumer)
	{

	}
	double GetObjem()
	{
		double tmp = 1.0/6.0;
		double value = tmp * 3.14 * (_vyska * _vyska * _vyska);
		return value;
	}
	double GetPovrch()
	{
		double value = 0;
		value = 3.14 * (_vyska * _vyska);
		return value;
	}
};








/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




int main()
{
	////////////////////////////////////////// Osoba - student,ucitel,zamestanec //////////////////////////////////////////////////
	School* sch1 = new School("VSB", 100);

	Student* std1 = new Student(1, "Pavel", "Novotny", 1998);
	Student* std2 = new Student(2, "Jiri", "Modry", 1997);
	Student* std3 = new Student(3, "Andre", "Sachasvili", 1999);

	Teacher* tch1 = new Teacher("Informatika", 30000, "Karel", "Kral", 1945);
	Employee* ucetni = new Employee(25000, "Jana", "Nova", 1975);

	Subject* sub1 = new Subject(0, "APPS", 15);

	sch1->addStudent(std1);
	sch1->addStudent(std2);
	sch1->addStudent(std3);

	sch1->printAllStudent(); // funkce pro dokazani spravnosti fungovani programu
	tch1->addSubject(sub1);
	tch1->increase_salary(1500); // overeni zda plat se meni i pro ucitele
	int tmp = tch1->GetSalary();
	cout << tmp << " ";
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	///////////////////////////////////// Geometrické tvary - rozšíøení o tøetí dimenzi //////////////////////////////////////////////
	Ball* bl1 = new Ball(10);
	cout << "Objem:" << bl1->GetObjem() << " " << "Povrch:" << bl1->GetPovrch() << " ";
	Kvadr* kv1 = new Kvadr(10, 5, 3);
	cout << "Objem:" << kv1->GetObjem() << " " << "Povrch:" << kv1->GetPovrch() << " ";
	Krychle* kr1 = new Krychle(5);
	cout << "Objem:" << kr1->GetObjem() << " " << "Povrch:" << kr1->GetPovrch() << " ";





	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






	return 1;
}
