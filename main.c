#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"


int main()
{
    // ------------------------------Creating Variabels-----------------------------------//
    Node_t *employee=NULL;          // Head of Node
    Queue_statuse Statuse=0;       // Statuse
    unsigned int Data=0;          // Data input
    change_t change=NAME_CHANGE; //  Change
    char option=0;              //  option
    char Sub_option=0;
    char Exit=1;
unsigned int L_data=0;

    while(Exit)
    {
       // system("cls");


    printf("\t------------Welcome---------------\n\n\n\n");
    printf("\tChoose your option : \n\n");
    printf("\t1.Add a new employee data.\n\t2.Delete the data of an employee.\n\t3.Modify the data of an employee.\n\t4.View the data of an employee.\n\t5.View all the employees data.\n\t6.Exit.\n");
    scanf("%i",&option);
    fflush(stdin);
    switch(option)
    {
    case 1:
        system("cls");
      Statuse= Add_employee_data(&employee);
      if(NULL!=Statuse)
      {
          printf("You Passed NULL to Function\n");
      }
      if(Statuse==R_OK)
      {
          printf("Data Entered successfully  \n");
      }
      else
      {
          printf("Data Entered Done \n");
      }
        break;

    case 2:
        system("cls");
        printf("Write the ID of The employee to delete \n");
        scanf("%i",&Data);
        Statuse=Delete_employee(&employee,Data);
        if(R_OK!=Statuse)
        {
            printf("Cant Delete %i\n",Data);
        }
        else
        {
            printf("Deleted successfully\n");
        }

        break;
    case 3:

        system("cls");
        printf("Write the ID of The employee to Modefie  \n");
        scanf("%i",&L_data);
        fflush(stdin);
        printf("Choose your Action \n1-NAME_CHANGE\n2-AGE_CHANGE\n3-SALARY_CHANGE\n4-TITLE_CHANGE\n5-ID_CHANGE\n");
        scanf("%i",&Sub_option);
        fflush(stdin);

        switch(Sub_option)
        {
        case 1:



            Statuse=Modify_employee(employee,L_data,NAME_CHANGE);

            if(Statuse==R_NOK)
            {
                printf("Error happen\n");
            }
            else if(Statuse==R_NULL)
            {
                printf("NULL\n");
            }
            else
            {
                printf("Done\n");
            }

            break;
        case 2:
            Statuse=Modify_employee(employee,L_data,AGE_CHANGE);
            if(Statuse!=R_OK)
            {
                printf("Error happen\n");
            }
            else
            {
                printf("Done\n");
            }
            break;
        case 3:
            Statuse=Modify_employee(employee,L_data,SALARY_CHANGE);
            if(Statuse!=R_OK)
            {
                printf("Error happen\n");
            }
            else
            {
                printf("Done\n");
            }
            break;
        case 4:
            Statuse=Modify_employee(employee,L_data,TITLE_CHANGE);
            if(Statuse!=R_OK)
            {
                printf("Error happen\n");
            }
            else
            {
                printf("Done\n");
            }

            break;
        case 5:
            Statuse=Modify_employee(employee,L_data,ID_CHANGE);
            if(Statuse!=R_OK)
            {
                printf("Error happen\n");
            }
            else
            {
                printf("Done\n");
            }

            break;
        default:
            printf("Wrong number  :( \n");
            break;
        }

        break;
    case 4:
        system("cls");
        printf("Write the ID of The employee to delete \n");
        scanf("%i",&Data);
        Statuse=View_employee(employee,Data);
        if(Statuse!=R_OK)
            {
                printf("Error happen\n");
            }
            else
            {
                printf("Done\n");
            }

        break;
    case 5:
        system("cls");
        Statuse=View_all_employees(employee);
        if(Statuse!=R_OK)
        {
            printf("Error happen \n");
        }
        break;
    case 6:
        system("cls");
        Exit=0;
        break;
    default:
        system("cls");
        printf("Wrong number  :( \n");
        break;
    }
    }
    return 0;
}
