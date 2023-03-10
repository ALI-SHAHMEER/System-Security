#include<stdio.h>
#include<time.h>
#include <string.h>

void start_time()
{
    FILE * fptr;
    char * time_now;
    char str[100]={0};
    time_t t;
    fptr = fopen("log.txt","a");    
    time(&t);
    fprintf(fptr,"\nLogin in time = %s",ctime(&t));
    printf("%s", ctime(&t));
    fclose(fptr);
}
void end_time()
{
    FILE * fptr;
    char * time_now;
    time_t t;
    char str[100]={0};

    fptr = fopen("log.txt","a");
    
    time(&t);
    fprintf(fptr,"\nLogged out time = %s",ctime(&t));
    printf("%s", ctime(&t));
    fclose(fptr);
}
void user_register()
{
    FILE * fname;
    FILE * fpassword;
    char name[50]={0},password[50]={0};
    fname = fopen("user.txt","a");
    fpassword = fopen("password.txt","a");
    printf("Enter Username To Register:");
    scanf("%s", name);

    
    printf("Enter Password To Password:");
    scanf("%s",password);
    
    fputs(name,fname);
    fputs(password,fpassword);
}

int user_check(char username[])
{
    char line[200];
    FILE *fptr=fopen("user.txt","r");
    if(fptr == NULL)
    {
        printf("invalid");
    }
    
    while (!feof(fptr))
    {
        fgets(line,200,fptr);
        line[strcspn(line, "\n")] = 0;

        if(strcmp(username,line) == 0)
        {
            printf("\nValid User");
        }
    }

    fclose(fptr);
}

void password_check(char userpassword[])
{
    char line[300];
    FILE *fptr=fopen("password.txt","r");
    if(fptr == NULL)
    {
        printf("invalid");
    }
    
    while (!feof(fptr))
    {
        fgets(line,300,fptr);
        line[strcspn(line, "\n")] = 0;

        if(strcmp(userpassword,line) == 0)
        {
            printf("\nValid Password");
        }
    }

    fclose(fptr);
}

void encryptfile(char fileinput[],char fileoutput[])
{
    FILE * input, * output;
    char ch;
    input = fopen(fileinput,"r");
    output = fopen(fileoutput,"w");
    do{
        ch = fgetc(input);
        fputc(ch+3,output);
    }while (ch!=EOF);
    printf("Encryption is completed in your file\n");
}
void dencryptfile(char fileinput[],char fileoutput[])
{
    FILE * input, * output;
    char ch;
    input = fopen(fileinput,"r");
    output = fopen(fileoutput,"w");
    ch = fgetc(input);
    while (ch != EOF)
    {
        fputc(ch - 3, output);
        ch = fgetc(input);
    }
    printf("Dencryption is completed in file.\n");
}



int main()
{
    int i=1,j=1,choice;
    char user[50];
    char password[200];
    start_time();
    long int login_password = 5459;
    long int user_password;
    printf("Enter Login Password:\n");
    scanf("%d", &user_password);
    // for(i=0;i<3;i++)
    // {
    //     if(login_password != user_password)
    //     {
    //         printf("Invalid login password");
    //         j++;
    //     }
    //     else if(login_password == user_password){
    //         printf("Valid login password");
    //         break;
    //     }
    // }
    while (i<3)
    {
        if(login_password != user_password)
        {
            printf("Invalid login password\n");
            printf("Try %d wrong\n", j);
            scanf("%d", &user_password);
            i++;
            j++;
        }
        else if(login_password == user_password){
            printf("Valid login password");
            break;
        }
    }
    
    printf("%d", i);
    if(i >= 2)
    {
        
    }
    if(i>=3){
        system("/home/wolf/Desktop/C-project/command/lock.sh");
        return 0;
    }
    printf("\t\tADVANCE VAULT SYSTEM\n");
    printf("\t\tPress 1 To register user\n");
    printf("\t\tPress 2 To check user is valid\n");
    printf("\t\tPress 3 To check password is valid\n");
    printf("\t\tPress 4 To Insert data into a file\n");
    printf("\t\tPress 5 To Encrypt data of a file\n");
    printf("\t\tPress 6 To Dencrypt data of a file\n");
    scanf("%d", &choice);
    if(choice == 1)
    {
        user_register();
    }
    else if(choice == 2)
    {
        printf("Enter username:\n");
        gets(user);
        user_check(user);
    }
    else if(choice == 3)
    {
        printf("\nEnter password:\n");
        gets(password);
        password_check(password);
    } 
    else if(choice == 4)
    {
        int i,n;
        FILE * fptr;
        char filename[30], str[300];
        printf("Enter number of lines to store data");
        scanf("%d", &n);
        printf("Enter file name to insert data:");
        gets(filename);
        fptr = fopen(filename,"w");
        for(i=0;i<n+1;i++);
        {
            fgets(str,300,stdin);
            fputs(str,fptr);
        }
        fclose(fptr);
    }
    else if(choice == 5)
    {
        FILE * fptrinput, *fptroutput;
        char fileinput[30], fileoutput[30];
        printf("Enter file name to Encrypt data:");
        gets(fileinput);
        printf("\nEnter file name to Dencrypt data:");
        gets(fileoutput);
        encryptfile(fileinput,fileoutput);
    }
    else if(choice == 6)
    {
        FILE * fptrinput, *fptroutput;
        char fileinput[30], fileoutput[30];
        printf("Enter file name to Decrypt data:");
        gets(fileinput);
        printf("\nEnter file name to Encrypt data:");
        gets(fileoutput);
        dencryptfile(fileinput,fileoutput);
    }
    
    // user_register();
    // printf("Enter username:\n");
    // gets(user);
    // user_check(user);
    // printf("\nEnter password:\n");
    // gets(password);
    // password_check(password);    
    // encryptfile();
    
    end_time();
    return 0;
}