#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
// #include <errno.h>
#include <stdbool.h>

// Error handle
#define try bool __HadError=false;
#define catch(x) ExitJmp:if(__HadError)
#define throw(x) {__HadError=true;goto ExitJmp;}

// Colors
#define RED   "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW   "\x1B[33m"
#define BLUE   "\x1B[34m"
#define MAGENTA   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHITE   "\x1B[37m"
#define RESET "\x1B[0m"


int main(){
    //clear screen
    // try{

    //     system("clear 2>null");
    //     throw();
    // }   

    // catch() {
    //     system("cls 2>null");
    // }

    // variables
    char ask;
    char name[30];
    char l_name[35];
    int *age ;
    int *number;
    char loc[200];
    char pass[100];
    char bul;
    FILE *file;

    //allocate memory
    age = (int*)calloc(40 , sizeof(int));
    number = (int*)calloc(80 , sizeof(int));
    

    // start
    // printf(GREEN "======================= welcome to data base app ===========================" RESET);   

    // printf("\n\nWant to find User or Create (f/c) : ");
    // scanf("%c" , &ask);

    // while (getchar() != '\n')
    // printf("");

    // if (ask == 'c'){

    printf("\n\nEnter user name : ");
    fgets(name , sizeof(name) , stdin);

    printf("\nEnter last name : ");
    fgets(l_name , sizeof(l_name) , stdin);
    
    printf("\nEnter User age : ");
    scanf("%d" , &age);

    printf("\nEnter User phone number : ");
    scanf("%d" , &number);
    
    while (getchar() != '\n')
    printf("");

    printf("\nEnter User address : ");
    fgets(loc , sizeof(loc) , stdin);
    
    printf("\nEnter User pass : ");
    scanf("%s" , &pass);

    printf("\n==========================================");
    printf("\nYou entered for user name is >> %sYou entered for last name is >> %sUser pass is >> %s" , name ,l_name , pass);    
    printf("\n==========================================");

    while (getchar  () != '\n')
    printf("");
    
    printf("\n\nWant to save it (y/n) : ");
    bul = getchar();    

    if(bul == 'y' | bul == 'Y'){
        file = fopen("User.txt" , "a");
        
        fprintf(file , "\n=====================================================\n");
        fprintf(file , "Username : %s" , name);
        fprintf(file , "\nLast name : %s" , l_name);
        fprintf(file , "Age : %d" , age);
        fprintf(file , "\nNumber : %d" , number);
        fprintf(file , "\nAddress : %s" , loc);
        fprintf(file , "Password : %s" , pass);
        fclose(file);

        printf("\nsaved in User.txt file");
    }
    else if (bul == 'n' | bul == 'N')
    {
        exit(1);
    }
    

    // if ask c 

    //variable
    // FILE *find;
    // char f_user[25];
    // char pwd[25];

    // if (ask == 'f'){
        // printf("\nWhich user want to search : ");
        // fgets(f_user , sizeof(f_user) , stdin);


        // find = fopen("User.txt" , "r");

        // if (find == NULL){
        //     printf("You didnt add any user to file");
        //     exit(1);
        // }

        
        // if(fscanf(find , "%s" ,f_user)){
        //     printf("\nEnter password : ");
        //     fgets(pwd , sizeof(pwd) , stdin);
            
        //     if(fscanf(find , "%s" , pwd)){
        //         printf("hey");
        //     }
        // }   

        // else{
        //     printf("couldnt find any user !");
        // }
         
        // fclose(find);

    //if ask f

    return 0;
}//main