#include <stdio.h>
#include <iostream>

using namespace std;

////////////////// Dìdiènost /////////////////////////
class Shapes
{
protected:
	int _sirka;
	int _vyska;
public:
	Shapes(int sirka,int vyska)
	{
		_sirka = sirka;
		_vyska = vyska;
	}
	double GetArea();
	double GetPerimeter();
};
class Point :public Shapes
{
public:
	Point(int x,int y) : Shapes(x,y)
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
	Rectangle(int sirka, int vyska) :public Shapes(sirka, vyska)
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
class Square :public Shapes
{
public:
	Square(int strana) :public Shapes(strana, strana)
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
class Triangle :public Shapes
{
private:
	int _a;
	int _b;
	int _c;
public:
	Triangle(int a, int b,int c) : Shapes(a, b)
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
////////////////////////////////////////////////////////////


/////////////////// Osoba //////////////////////////////////
class Person
{
protected:
	string firstname;
	string secondname;
	int years;
	int generation;
	
public:
	Person(string _firstname, string _secondname, int _years,int _generation)
	{
		firstname = _firstname;
		secondname = _secondname;
		years = _years;
		generation = _generation;
		
	}
	~Person() //Destruktor zde dávam èistì ze sportu bo nikde zatím dynamicky nealokuju
	{
	}
	int GetGeneration() // Getter tu mam bo jsem nenasel jine reseni jak pristoupit k promenne generation
	{
		return generation;
	}
	void PrintPerson()
	{
		cout << firstname << " " << secondname << " " << years << " ";
	}
};

class FamilyTreePerson : Person
{
private:
	Person** family_array;
	int count;
public:
	FamilyTreePerson(string _firstname,string _secondname,int _years,int _tree) : Person(_firstname,_secondname,_years,_tree)
	{
		family_array = new Person*[10];
		count = 0;
	}
	void addPerson(Person* p1)
	{
		family_array[count] = p1;
		count++;
	}
	Person* GetPerson(int idx)
	{
		return family_array[idx];
	}
	void PrintTree()
	{
		int tmp_count,tmp_count2;
		for (int a = 0; a < count; a++)
		{
			if (GetPerson(a)->GetGeneration() == 1)
			{
				GetPerson(a)->PrintPerson();
				tmp_count = 1;
			}
			if (GetPerson(a)->GetGeneration() == 2)
			{
				if (tmp_count == 1)
				{
					putchar('\n');
					putchar('\t');
					tmp_count = 0;
				}
				GetPerson(a)->PrintPerson();
				tmp_count2 = 1;
			}

			if (GetPerson(a)->GetGeneration() == 3)
			{
				if (tmp_count2 == 1)
				{
					putchar('\n');
					putchar('\t');
					putchar('\t');
					tmp_count2 = 0;
				}
				GetPerson(a)->PrintPerson();
			}
		}

	}
};
/////////////////////////////////////////////////////////////



int main()
{
	////////////////// Dìdiènost /////////////////////////
	Point* bod1 = new Point(1, 1);
	printf("Obvod: %lf Obsah: %lf \n", bod1->GetPerimeter(), bod1->GetArea());
	Rectangle* obdelnik1 = new Rectangle(5, 2);
	printf("Obvod: %lf Obsah: %lf \n", obdelnik1->GetPerimeter(), obdelnik1->GetArea());
	Square* ctverec1 = new Square(5);
	printf("Obvod: %lf Obsah: %lf \n", ctverec1->GetPerimeter(), ctverec1->GetArea());
	Triangle* trojuhelnik1 = new Triangle(3, 4, 5);
	printf("Obvod: %lf Obsah: %lf \n", trojuhelnik1->GetPerimeter(), trojuhelnik1->GetArea());
	Circle* kruh1 = new Circle(10);
	printf("Obvod: %lf Obsah: %lf \n", kruh1->GetPerimeter(), kruh1->GetArea());
	////////////////////////////////////////////////////////////

	/////////////////// Osoba /////////////////////////////
	Person* person1 = new Person("Pavel", "Novy", 76,1);
	Person* person2 = new Person("Sara", "Nova", 73,1);
	Person* person3 = new Person("Jiri", "Novy", 43,2);
	Person* person4 = new Person("Karel", "Novy", 41,2);
	Person* person5 = new Person("Vladko", "Novy", 38,2);
	Person* person6 = new Person("Jozko", "Novy", 12,3);

	FamilyTreePerson* tree1 = new FamilyTreePerson("","",0,0);
	tree1->addPerson(person1); // Pridavam osoby do pole osob, ktere mam ve tride FamilyTreePerson
	tree1->addPerson(person2);
	tree1->addPerson(person3);
	tree1->addPerson(person4);
	tree1->addPerson(person5);
	tree1->addPerson(person6);
	tree1->PrintTree();
	///////////////////////////////////////////////////////



	return 1;
}

