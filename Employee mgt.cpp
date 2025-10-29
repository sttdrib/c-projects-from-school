#include <iostream>
#include <string>
using namespace std;

struct Employee
{
    string id;
    string name;
    string position;
    float salary;
    string date;
    Employee *next;
};

Employee *head = NULL;
Employee *tail = NULL;

void addEmployee(string name, string id, string position, float salary, string date)
{
    Employee *temp = new Employee;
    temp->id = id;
    temp->name = name;
    temp->position = position;
    temp->salary = salary;
    temp->date = date;
    temp->next = NULL;

    if (tail == NULL)
    {
        tail = temp;
        temp->next = temp;
    }
    else
    {
        temp->next = tail->next;
        tail->next = temp;
        tail = temp;
    }
    cout << "Employee added successfully." << endl;
}

void displayEmployees()
{
   if (tail == NULL)
   {       cout << "No employees to display." << endl;
       return;
   }    cout << "___________________________________________________________________" << endl;
    cout << "| Name       | ID         | Position   | Salary     | Date       |" << endl;
   cout << "___________________________________________________________________" << endl;

    Employee *current = tail->next;
   do
   {
        cout << "| ";
       cout.width(10);
       cout << left << current->name;
      cout << " | ";
      cout.width(10);
      cout << left << current->id;
      cout << " | ";
      cout.width(10);
      cout << left << current->position;
      cout << " | ";
	        cout.width(10);
       cout.setf(ios::fixed);
       cout.precision(2);
       cout << left << current->salary;
        cout << " | ";
       cout.width(10);
       cout << left << current->date;
       cout << " |" << endl;

       current = current->next;
   } while (current != tail->next);
    cout << "___________________________________________________________________" << endl;
}

int deleteEmployee(string id)
{
    if (tail == NULL)
        return 0;

    Employee *current = tail->next;
    Employee *prev = tail;

    do
    {
        if (current->id == id)
        {
            if (current == tail && current == tail->next)
            {
                delete current;
                tail = NULL;
            }
            else
            {
                prev->next = current->next;
                if (current == tail)
                    tail = prev;
                delete current;
            }
            return 1;
        }
        prev = current;
        current = current->next;
    } while (current != tail->next);

    return 0;
}

Employee *searchEmployee(string id)
{
    if (tail == NULL)
        return NULL;

    Employee *current = tail->next;
    do
    {
        if (current->id == id)
        {
            return current;
        }
        current = current->next;
    } while (current != tail->next);

    return NULL;
}

int updateEmployee(string id, string newName, string newPosition, float newSalary, string newDate)
{
    Employee *emp = searchEmployee(id);
    if (emp != NULL)
    {
        emp->name = newName;
        emp->position = newPosition;
        emp->salary = newSalary;
        emp->date = newDate;
        return 1;
    }
    return 0;
}

void sortEmployeesByName()
{
    if (tail == NULL || tail->next == tail)
        return;

    bool swapped;
    Employee *temp;
    Employee *temp1 = NULL;

    do
    {
        swapped = false;
        temp = tail->next;

        do
        {
            Employee *nextNode = temp->next;
            if (nextNode == tail->next)
                break;

            if (temp->name > nextNode->name)
            {
                swap(temp->id, nextNode->id);
                swap(temp->name, nextNode->name);
                swap(temp->position, nextNode->position);
                swap(temp->salary, nextNode->salary);
                swap(temp->date, nextNode->date);
                swapped = true;
            }
            temp = temp->next;
        } while (temp->next != temp1);

        temp1 = temp;
    } while (swapped);
}

int main()
{
    int choice, count;
    string id, name, position, date;
    float salary;

    do
    {
        cout << "\n Employee Management System \n";
        cout << "1. Add Employee\n";
        cout << "2. Display All Employees\n";
        cout << "3. Search Employee\n";
        cout << "4. Update Employee\n";
        cout << "5. Delete Employee\n";
        cout << "6. Sort Employees by Name\n";
        cout << "7. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            cout << "How many employees do you want to add: ";
            cin >> count;
            cin.ignore();
            
            
            
            

            for (int i = 0; i < count; i++)
            {
                cout << "\nEmployee #" << (i + 1) << endl;

                cout << "Enter Name: ";
                getline(cin, name);

                cout << "Enter ID: ";
                getline(cin, id);
                
                if (searchEmployee(id)!=NULL){
			    cout<<"Employee id is used! "<<endl;
            	break;
			}

                cout << "Enter Position: ";
                getline(cin, position);

                cout << "Enter Salary: ";
                cin >> salary;
                cin.ignore();

                cout << "Enter Date: ";
                getline(cin, date);

                addEmployee(name, id, position, salary, date);
            }
            break;

        case 2:
            displayEmployees();
            break;

        case 3:
            cout << "Enter ID to search: ";
            getline(cin, id);
            {
                Employee *emp = searchEmployee(id);
                if (emp != NULL)
                {
                    cout << "Found Employee:\n";
                    cout << "Name: " << emp->name << endl;
                    cout << "ID: " << emp->id << endl;
                    cout << "Position: " << emp->position << endl;
                    cout << "Salary: " << emp->salary << endl;
                    cout << "Date: " << emp->date << endl;
                }
                else
                {
                    cout << "Employee not found." << endl;
                }
            }
            break;

        case 4:
            cout << "Enter ID to update: ";
            getline(cin, id);

            cout << "Enter new Name: ";
            getline(cin, name);

            cout << "Enter new Position: ";
            getline(cin, position);

            cout << "Enter new Salary: ";
            cin >> salary;
            cin.ignore();

            cout << "Enter new Date: ";
            getline(cin, date);

            if (updateEmployee(id, name, position, salary, date) == 1)
            {
                cout << "Employee updated successfully." << endl;
            }
            else
            {
                cout << "Employee not found." << endl;
            }
            break;

        case 5:
            cout << "Enter ID to delete: ";
            getline(cin, id);
            if (deleteEmployee(id) == 1)
            {
                cout << "Employee deleted successfully." << endl;
            }
            else
            {
                cout << "Employee not found." << endl;
            }
            break;

        case 6:
            sortEmployeesByName();
            cout << "Employees sorted by name (ascending) successfully." << endl;
            break;

        case 7:
        cout << "Exiting..." << endl;
            break;

        default:
            cout<<"Invalid option.\n";
			cout<<"__________\n| WARNING | : you need to restart the program if the character you entered is not of the set of real numbers!"<<endl;
            cout<<"__________"<<endl;
        }
    } while (choice);
    return 0;
}

