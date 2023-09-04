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
void signup()
{
   printf("\n\n ***************welcome to signup page************");
   printf("\tEnter your name: ");
   scanf("%s",&temp_name);
   printf("\tEnter your age:");
   scanf("%s",&temp_email);
   printf("\tEnter your password:");
   scanf("%s",&temp_password1);
   printf("\tConfirm password:");
   scanf("%s",&temp_password2);
   printf("\tEnter your phone number:");
   scanf("%d",&temp_mobile);

   x=validate();
   if(x==1)
   {
     account_check();
     login();
   }
}
int validate()
{
 //valid the name
   for(i=0;temp_name[i]!='\0';i++)
   {
      if(!((temp_name[i]>='a' && temp_name[i]<=
      'z')|| (temp_name[i]>='A'&& temp_name[i]<='Z')))
      {
         printf("\nPlease Enter your valid name\n");
         flag=0;
         break;
      }
   }
   if(flag==1)
   {
      count=0;
      //valid the Email

      for(i=0;temp_email[i]!='\0';i++)
      {
         if(temp_email[i]=='@' || temp_email[i]=='.')
         count++;
      }
      if(count >= 2 && strlen(temp_email) >=5)
      {
         //valid password
         //confirm password

         if(!strcmp(stemp_password1,temp_password2))
         {
            if(strlen(temp_password1)>=8 && strlen(temp_password1)<=12)
            {
               caps=0;
               small=0;
               number=0;
               special=0;
               for(i=0;temp_password1[i] !='\0';i++)
               {
                  if(temp_password[i]>='A'&& temp_password1[i]<='Z')
                  {
                  caps++;
                  }
                  else if(temp_password1[i]>='a'&& temp_password[i]<='z')
                  {
                     small++;
                  }
                  else if(temp_password1[i] >='0'&&temp_password1[i]<='9')
                  {
                     numbers++;
                  }
                  else if(temp_password[i]=='@' || temp_password1[i]==& || temp_password1[i]=='#'|| temp_password1[i]=='*')
                  {
                     special++;
                  }
                  if(caps>=1 && small >=1 && numbers >=1 && special >=1)
                  {
                     //valid the input age
                     if(temp_age !=0 && temp_age>0)
                     {
                          //valid phone number
                          if(strlen(temp_mobile)==11)
                            {
                              for(i=0;i<11;i++)
                              {
                                 if(temp_mobile[i]>='0' && temp_mobile[i]<='9')
                                 {
                                    success=1;
                                 }
                                 else
                                  { 
                                     printf("\nGive your valid phone number\n");
                                     return 0;
                                     break;               
                                  }
                              }  
                              if(success == 1)
                              {
                                 return 1;
                              }    
                              else
                              {
                                 printf("\n\nplease enter your valid age\n");
                                 return 0;
                              }   
                            }
                            else
                            {
                              printf("\nplease enter the  ");
                              printf("Use Strong pasword  ");
                              printf("password must contain ");
                              printf("atleast one uppercase ");
                              printf("lowwer case ,number and special char \n\n");

                              return 0;
                            }
                     }
                     else
                     {
                        printf("\nyour password is too short and length would be between 8 to 12"\n\n);
                        return 0;
                     } 
                  }
                  else
                  {
                     printf("\npassword does not match");
                     return 0;
                  }
               }
               else
               {
                  printf("\nplease enter valid email\n\n");
                  return 0;
               }
            }
         }
      }
   }
   
}
