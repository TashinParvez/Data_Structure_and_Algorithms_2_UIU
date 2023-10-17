#include <bits/stdc++.h>
using namespace std;
class Employee
{
public:
    string name;
    int id;
    int salary;

    Employee(string name, int id, int salary)
    {
        this->name = name;
        this->id = id;
        this->salary = salary;
    }

    Employee()
    {
    }
};

bool comparator(Employee a, Employee b)
{
    if (a.salary < b.salary)
        return true;
    else if (a.salary > b.salary)
        return false;
    else
    {
        if (a.id < b.id)
            return true;
        else
            return false;
    }
}

void printVector(vector<Employee> employees)
{
    for (Employee e : employees)
    {
        cout << e.name << " " << e.salary << " " << e.id;
        cout << endl;
    }
    cout << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    getchar();

    vector<Employee> employees(n);

    for (int i = 0; i < n; i++)
    {
        getline(cin, employees[i].name);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> employees[i].id;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> employees[i].salary;
    }

    printVector(employees);

    sort(employees.begin(), employees.end(), comparator);

    printVector(employees);
    return 0;
}