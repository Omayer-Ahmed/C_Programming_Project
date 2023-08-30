#include<stdio.h>

int main()
{

while(1)
{
    printf("\n\n**************Welcome to Food Ordaring System***************");
    printf("\n\n1. Sign up\n\n");
    printf("\n2. Login\n\n");
    printf("\n\nExit");
    printf("\nEnter your choice:");
    scanf("%d ",&choice);
    switch (choice)
    {
    case 1:
       {
        signup();
         break;
       }
    case 2:
       {
          login();
          break;
       }
    case 3:
       {
        printf("\n************Thank you visit again **********\n");
         exit(0);
         return 0;
       }            
        
    
    default:
         printf("\nPleace enter the valid choice");
         break;
    }

}

}

 