#include <stdio.h>
#include <stdlib.h>
struct employee
{
    char name[50];
    int ID;
    float salary;
    int phnum;
    int citnum;
};
void newemp(int j, struct employee *ptr);
void deleteemp(int ID, struct employee *ptr);
void deleteemp2(char *A, struct employee *ptr);
void modify(int ID,struct employee *ptr);
void print1(int ID, struct employee *ptr);
void print2(char *A,struct employee *ptr);
void print3(int num,struct employee *ptr);
void swap(struct employee *xp,struct employee *yp);
void selectionSort(struct employee *ptr );
void printall(struct employee *ptr);
int main()
{
    struct employee E[100]={0};
    int i;
    int j=0;
    for(i=0;i<100;i++)
    {
        E[i].ID=0;
    }

   int choose;
   int count;
   for(;;count++)
   {
       printf("1-Add new employee\t\t\t 2-Delete employee form data base\n\n");
       printf("3-Modify employee data\t\t\t 4-Print employee details\n\n");
       printf("5-Sort the data base\t\t\t 6-print all the data base\n\n\n\n");
       printf("choose one of the options:\n");
       scanf("%d",&choose);

       if(choose==1)
   {
        newemp(j,E);
        j++;
   }
   else if(choose==2)
   {
       printf("1-Delete by ID\t\t\t2-Delete by name\n\n");
       scanf("%d",&count);
       if(count==1)
       {
           int ID;
           printf("enter the ID:\n");
           scanf("%d",&ID);
           deleteemp(ID,E);
       }
       else if(count==2)
       {
           char A[50];

           deleteemp2(A,E);


       }
       else
       {
           printf("please choose one of the options");
       }

   }
   else if(choose==3)
   {
        int ID;
        printf("enter the ID:\n");
        scanf("%d",&ID);
        modify(ID,E);
   }
   else if(choose==4)
   {
        printf("1-Print by ID\t\t\t2-Print by name\n\n");
        printf("3-Print by phone number\n\n");
        scanf("%d",&count);
        if(count==1)
        {
           int ID;
           printf("enter the ID:\n");
           scanf("%d",&ID);
           printf("\n\n");
           print1(ID,E);
        }
        else if(count==2)
        {
           char A[50];
           print2(A,E);


        }
        else if (count==3)
        {
           int num;
           printf("enter the phone number:\n");
           scanf("%d",&num);
           printf("\n\n");
           print3(num,E);
        }
        else
       {
           printf("please choose one of the options");
       }
   }
   else if (choose==5)
   {
       selectionSort(E);


   }
   else if (choose==6)
   {
        printall(E);
   }
   else
   {
       printf("please choose one of the options");

   }
   printf("\n\n\n");
   }

    return 0;
}

void newemp(int j, struct employee *ptr)
{
    printf("enter employee's name:\n");
    scanf("%s",&ptr[j].name);
    printf("enter employee's ID:\n");
    scanf("%d",&ptr[j].ID);
    checkID(j,ptr);


    printf("enter employee's salary:\n");
    scanf("%f",&ptr[j].salary);
    printf("enter employee's phone number:\n");
    scanf("%d",&ptr[j].phnum);
    printf("enter employee's city number:\n");
    scanf("%d",&ptr[j].citnum);

}

void checkID(int i, struct employee *ptr)
{
    int j;

    for (j=0;j<i;j++)
    {
        if((ptr[i].ID)!=(ptr[j].ID))
        {

            continue;
        }
        else
        {
            printf("Already taken please enter another employee's ID:\n");
            scanf("%d",&ptr[i].ID);
            checkID(i,ptr);
        }
    }

}

void deleteemp(int ID, struct employee *ptr)
{
int i;
int j;
for(i=0;i<100;i++)
{
    if((ptr[i].ID)==ID)
    {
        for(j=0;j<50;j++)
        {
            ptr[i].name[j]='\0';
        }
        ptr[i].ID='\0';
        ptr[i].salary='\0';
        ptr[i].citnum='\0';
        ptr[i].phnum='\0';
        printf("\t\t\tDone\n\n\n");
    }
}

}

