/* Author: Giulia Piombo
 * Date: February 20th, 2021
 * Specification: List of all employees at a company
*/

#include<stdio.h>

// structure for employee
struct employee {
  int id;
  char name[50];
  int salary;
  int exp;
  char dept[100];
};

int main() {

  // enter number of employees
  int num_employees;

  printf("How many employees information do you want to enter? ");
  scanf("%d", &num_employees);

  // array of objects
  struct employee emp[num_employees];

  // input data
  for(int i = 0; i < num_employees; i++) {
    printf("\nEnter details for employee %d:\n", i+1);
    printf("ID: ");
    scanf("%d",&emp[i].id);
    printf("Name: ");
    scanf("%s",emp[i].name);
    printf("Salary: ");
    scanf("%d",&emp[i].salary);
    printf("Experience: ");
    scanf("%d",&emp[i].exp);
    printf("Department: ");
    scanf("%s",emp[i].dept);
  }

  // print data
  printf("\nThe input data is: \n");
  for(int i = 0; i < num_employees; i++) {
    printf("\n******** DETAILS OF Employee %d ********\n",i+1);
    printf("ID = %d\n",emp[i].id);
    printf("Name = %s\n",emp[i].name);
    printf("Salary = %d\n",emp[i].salary);
    printf("Experience = %d\n",emp[i].exp);
    printf("Department = %s\n",emp[i].dept);
  }

  // enter id of the employee you want to make changes
  int changes;

  printf("\n\nEnter the id of the employee you want to change information: ");
  scanf("%d", &changes);

  // find the position of this employee
  int position;

  for (int i = 0; i < num_employees; i++) {
    if (changes == emp[i].id) {
      position = i;
    }
  }

  // input new information
  printf("Enter the new information for employee with ID %d\n", changes);
  printf("Salary: ");
  scanf("%d",&emp[position].salary);
  printf("Experience: ");
  scanf("%d",&emp[position].exp);
  printf("Department: ");
  scanf("%s",emp[position].dept);

  // print details of Employee that had changes
  printf("\n\n********DETAILS OF Employee %d********\n", position+1);
  printf("ID = %d\n",emp[position].id);
  printf("Name = %s\n",emp[position].name);
  printf("Salary = %d\n",emp[position].salary);
  printf("Experience = %d\n",emp[position].exp);
  printf("Department = %s\n",emp[position].dept);
}