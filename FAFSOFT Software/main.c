
#include <stdio.h>
#include<stdlib.h>
#include "header.h"




int main()
{


    int choice;//Here is the users's choice variable
    int call;//Here is the variable which is used for the GOTO statement in my program
    int log; //Here is the login variable
    int passwordlog;//Here is the login password which will be tested with the temp
    int password;//Here is the variable for password
    int cmpassword;//Here is the variable used to conform that the two password match

//Here is the login menu
    system("COLOR E");//Here i change the colour of the text
    logg:
    login_menu();
    scanf("%d", &log);

    while((log!=1) & (log!=2))
    {
        printf("\n\n\t\t\t\tERROR PLEASE TRY AGAIN: ");
        scanf("%d", &log);
    }

    switch(log){

    case 1:
    printf("\n\t\t\t\t\t\tCreate new PASSWORD here NOTE [Must be numeric]\n\n\n");
    printf("\n\t\t\t\tEnter password: ");
    scanf("%d", &password);//Here i scan the first password entered

    printf("\n\t\t\t\tConfirm Password[Numeric]: ");
    scanf("%d",&cmpassword);//Here i scan the second password entered

    if(password != cmpassword){//Here i simply compare the first password entered and the second password entered

        do{
            printf("\n\t\t\t\tPassword doesn't match\n\n");
            printf("\n\t\t\t\tTRY AGAIN[Numeric]: ");
             scanf("%d", &cmpassword);
        }while(password != cmpassword);//If the passwords are not the same the user will enter the above do loop and only come out when the two passwords are the same
    }

        printf("\n\n\t\t\tSave Successful");

     printf("\n\n\t\t\tEnter '0' to return : "); //Here is my goto block
        scanf("%d", &call);

        while(call != 0){
                printf("\n\t\t\tPlease enter '0' and try again: ");
            scanf("%d", &call);
        }

            if(call == 0){ //Here i test for the value inputed if the value is '0' it will go back to The Main menu
                goto logg;
            }




    break;

//Here is the login option
    case 2:
    printf("\n\n\n\t\t\t\tLOGNIN here!!!");
    printf("\n\n\n\t\t\t\tEnter your PASSWORD to login to your session[Max length 10]: ");
    scanf("%d", &passwordlog);


    if(password != passwordlog){//Here i compare the password user sign up with and the new password used in logging in with
        do{
            printf("\n\t\t\t\tWrong PASSWORD, please try AGAIN: ");
            scanf("%d", &passwordlog);
        }while(password != passwordlog);
    }

    break;
    }


     mainm://Here is the main menu label which is used to come back to main menu
    main_menu(); //Here i call for the function main_menu in my header file
    scanf("%d", &choice);

    while((choice!=1) & (choice!=2) & (choice!=3) & (choice!=4) & (choice!=5) & (choice!=6))
    {
        printf("\n\n\t\t\t\tPlease select a valid option form the above Menu: ");
        scanf("%d", &choice);
    }

  switch(choice)
  {
      case 1:
    printf("\n\n\n\n\n\n\n\t\t\t\tREGISTER NEW CRIME"); //Heading of the Register new crime session
    printf("\n\t\t\t\t------------------\n\n\n\n\n\n\n");

      typedef struct dateofin{
        int day;
        int month;
        int year;
        }dateofin;

    typedef struct cases{
            int casenum;//This is the case number
            char casename[50]; //The crime which has been committed
            char name[50]; //The name of the victim
            int phonenum[50]; //The phone number of victim
            int age; //the age of the victim
            char sex[50]; //The sex of the victim
            char place[50]; //The place where the incidence occurred
            char reg[50];//Here we have the region
            dateofin date;//Here my new type is dateofin which is used
        }cases;
//This is the record above for the general informations


    FILE* fp; //Here i create a file pointer
    fp= fopen("Data.txt", "a"); //The file pointer is called data

    cases tab[100];//Array of 100
    int i, n;
    fprintf(fp,"\n\n\t\t\t------------------------------------------ ");
    printf("\n\n\t\t\tLOADING... ");//Heading in file Data.txt
    printf("\n\n\t\t\tHow many Cases do you wish to register: ");//Getting the number so to know how many loops will be performed
    scanf("%d", &n);
    if((n>=101) | (n<=0)){ //Here we are are testing for the value of n if true we enter the loop
   do
   {
       printf("\n\n\t\t\tEnter a value between 0 and 100: ");
       scanf("%d", &n);//The value of n will be replaced each time till it is between 1 and 100
   }while((n>=101) | (n<=0));//The loop won't stop until user enters value between 1 and 100
    }
        for(i=1;i<=n;i++)//Here we loop n times according to the value entered by user
    {

    printf("\n\n\t\t\t\t=>> Enter case number: ");//Displayed on screen not in file
    scanf("%d",&tab[i].casenum); //Reading value
    fprintf(fp,"\nCase number: %d",tab[i].casenum);//Writing in file

    printf("\n\t\t\t\tEnter case name,e.g Theft, gambling: ");//Displayed on screen not in file
    scanf("%s",&tab[i].casename);//Reading value
    fprintf(fp,"\nCase name: %s",tab[i].casename);//Writing in file


     printf("\n\t\t\t\tEnter Victim name: ");//Displayed on screen not in file
     scanf("%s",&tab[i].name);//Reading value
      fprintf(fp,"\nVictim name: %s",tab[i].name);//Writing in file

      printf("\n\t\t\t\tEnter phone number: ");//Displayed on screen not in file
    scanf("%d",&tab[i].phonenum);//Reading value
    fprintf(fp,"\nPhone number: +237 %d",tab[i].phonenum);//Writing in file

     printf("\n\t\t\t\tEnter age: ");//Displayed on screen not in file
     scanf("%d",&tab[i].age);//Reading value
      fprintf(fp,"\nAge: %d",tab[i].age);//Writing in file

    printf("\n\t\t\t\tEnter gender. Male of Female: ");//Displayed on screen not in file
     scanf("%s",&tab[i].sex);//Reading value
    fprintf(fp,"\nGender : %s",tab[i].sex);//Writing in file

      printf("\n\t\t\t\tEnter place of incidence: ");//Displayed on screen not in file
     scanf("%s",&tab[i].place);//Reading value
      fprintf(fp,"\nPlace: %s",tab[i].place);//Writing in file

      printf("\n\t\t\t\tRegion of incidence: ");//Displayed on screen not in file
    scanf("%s",&tab[i].reg); //Reading value
    fprintf(fp,"\nRegion of incidence: %s",tab[i].reg);//Writing in file

      printf("\n\t\t\t\tEnter date of incidence below...");
      fprintf(fp,"\nDate information below...");

      printf("\n\t\t\t\tDay: ");
      scanf("%d",&tab[i].date.day);//Here i read the day and store in the the record cases and again in dateofin(record)

    //In this if statement i try to control the value the user enters which most be between 1 to 31
      if((tab[i].date.day >= 32) | (tab[i].date.day <= 0)){
        do{
            printf("\n\t\t\t\tInvalid! please Day must be between 1 and 31: ");
            scanf("%d",&tab[i].date.day);
        }while((tab[i].date.day >= 32) | (tab[i].date.day <= 0));
      }

      fprintf(fp,"\n\t\tDay: %d",tab[i].date.day);//Now here we are sure that as the user gets out of the above loop he most have had a value between 1 and 31 so we store in the file

      printf("\n\t\t\t\tMonth: ");
      scanf("%d",&tab[i].date.month);//Here i do same but store it in the record cases under date, in dateofin with name month and type char

       //In this if statement i try to control the value the user enters which most be between 1 to 12
      if((tab[i].date.month >= 13) | (tab[i].date.month <= 0)){
        do{
            printf("\n\t\t\t\tInvalid! please Month must be between 1 and 12: ");
            scanf("%d",&tab[i].date.month);
        }while((tab[i].date.month >= 13) | (tab[i].date.month <= 0));
      }
//Now here we are sure that as the user gets out of the above loop he most have had a value between 1 and 12 so we stare in the file

//Here is  the if statement that will write in file the direct month of the year when the user just enters the month number
      if(tab[i].date.month == 1){
        fprintf(fp,"\n\t\tMonth: January");
          } else if(tab[i].date.month == 2){
             fprintf(fp,"\n\t\tMonth: February");
                } else if(tab[i].date.month == 3){
                    fprintf(fp,"\n\t\tMonth: March");
                    } else if(tab[i].date.month == 4){
                        fprintf(fp,"\n\t\tMonth: April");
                        } else if(tab[i].date.month == 5){
                             fprintf(fp,"\n\t\tMonth: May");
                            } else if(tab[i].date.month == 6){
                                fprintf(fp,"\n\t\tMonth: June");
                                } else if(tab[i].date.month == 7){
                                    fprintf(fp,"\n\t\tMonth: July");
                                    } else if(tab[i].date.month == 8){
                                        fprintf(fp,"\n\t\tMonth: August");
                                        } else if(tab[i].date.month == 9){
                                            fprintf(fp,"\n\t\tMonth: September");
                                            } else if(tab[i].date.month == 10){
                                                fprintf(fp,"\n\t\tMonth: October");
                                                } else if(tab[i].date.month == 11){
                                                   fprintf(fp,"\n\t\tMonth: November");
                                                    } else{
                                                        fprintf(fp,"\n\t\tMonth: December");
                                                        }
//Here we will test all the if's above and if it matches we will do that particular statement



      printf("\n\t\t\t\tYear: ");
      scanf("%d",&tab[i].date.year);//Here i do same
      fprintf(fp,"\n\t\tYear: %d\n\n\n",tab[i].date.year);

     printf("\t\t\t\t----------------------------------------");
      fflush(fp);
    }
        printf("\n\n\t\t\tSaving information...\n\n ");
        printf("\n\n\t\t\tEnter '0' to go back to 'Main menu': "); //Here is my goto block
        scanf("%d", &call);

        while(call != 0){
                printf("\n\t\t\tInvalid entry please enter '0' and try again: ");
            scanf("%d", &call);
        }

            if(call == 0){ //Here i test for the value inputed if the value is '0' it will go back to The Main menu
                goto mainm;
            }


      break;

      case 2:
        printf("\n\t\t\tFetching Data...\n\n ");


    printf("\n\n\n\n\n\t\t\t\tVIEW REGISTERED CASES"); //Heading of the Register new crime session
    printf("\n\t\t\t\t---------------------\n\n\n\n\n\n\n");

      int c;
      FILE *file; //Here i declare another file pointer which i will use to go through the file to get and display the entire values
      file= fopen("Data.txt", "r");//Here i open the file which is already existing at th same time i'm giving the execution right to the file
      if(file) {
        while((c = getc(file)) != EOF)
            putchar(c);
        fclose(file);
      }

        printf("\n\n\t\t\tEnter '0' to go back to 'Main menu': "); //Here is my goto block
        scanf("%d", &call);

        while(call != 0){
            printf("\n\t\t\tInvalid entry please enter '0' and try again: ");
            scanf("%d", &call);
        }

            if(call == 0){ //Here i test for the value inputed if the value is '0' it will go back to The Main menu
                goto mainm;
            }


      break;

      case 3:

          //Here we open the file in Write Mode and it enables us to close it without actually writing anything in it hence we have cleaned all data.
       printf("\n\n\n\n\n\n\n\t\t\t\tDELETE ALL CASE"); //Heading of the About FAFPSOFT session
    printf("\n\t\t\t\t-----------------\n\n\n\n\n\n");


     printf("\n\n\n\t\t\t\tPlease NOTE that by validating YOU will clean ALL data you entered!!!\n");//Here below we make sure The users really wishes to quit
        printf("\n\t\t\t\tEnter '1' to CLEAN OR '0' to cancel and go back to Main menu: ");
        scanf("%d", &call);

        while((call != 0) & (call != 1)){//Here i try to control the value of call in such a way that it will enter the loop if user enters a value which is not '0' OR '1'
            printf("\n\t\t\tInvalid command, please enter '0' OR '1' and try again: ");
            scanf("%d", &call);
        }
            //Here, we are sure that as we come out of the loop we will have either a '0' or a '1'
            if(call == 0){ //Here i test for the value inputed if the value is 0 it will go back to The Main menu else it will exit
                goto mainm;
            } else{
             printf("\n\n\n\t\t\t\t\tACTION WAS SUCCESSFULL!!!\n\n\n\n\n");

                FILE* sc; //Here i create a new file pointer
                sc= fopen("Data.txt", "w+"); //The file pointer is called data
            }

     printf("\n\n\t\t\tLOADING...\n\n ");
        printf("\n\n\t\t\tEnter '0' to go back to 'Main menu': "); //Here is my goto block
        scanf("%d", &call);

        while(call != 0){
            printf("\n\t\t\tInvalid entry please enter '0' and try again: ");
            scanf("%d", &call);
        }

            if(call == 0){ //Here i test for the value inputed if the value is '0' it will go back to The Main menu
                goto mainm;
            }

      break;

      case 4:
     printf("\n\n\n\n\n\n\n\t\t\t\tABOUT FAFPSOFT"); //Heading of the About FAFPSOFT session
    printf("\n\t\t\t\t---------------\n\n\n\n\n\n");
    printf("\n\t\t\t\tDESCRIPTION\n");
    printf("\n\t\t\t\tWelcome to FAFPSOFT police station management\n");
    printf("\n\t\t\t\tFAFPSOFT is a full-featured software aimed at facilitating and helping individuals to work\n");
    printf("\n\t\t\t\tbetter in a numeric world. It is a software that is programed to manage a police station.\n\n\n");
    printf("\n\t\t\t\t----------------------------------------------------------------------------\n\n\n\n");
    printf("\n\n\t\t\t\tINFORMATION\n");
    printf("\n\t\t\t\tNAME: FAFSOFT\n");
    printf("\n\t\t\t\tYEAR OF CREATION: 2018\n");
    printf("\n\t\t\t\tAUTHOR: The FAFPSOFT Team(GROUP ONE)\n");
    printf("\n\t\t\t\t\t\t\t\t\tDIRECTED BY: MR. FOTSA\n");
    printf("\n\t\t\t\t----------------------------------------------------------------------------\n\n");
    printf("\n\t\t\t\tThanks to...\n\n\n");
    printf("\n\t\t\t\tDEVELOPERS\n");
    printf("\n\t\t\t\tFOTIE MOGHOMMAHIE CONSTANT - project leader\n");
    printf("\n\t\t\t\tFANTCHO PAUL\n");
    printf("\n\t\t\t\tANZAMA ELIZABETH\n\n\n");
    printf("\n\t\t\t\t----------------------------------------------------------------------------\n\n\n\n");
    printf("\n\t\t\t\tLICENSE\n");
    printf("\n\t\t\t\tThis software is not to be copied without the legal authorization of the above developers\n");
    printf("\n\t\t\t\t\t\t\t\tThank you for using FAFPSOFT to manage your police station\n\n\n\n");


         printf("\n\n\t\t\tEnd of Page...\n\n ");
        printf("\n\n\t\t\tEnter '0' to go back to 'Main menu': "); //Here is my goto block
        scanf("%d", &call);

        while(call != 0){
            printf("\n\t\t\tInvalid entry please enter '0' and try again: ");
            scanf("%d", &call);
        }

            if(call == 0){ //Here i test for the value inputed if the value is '0' it will go back to The Main menu
                goto mainm;
            }


    break;


      case 5:
     printf("\n\n\n\n\n\n\n\t\t\t\tHELP"); //Heading of the About FAFPSOFT session
    printf("\n\t\t\t\t-------\n\n\n\n\n\n");
    printf("\n\t\t\t\tSearching for help...\n\n");

    printf("\n\t\t\t\tWelcome to the help option, to use this software you will have to go through the following... \n");
    printf("\n\t\t\t\t In this software we have six(6) options in the main menu which are listed below; \n");
     printf("       =>    1.  Register new case                                              \n");
     printf("\n\t\tHere, you have the possibility to add a new case in the database and at any time. you just have to follow the steps provided by the program\n");

    printf("\n\n       =>    2.  View registered cases                                                  \n");
    printf("\n\t\tHere you will have the possibility to view the registered cases in the database just by following the steps of the program\n\n");

    printf("\n\n       =>    3.  Delete cases                                                 \n");
    printf("\n\t\tHere you will be able to delete cases\n\n");

    printf("\n\n       =>    4.  About FAFPSOFT                                                  \n");
    printf("\n\t\tHere you will have the possibility to view the Developers of the software and the Coordinator of the project which is 'MR FOTSA'\n");

    printf("\n\n       =>    5.  Help                                                 \n");
    printf("\n\t\tHere is the Help menu. were you are now!!! Here you get supports about the subject\n\n");

    printf("\n\n       =>    6.  Exit                                                 \n");
    printf("\n\t\tHere you will just have to exit the program\n\n");

     printf("\n\n\t\t\tEnd of Page...\n\n ");
       printf("\n\n\t\t\tEnter '0' to go back to 'Main menu': "); //Here is my goto block
        scanf("%d", &call);

        while(call != 0){
            printf("\n\t\t\tInvalid entry please enter '0' and try again: ");
            scanf("%d", &call);
        }

            if(call == 0){ //Here i test for the value inputed if the value is '0' it will go back to The Main menu
                goto mainm;
            }

      break;

      case 6:
        printf("\n\n\n\t\t\t\tAre you sure you want to Exit the program?\n");//Here below we make sure The users really wishes to quit
        printf("\n\t\t\t\tEnter '1' to Exit OR '0' to cancel and go back to Main menu: ");
        scanf("%d", &call);

        while((call != 0) & (call != 1)){//Here i try to control the value of call in such a way that it will enter the loop if user enters a value which is not '0' OR '1'
            printf("\n\t\t\tInvalid, please enter '0' OR '1' and try again: ");
            scanf("%d", &call);
        }
            //Here, we are sure that as we come out of the loop we will have either a '0' or a '1'
            if(call == 0){ //Here i test for the value inputed if the value is 0 it will go back to The Main menu else it will exit
                goto mainm;
            } else{
            printf("\n\t\t\tWe are so sad to see you go and we hope to see you again");
             printf("\n\n\n\n\t\t\t\t\tPress any key to Exit!!!\n\n\n\n\n");
            }

    break;


    return 0;
      }

    }

