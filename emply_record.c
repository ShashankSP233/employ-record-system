#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 50
#define MAX_NAME_LENGTH 50
#define MAX_EID_LENGTH 10

typedef struct
{
    char eid[MAX_EID_LENGTH];
    char name[MAX_NAME_LENGTH];
    int age;
    float salary;
} Employee; 

// Function prototypes
void addEmployee(Employee *employees, int *numEmployees);
void searchEmployee(Employee *employees, int numEmployees);
void showEmployees(Employee *employees, int numEmployees);
int getChoice();
void displayMenu();
int getPassword();

int main()
{
    // Dynamic memory allocation for employees array
    Employee *employees = malloc(MAX_EMPLOYEES * sizeof(Employee));
    if (employees == NULL)
    {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    int numEmployees = 4;
    int choice;
    int password;

    // Prebuilt employees (admins)
    strcpy(employees[0].eid, "EIR000");
    strcpy(employees[0].name, "Shashank Primearch");
    employees[0].age = 19;
    employees[0].salary = 999999.99;

    strcpy(employees[1].eid, "EIR001");
    strcpy(employees[1].name, "Raj KING");
    employees[1].age = 19;
    employees[1].salary = 999999.99;

    strcpy(employees[2].eid, "EIR002");
    strcpy(employees[2].name, "Rudrapratap");
    employees[2].age = 19;
    employees[2].salary = 999999.99;

    strcpy(employees[3].eid, "EIR003");
    strcpy(employees[3].name, "Raj");
    employees[3].age = 17;
    employees[3].salary = 999999.99;

    password = getPassword();

    if (password == 121234)
    {
        do
        {
            displayMenu();
            choice = getChoice();

            switch (choice)
            {
            case 1:
                addEmployee(employees, &numEmployees);
                break;
            case 2:
                searchEmployee(employees, numEmployees);
                break;
            case 3:
                showEmployees(employees, numEmployees);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
                break;
            }
        } while (choice != 4);
    }
    else
    {
        printf("Incorrect password.\n");
    }

    free(employees); // Memory deallocation
    return 0;
}

void addEmployee(Employee *employees, int *numEmployees)
{
    if (*numEmployees >= MAX_EMPLOYEES)
    {
        printf("Error: Maximum number of employees reached.\n");
        return;
    }

    printf("\nEnter employee EID: ");
    scanf("%9s", employees[*numEmployees].eid); // Limit input to MAX_EID_LENGTH - 1 characters

    printf("Enter employee name: ");
    scanf("%49s", employees[*numEmployees].name); // Limit input to MAX_NAME_LENGTH - 1 characters

    printf("Enter employee age: ");
    scanf("%d", &employees[*numEmployees].age);

    printf("Enter employee salary: ");
    scanf("%f", &employees[*numEmployees].salary);

    (*numEmployees)++;
    printf("Employee record added successfully.\n");
}

void searchEmployee(Employee *employees, int numEmployees)
{
    char eid[MAX_EID_LENGTH];
    int i, found = 0;

    printf("\nEnter employee EID to search: ");
    scanf("%9s", eid); // Limit input to MAX_EID_LENGTH - 1 characters

    for (i = 0; i < numEmployees; i++)
    {
        if (strcmp(eid, employees[i].eid) == 0)
        {
            printf("Employee found:\n");
            printf("EID: %s\n", employees[i].eid);
            printf("Name: %s\n", employees[i].name);
            printf("Age: %d\n", employees[i].age);
            printf("Salary: %.2f\n", employees[i].salary);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Employee not found.\n");
    }
}

void showEmployees(Employee *employees, int numEmployees)
{
    int i;
    for (i = 0; i < numEmployees; i++)
    {
        printf("\nEID: %s\n", employees[i].eid);
        printf("Name: %s\n", employees[i].name);
        printf("Age: %d\n", employees[i].age);
        printf("Salary: %.2f\n\n", employees[i].salary);
    }
}

int getChoice()
{
    int choice;
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);
    return choice;
}

void displayMenu()
{
    printf("\nEmployee Management System\n");
    printf("1. Add Employee Record\n");
    printf("2. Search Employee Record\n");
    printf("3. Show all Employee Records\n");
    printf("4. Exit\n");
}

int getPassword()
{
    int password;
    printf("Please enter the password: ");
    scanf("%d", &password);
    return password;
}
