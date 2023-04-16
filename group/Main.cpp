#include <iostream>
#include <vector>
#include <string>

class Student
{
	static int count;
	int id;
	std::string name;
	int age;
	int groupID;
public:

	Student() : Student("", 0) {}

	Student(std::string _name, int _age) : name{ _name }, age{ _age }
	{
		count++;
		id = count;
	}

	Student(const Student& temp) : name{ temp.name }, age{ temp.age }
	{
		count++;
		id = count;
	}

	void print() { std::cout << "Group ID: " << groupID << "; Student id: " << id << "; Name: " << name << "; Age: " << age << std::endl; }

	void setGroupID(int _ID) { groupID = _ID; }

	int getID() { return id; }

	std::string getName() { return name; }
};

int Student::count = 0;

class Group
{
	int ID;
	std::vector<Student>group;

public:

	Group(int _id) : ID{ _id } {}

	void addStudent(std::string _name, int _age)
	{
		Student temp(_name, _age);
		temp.setGroupID(ID);
		group.push_back(temp);
	}

	void deleteStudent(int id)
	{
		for (int i = 0; i < group.size(); i++)
			if (group[i].getID() == id)
			{
				group.erase(group.begin() + i);
				break;
			}
	}

	void deleteStudent(std::string name)
	{
		int count = 0;
		int index = -1;
		for (int i = 0; i < group.size(); i++)
		{
			if (group[i].getName() == name)
			{
				count++;
				if (count >= 2)
				{
					std::cout << "There are more than 1 student with this name" << std::endl;
					break;
				}
				index = i;
			}
			if(i==group.size()-1 && index!=-1)
				group.erase(group.begin() + index);
		}
	}
	void printGroup()
	{
		for (Student item : group)
			item.print();
		std::cout << std::endl;
	}
};

int main()
{
	Group group(1);
	group.addStudent("Ilya", 15);
	group.addStudent("Ilya", 16);
	group.addStudent("Igor", 16);
	group.printGroup();
	group.deleteStudent(1);
	group.deleteStudent("Igor");
	group.printGroup();

	return 0;
}