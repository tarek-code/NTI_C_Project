
#include <stdio.h>
#include "Employee.h"

// helper Function
Node_t *Creat_List(void)
{
    Node_t *Ptr;
  return (Ptr);
}


//Main Function
Queue_statuse Add_employee_data(Node_t **Node)
{
    unsigned int numer=0;
    unsigned char text[255]={0};
    Node_t *Temp_Node=NULL;
    Queue_statuse L_Status=R_NOK;
    if(NULL==Node)
    {
        L_Status=R_NULL;
    }
    else
    {
        Temp_Node=(Node_t *)malloc(sizeof(Node_t));
        if(NULL==Temp_Node)
        {
            L_Status=R_NULL;
        }
        else
        {
            Temp_Node->Next=*Node;
            *Node=Temp_Node;
            fflush(stdin);
            printf("\nWrite employee  Name : ");
            gets(Temp_Node->Name);
            fflush(stdin);
            printf("\nWrite employee  age : ");
            scanf("%i",&Temp_Node->age);
            fflush(stdin);
            printf("\nWrite employee  Title : ");
            gets(Temp_Node->tilte);
            fflush(stdin);
            printf("\n Write employee  Salary : ");
            scanf("%f",&Temp_Node->Salary);
            fflush(stdin);
            printf("\nWrite employee  ID : ");
            scanf("%i",&(Temp_Node->ID));
            fflush(stdin);
           L_Status=R_OK;
        }
    }
    return L_Status;
}

Queue_statuse Delete_employee(Node_t **Node,unsigned int ID)
{

    Node_t *current=*Node;
    Node_t *Previus=NULL;
    Queue_statuse L_Statuse=R_NOK;
    if(current!=NULL&&current->ID==ID)
    {
        *Node=current->Next;
        free(current);
        L_Statuse=R_OK;
    }
    else
    {
        while(current!=NULL&&current->ID!=ID)
        {
            Previus=current;
            current=current->Next;
        }
        if(current==NULL)
        {
            L_Statuse=R_NULL;
        }
        else
        {
            Previus->Next=current->Next;
            free(current);
            L_Statuse=R_OK;
        }
    }
    return L_Statuse;

}

Queue_statuse Modify_employee(Node_t *Node,unsigned int ID,change_t change)
{

    Node_t *current=Node;
    Node_t *Previus=NULL;
    Queue_statuse L_Statuse=R_NOK;



    while (current != NULL && current->ID != ID) {
        current = current->Next;
    }

    if (current == NULL) {
        printf("Error: Employee with ID %d not found.\n", ID);
        L_Statuse=R_NOK;
    }
    else
    {



        switch(change)
        {
        case NAME_CHANGE:
            for(int i=0;i<255;i++)
            {
                current->Name[i]=0;
            }
            printf("\nWrite the new Name of The employee :");
            gets(current->Name);
            fflush(stdin);
             L_Statuse=R_OK;
            break;
        case ID_CHANGE:
            printf("\nWrite the new ID of The employee :");
            scanf("%i",&current->ID);
            fflush(stdin);
             L_Statuse=R_OK;
            break;
        case TITLE_CHANGE:
            for(int i=0;i<255;i++)
            {
                current->tilte[i]=0;
            }
            printf("\nWrite the new Title of The employee :");
            gets(current->tilte);
            fflush(stdin);
             L_Statuse=R_OK;
            break;
        case SALARY_CHANGE:
             printf("\nWrite the new Salary of The employee :");
            scanf("%f",&current->Salary);
            fflush(stdin);
             L_Statuse=R_OK;
            break;
        case AGE_CHANGE:
             printf("\nWrite the new Age of The employee :");
            scanf("%i",&current->age);
            fflush(stdin);
             L_Statuse=R_OK;
            break;
        default:
            L_Statuse=R_NOK;
            break;
        }


            L_Statuse=R_OK;
        }



    return L_Statuse;
}

Queue_statuse View_employee(Node_t *Node,unsigned int ID)
{
    Node_t *current=Node;

    Queue_statuse L_Statuse=R_NOK;
    if(NULL==Node)
    {
        L_Statuse=R_NULL;
    }
    else
    {


    if(current!=NULL&&current->ID==ID)
    {
        printf("----------------------------------------\n\n");
        printf("The ID Of employee is = %i\n",current->ID);
        printf("The Name Of employee is = %s\n",current->Name);
        printf("The Title Of employee is = %s\n",current->tilte);
        printf("The Age Of employee is = %i\n",current->age);
        printf("The Salary Of employee is = %f\n",current->Salary);
        printf("----------------------------------------\n\n");

        L_Statuse=R_OK;
    }
    else
    {
        while(current!=NULL&&current->ID!=ID)
        {

            current=current->Next;
        }
        if(current==NULL)
        {
            L_Statuse=R_NULL;
        }
        else
        {

        printf("----------------------------------------\n\n");
        printf("The ID Of employee is = %i\n",current->ID);
        printf("The Name Of employee is = %s\n",current->Name);
        printf("The Title Of employee is = %s\n",current->tilte);
        printf("The Age Of employee is = %i\n",current->age);
        printf("The Salary Of employee is = %f\n",current->Salary);
        printf("----------------------------------------\n\n");
            L_Statuse=R_OK;
        }
    }
    }
    return L_Statuse;
}

Queue_statuse View_all_employees(Node_t *Node)
{

    Node_t *current=Node;
    Queue_statuse L_Statuse=R_NOK;
    if(NULL==Node)
    {
        L_Statuse=R_NULL;
    }
    else
    {


    while(current!=NULL)
    {
        printf("----------------------------------------\n\n");
        printf("The ID Of employee is = %i\n",current->ID);
        printf("The Name Of employee is = %s\n",current->Name);
        printf("The Title Of employee is = %s\n",current->tilte);
        printf("The Age Of employee is = %i\n",current->age);
        printf("The Salary Of employee is = %f\n",current->Salary);
        printf("----------------------------------------\n\n");
        current=current->Next;
        L_Statuse=R_OK;
    }
    }
    return L_Statuse;
}