void deleteemp2(char *A, struct employee *ptr)
{
    int k;
    int i;
    int j;
    printf("enter the employee's name:\n");
    scanf("%s",A);
    printf("\n\n");

    for (j=0;j<100;j++)
    {
        int len1=0;
        int len2=0;
        int same=0;
        i=0;
        while(A[i++]!='\0')
        {
            len1++;
        }
        i=0;
        while(ptr[j].name[i++]!='\0')
        {
            len2++;
        }
        if(len1!=len2)
        {
            continue;

        }
        same=1;

        for(i=0;i<len1;i++)
        {
            if(A[i]!=(ptr[j].name[i]))
            {
                same=0;
                i=len1;
                printf("hello12345");
            }

        }

        if (same==1)
         {
             for(k=0;k<50;k++)
             {
                 ptr[j].name[k]='\0';
             }
             ptr[j].ID='\0';
             ptr[j].salary='\0';
             ptr[j].citnum='\0';
             ptr[j].phnum='\0';
             printf("\t\t\tDone\n\n\n");
             break;
         }
    }

}

void modify(int ID,struct employee *ptr)
{
    int i;

    for(i=0;i<100;i++)
    {
        if((ptr[i].ID)==ID)
        {
            newemp(i,ptr);
        }
    }
}

void print1(int ID, struct employee *ptr)
{
    int i;

    for(i=0;i<100;i++)
    {
        if((ptr[i].ID)==ID)
        {
             printf("employee's name is %s\n\n",ptr[i].name);
             printf("employee's ID is %d\n\n",ptr[i].ID);
             printf("employee's salary is %f\n\n",ptr[i].salary);
             printf("employee's phone number is %d\n\n",ptr[i].phnum);
             printf("employee's city number is %d\n\n",ptr[i].citnum);

        }
    }
}

void print2(char *A,struct employee *ptr)
{
    int k;
    int i;
    int j;
    printf("enter the employee's name:\n");
    scanf("%s",A);
    printf("\n\n");

    for (j=0;j<100;j++)
    {
        int len1=0;
        int len2=0;
        int same=0;
        i=0;
        while(A[i++]!='\0')
        {
            len1++;
        }
        i=0;
        while(ptr[j].name[i++]!='\0')
        {
            len2++;
        }
        if(len1!=len2)
        {
            continue;

        }
        same=1;

        for(i=0;i<len1;i++)
        {
            if(A[i]!=(ptr[j].name[i]))
            {
                same=0;
                i=len1;
                printf("hello12345");
            }

        }

        if (same==1)
         {

             printf("employee's name is %s\n\n",ptr[j].name);
             printf("employee's ID is %d\n\n",ptr[j].ID);
             printf("employee's salary is %f\n\n",ptr[j].salary);
             printf("employee's phone number is %d\n\n",ptr[j].phnum);
             printf("employee's city number is %d\n\n",ptr[j].citnum);
         }
    }
}
void print3(int num,struct employee *ptr)
{
    int i;

    for(i=0;i<100;i++)
    {
        if((ptr[i].phnum)==num)
        {
             printf("employee's name is %s\n\n",ptr[i].name);
             printf("employee's ID is %d\n\n",ptr[i].ID);
             printf("employee's salary is %f\n\n",ptr[i].salary);
             printf("employee's phone number is %d\n\n",ptr[i].phnum);
             printf("employee's city number is %d\n\n",ptr[i].citnum);

        }
    }
}

void swap(struct employee *xp,struct employee *yp)
{
    struct employee temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(struct employee *ptr )
{
    int i, j, min_idx;


    for (i = 0; i < 99; i++)
    {

        min_idx = i;
        for (j = i+1; j < 100; j++)
          if (ptr[j].ID < ptr[min_idx].ID)
            min_idx = j;


        swap(&ptr[min_idx], &ptr[i]);

    }
    printf("\n\n\t\t\tDone\n\n\n");
}

void printall(struct employee *ptr)
{
    int i;
    for(i=0;i<100;i++)
    {
         printf("employee's name is %s\n\n",ptr[i].name);
         printf("employee's ID is %d\n\n",ptr[i].ID);
         printf("employee's salary is %f\n\n",ptr[i].salary);
         printf("employee's phone number is %d\n\n",ptr[i].phnum);
         printf("employee's city number is %d\n\n",ptr[i].citnum);
         printf("\n\n\n\n");
    }
}
