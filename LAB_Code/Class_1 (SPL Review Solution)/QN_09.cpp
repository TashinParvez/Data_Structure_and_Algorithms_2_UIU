#include <bits/stdc++.h>
using namespace std;

class Employee
{
public:
    string name;
    int height;
    int age;

    Employee(string name, int height, int age)
    {
        this->name = name;
        this->height = height;
        this->age = age;
    }

public:
    Employee()
    {
    }
};

bool comparator(Employee a, Employee b)
{
    if (a.height < b.height) 
        return false;
    else if (a.height > b.height)
        return true;
    else
    {
        if (a.age < b.age)
            return false;
        else
            return true;
    }
}

void printVector(vector<Employee> employees)
{
    for (Employee e : employees)
    {
        cout << e.name << " " << e.height << " " << e.age;
        cout << endl;
    }
    cout << endl;
}

int main()
{

    int n;
    cin >> n;

    vector<Employee> employees(n);

    for (int i = 0; i < n; i++)
    {
        getchar();
        getline(cin, employees[i].name);
        cin >> employees[i].height >> employees[i].age;
    }

    sort(employees.begin(), employees.end(), comparator);
    printVector(employees);

    return 0;
}
