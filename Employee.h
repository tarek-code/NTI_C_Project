#ifndef Employee_H
#define Employee_H
#define ERROR 5
typedef struct Node
{
unsigned char Name[255];
unsigned char age;
float Salary;
unsigned char tilte[255];
unsigned int ID;
struct Node *Next;
}Node_t;

typedef enum
{
    R_OK,
    R_NOK,
    R_NULL

}Queue_statuse;

typedef enum
{
    NAME_CHANGE,
    AGE_CHANGE,
    SALARY_CHANGE,
    TITLE_CHANGE,
    ID_CHANGE
}change_t;

Node_t *Creat_List(void);
Queue_statuse Add_employee_data(Node_t **Node);
Queue_statuse Delete_employee(Node_t **Node,unsigned int ID);
Queue_statuse Modify_employee(Node_t *Node,unsigned int ID,change_t change);
Queue_statuse View_employee(Node_t *Node,unsigned int ID);
Queue_statuse View_all_employees(Node_t *Node);



#endif // Employee_H

