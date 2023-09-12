#include<stdio.h>
//user information
struct detailes
{
   char name[100];
   int age;
   char password[100];
   char email[100];
   char mobile[10];
};

//hotel and their food details
struct Hotels
{
   char hotel[100];
   char first_food[20];
   char second_food[20];
   char third_food[20];
   char fourth_food[25];
   int first,second,third,fourth;
};

struct hotels m[5];
struct detailes s[100];
//function prototype
void signup();
void account_check();
int validate();
void login();
void cart();
void search_by_hotels();
void search_by_food();
void food_order(int food);

int flag=1,i,j=0,count=0,caps=0;
int small=0,special=0,numbers=0;
int success=0,x,choice;
char temp_name[100],temp_password1[100];
char temp_password2[100],temp_email[100];
char temp_mobile[100];
int temp_age,total=0,food_choice,n;
int hotel_choice ,search_choice,confirm;
int ch,food,hotel_id;



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
//check whether 
//the user input is valid or not

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

         if(!strcmp(temp_password1,temp_password2))
         {
            if(strlen(temp_password1)>=8 && strlen(temp_password1)<=12)
            {
               caps=0;
               small=0;
               numbers=0;
               special=0;
               for(i=0;temp_password1[i] !='\0';i++)
               {
                  if(temp_password1[i]>='A'&& temp_password1[i]<='Z')
                  
                  caps++;
                  
                  else if(temp_password1[i]>='a'&& temp_password1[i]<='z')
                  
                     small++;
                  
                  else if(temp_password1[i] >='0'&&temp_password1[i]<='9')
                  
                     numbers++;
                  
                  else if(temp_password1[i]=='@' || temp_password1[i]=='&' || temp_password1[i]=='#'|| temp_password1[i]=='*')
                  
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
                              return 1;
                                 
                            }
                            else
                            {
                              printf("\n\nPlease enter the 11 digit mobile number \n");
                              return 0;
                            }
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
                        printf("\nyour password is too short and length would be between 8 to 12\n\n");
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

void account_check()//check whether the account existed or not 
{
   for(i=0;i<100;i++)
   {
     //check email
     //check password
     if(!(strcmp(temp_email,s[i].email)
        && strcmp(temp_password1,s[i].password)))
      {
         printf("\n\nAccount already existed .please login !!\n\n");
         main();
         break;
      }
   }
   //if account doesnot exist
   //then create new one
   if(i==100)
   {
      strcmp(s[j].name,temp_name);
      s[j].age=temp_age;
      strcmp(s[j].password,temp_password1);
      strcmp(s[j].email,temp_email);
      strcmp(s[j].mobile,temp_mobile);
      j++;
      printf("\n\nAccount successfully created \n\n");
   } 
}
//use login function
void login()
{
   printf("\n\n***************Welcome to Login Page**************");
   printf("\tEnter your Email: ");
   scanf("%s",&temp_email);
   printf("\tEnter your password: ");
   scanf("%s",&temp_password1);
   for(i=0;i<100;i++)
   {
      //check whether the input is existed or not 
      if(!strcmp(s[i].email,temp_email))
      {
         if(!strcmp(s[i].password,temp_password1))
         {
         printf("\n\nWelcome %s, ",s[i].name);
         printf("You are successfully");
         printf("Logged in \n\n");
         printf("We provide two ways fo search\n");
         printf("1) Search By Hotels \n");
         printf("2) Search By Food\n");
         printf("3)Exit\n\n");
         printf("Please enter your choice:");
         scanf("%d ",&search_choice);
         
         switch(search_choice)
         {
            case 1:
         {
            search_by_hotels();
            break;
         
         }
           case 2:
           {
            search_by_food();
            break;
           }
           case 3:
           {
            main();
            return;
           }
           default:
           {
            printf("Please enter your valid choice\n\n");
            break;
           }
         }
         break;
         }
         else
         {
            printf("\n\nInvalid password");
            printf("\please enter the correct password\n\n");
            main();
            break;
         }
       }
       else
        {
         printf("\n\nAccount doesnot exist ,\nplease sign up again");
         main();
         break;
        }
   }

}
void hotel_initialize()
{
   //initializating the hotel name ,food and respective cost
   //first hotel 
   strcmp(m[1].hotel,"Kabab Factorary");
   strcmp(m[1].first_food,"Sandwich");
   strcmp(m[1].second_food,"Pizza");
   strcmp(m[1].third_food,"Fried_rice");
   strcmp(m[1],fourth_food,"Ice_Cream");
   m[1].first=150;
   m[1].second=200;
   m[1].third=120;
   m[1].fourth=80;
   
   //second hotel

   strcmp(m[2].hotel,"TakeOut");
   strcmp(m[2].first_food,"Parotta");
   strcmp(m[2].second_food,"Noodles");
   strcmp(m[2].third_food,"Chicken_Rice");
   strcmp(m[2].fourth_food,"Dosa");
   m[2].first=40;
   m[2].second=100;
   m[2].third=200;
   m[2].fourth=120;


   //third hotel
   strcmp(m[3].hotel,"Pizza Hut");
   strcmp(m[3].first_food,"Chicken_Biriyani");
   strcmp(m[3].second_food,"Noodles");
   strcmp(m[3].third_food,"Faloda");
   strcmp(m[3].fourth_food,"Burger");
   m[3].first=220;
   m[3].second=100;
   m[3].third=150;
   m[3].fourth=120;

}
