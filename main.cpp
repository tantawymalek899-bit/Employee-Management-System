#include <iostream>
using namespace std;

// Global variables
const int MAX = 10000;

string names[MAX];
int ages[MAX];
int salaries[MAX];
char gender[MAX];
int added = 0;

int menu()
{
    int choice = -1;
    while (choice == -1)
    {
        cout << "\nEnter your choice: \n";
        cout << "1) Add new employee\n";
        cout << "2) print all employees\n";
        cout << "3) Delete by age\n";
        cout << "4) Update salary by name\n";
        cout << "5) Exit\n";

        cin >> choice;

        if (!(1 <= choice && choice <= 5))
        {
            cout << "Invalid input! try again\n";
            choice = -1;
        }
        cout << endl;
    }
    return choice;
}

void read_employee()
{
    cout << "Enter name: ";
    cin >> names[added];

    cout << "Enter age: ";
    cin >> ages[added];

    cout << "Enter salary: ";
    cin >> salaries[added];

    cout << "Enter gender (M/F): ";
    cin >> gender[added];

    added++;
}

void print_employee()
{
    cout << "******************************************\n";
    for (int i = 0; i < added; i++)
        if (ages[i] != -1)
            cout << names[i] << " "
                 << ages[i] << " "
                 << salaries[i] << " "
                 << gender[i] << "\n";
}

void delete_by_age()
{
    int start, end;
    cout << "Enter start and end age: ";
    cin >> start >> end;

    for (int i = 0; i < added; i++)
        if (start <= ages[i] && ages[i] <= end)
            ages[i] = -1;
}

void update_salary_by_name()
{
    cout << "Enter name and salary: ";
    string name;
    int salary;
    cin >> name >> salary;

    bool found = false;

    for (int i = 0; i < added; i++)
    {
        if (ages[i] != -1 && name == names[i])
        {
            salaries[i] = salary;
            found = true;
            break;
        }
    }
    if (!found)
        cout << "There is no employee with this name!\n";
}

void employee_system()
{
    while (true)
    {
        int choice = menu();
        if (choice == 1)
            read_employee();
        else if (choice == 2)
            print_employee();
        else if (choice == 3)
            delete_by_age();
        else if (choice == 4)
            update_salary_by_name();
        else
            break;
    }
}
int main()
{
    employee_system();
    return 0;
}
