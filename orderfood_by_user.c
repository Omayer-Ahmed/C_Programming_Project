#include<stdio.h>
#include<string.h>
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
struct hotels
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


void hotel_initialize();
void hotels(int hotel_choice);


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
    printf("\n\n1. Sign up\n");
    printf("2. Login\n");
    printf("3. Exit");
    printf("\n\n\nEnter your choice:");
    scanf("%d",&choice);
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
        { 
         printf("\nPleace enter the valid choice");
         break;
        }
     }
   }
 }
void signup()
{
   printf("\n\n ***************welcome to signup page************");
   printf("\n\n\n\tEnter your name: ");
   scanf("%s", temp_name);
   printf("\n\n\tEnter your age:");
   scanf("%d", &temp_age);
   printf("\n\n\tEnter your email:");
   scanf("%s", temp_email);
   printf("\n\n\tEnter your password:");
   scanf("%s", temp_password1);
   printf("\n\n\tConfirm password:");
   scanf("%s", temp_password2);
   printf("\n\n\tEnter your phone number:");
   scanf("%s", temp_mobile);

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
                              printf("at least one uppercase ");
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

//account check 
void account_check()
{

   for(i=0;i<100;i++)
   {
      if(!(strcmp(temp_email,s[i].email)&& strcmp(temp_password1,s[i].password)))
      {
         printf("\n\nAccount already existed.Please login !!");
         main();
         break;
      }
   }

   if(i==100)
   {
      strcpy(s[j].name,temp_name);
      s[j].age=temp_age;
      strcpy(s[j].password,temp_password1);
      strcpy(s[j].email,temp_email);
      strcpy(s[j].mobile,temp_mobile);
      j++;
      printf("\n\nAccount successfully created\n\n");
   }
}
//use login function
void login()
{
   printf("\n\n***************Welcome to Login Page**************");
   printf("\n\n\tEnter your Email: ");
   scanf("%s",temp_email);
   printf("\n\tEnter your password: ");
   scanf("%s",temp_password1);
   for(i=0;i<100;i++)
   {
      //check whether the input is existed or not 
      if(!strcmp(s[i].email, temp_email))
      {
         if(!strcmp(s[i].password, temp_password1))
         {
         printf("\n\nWelcome %s, ",s[i].name);
         printf("You are successfully");
         printf("Logged in \n\n");
         printf("We provide two ways fo search\n");
         printf("1) Search By Hotels \n");
         printf("2) Search By Food\n");
         printf("3)Exit\n\n");
         printf("Please enter your choice:");
         scanf("%d",&search_choice);
         
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
         printf("\n\nAccount doesnot exist ,please sign up again");
         main();
         break;
        }
   }

}
void hotel_initialize()
{
   //initializating the hotel name ,food and respective cost
   //first hotel 
   strcpy(m[1].hotel,"Kabab Factorary");
   strcpy(m[1].first_food,"Sandwich");
   strcpy(m[1].second_food,"Pizza");
   strcpy(m[1].third_food,"Fried_rice");
   strcpy(m[1].fourth_food,"Ice_Cream");
   m[1].first=150;
   m[1].second=200;
   m[1].third=120;
   m[1].fourth=80;
   
   //second hotel

   strcpy(m[2].hotel,"TakeOut");
   strcpy(m[2].first_food,"Parotta");
   strcpy(m[2].second_food,"Noodles");
   strcpy(m[2].third_food,"Chicken_Rice");
   strcpy(m[2].fourth_food,"Dosa");
   m[2].first=40;
   m[2].second=100;
   m[2].third=200;
   m[2].fourth=120;


   //third hotel
   strcpy(m[3].hotel,"Pizza Hut");
   strcpy(m[3].first_food,"Chicken_Biriyani");
   strcpy(m[3].second_food,"Noodles");
   strcpy(m[3].third_food,"Faloda");
   strcpy(m[3].fourth_food,"Burger");
   m[3].first=220;
   m[3].second=100;
   m[3].third=150;
   m[3].fourth=120;

}
//search by hotels
void search_by_hotels()
{
   hotel_initialize();
   printf("\n\nPlease Choose the ");
   printf("hotels \n\n1) %s\n2) %s\n3) %s",
   m[1].hotel,m[2].hotel,m[3].hotel);
   printf("\n4) Exit \n\n Please ");
   printf("select the hotel\t");
   scanf("%d",& hotel_choice);
   if(hotel_choice>4)
   {
   printf("Please enter the valid choice\n\n");
   search_by_hotels();
   }
   else if(hotel_choice==4)
   return;

   else
   hotels(hotel_choice);

}
//function to implement the hotel
void hotels(int hotel_choice)
{
   total=0;
   while(1)
   {
      printf("\n\nList of foods available");

      printf("in %s \n\n1) %s\tTk: %d\n2)",
      m[hotel_choice].hotel,
      m[hotel_choice].first_food,
      m[hotel_choice].first);

      printf("%s\t\tTk: %d\n3) %s\tTk: %d\n4)%s\tTk: %d\n5)",
      m[hotel_choice].second_food,
      m[hotel_choice].second,
      m[hotel_choice].third_food,
      m[hotel_choice].third,
      m[hotel_choice].fourth_food,
      m[hotel_choice].fourth);


      printf("cart\n6) Exit\n\n Please enter ");
      printf("Your choice\t");
      scanf("%d",&food_choice);

      if(food_choice==1)
      {
         printf("Please enter the  ");
         printf("Count of %s\t",
         m[hotel_choice].first_food);
         scanf("%d",&n);
         total=total+(n*m[hotel_choice].first);
      }
      else if(food_choice==2)
      {
         printf("please Enter the count");
         printf("of %s\t",m[hotel_choice].second_food);
         scanf("%d",&n);
         total=total+(n*m[hotel_choice].second);
      }
      else if(food_choice==3)
      {
          printf("please Enter the count");
         printf("of %s\t",m[hotel_choice].third_food);
         scanf("%d",&n);
         total=total+(n*m[hotel_choice].third);
      }
      else if(food_choice==4)
      {
          printf("please Enter the count");
         printf("of %s\t",m[hotel_choice].fourth_food);
         scanf("%d",&n);
         total=total+(n*m[hotel_choice].fourth);
      }
      else if(food_choice==5)
      {
          cart();
      }
      else if(food_choice==6)
      {
         search_by_hotels();
      }
      else
      {
         printf("Please enter the valid choice\n\n");
      }
   }

}

void search_by_food()
{
   total =0;

   hotel_initialize();
   while(1)
   {
      printf("\n\nPleace Choose the ");
      printf("food\n\n1) %s\t%d\n2) %s\t%d",
      m[1].first_food,m[1].first,
      m[1].second_food,m[1].second);

    
      printf("\n3) %s\t%d\n4) %s\t%d\n",
      m[1].third_food,m[1].third,
      m[2].first_food,m[2].first);

      printf("5) %s\t%d\n6) %s\t%d\n",
      m[2].second_food,m[2].second,
      m[2].third_food,m[2].third);

      printf("7) %s\t%d\n8) %s\t%d\n",
      m[3].first_food,m[3].first,
      m[3].second_food,m[3].second);

      printf("9) %s\t%d\n10) cart\n",
      m[3].third_food,
      m[3].third);

      printf("11) Exit");
      printf("\nPlease enter your choice\t");
      scanf("%d",&food);

      if(food>10)
      {
         printf("Please enter the ");
         printf("valid choice\n\n");
         search_by_food();
      }
      else if(food==10)
      cart();
     
     else if(food==11)
     return;

     else

     food_order(food);
   }

}
//food order 
void food_order(int food)
{
   if(food>=1 && food<=3)
   hotel_id=1;

  else if (food>=4 && food<=6)
  hotel_id=2;
  
  else
  hotel_id=3;

  if((food % 3)==1)
  {
   printf("Please enter the count of %s\t",
   m[hotel_id].first_food);
   scanf("%d",&n);
   total=total+(n*m[hotel_id].first);
  }
  else if((food % 3)==2)
  {
   printf("Please enter the count of %s\t",
   m[hotel_id].second_food);
   scanf("%d",&n);
   total=total+(n*m[hotel_id].second);
  }
  else if((food % 3)==0)
  {
   printf("Please enter the count of %s\t",
   m[hotel_id].third_food);
   scanf("%d",&n);
   total=total+(n*m[hotel_id].third);
  }

}
void cart()
{
   printf("\n\n\n\n*****************cart*************");
   printf("\nYour total order");
   printf(" Amount is: %d\n",total);
   printf("\n\nDo you wish to");
   printf("order (y=1/n=0): ");
   scanf("%d",&ch);
   if(ch==1)
   {
      printf("\n\nThank you for your order ");
      printf(" .Your food is on the way .welcome again\n\n");
      return;
   }
   else if(ch==0)
   {
      printf("Do you want to exit=-1");
      printf("or Go back =0");
      scanf("%d",&confirm);
      if(confirm==1)
      {
         printf("\n\noop ! your order is cancelled !! Exiting.....");
         printf("\nThank you visit again!\n");
         return;
      }
      else 
      {
         printf("\n\nThank you\n\n");
         login();
      }
   }
   else
   {
      printf("\n\nPlease enter the correct choice");
      cart();
   }
}
