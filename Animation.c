/*===========================================*
 |  Created by:      Sidharth,Golu,suraj     |
 |  Group Project:   Amezing Animation       |
 |  Start Date:      28-05-2025              |
 |  Finish Date:     29-05-2025              |
 |  Course:          BCA                     |
 *===========================================*/
#include <stdio.h>  /* for standerd I/O functions */
#include<string.h>  /* for string related funcions */
#include<windows.h> /* for sleep function */
#include<conio.h>   /* for hold screen */

#define UP "\33[1A" /* Move cursor up 1 line */
#define DN "\33[1B" /* Move cursor down 1 line */
#define RT "\33[1C" /* Move cursor right 1 colume */
#define LT "\33[1D" /* Move cursor left 1 colume */

void correctint(int *integer);  /* prototype */

int main(){
    start:
    system("cls");  /* Clear terminal screen */

    printf("\33[1;3;34m\n\t\tANIMATION\n");
    printf("\33[31m\nNote:\33[3;36m\tThis Program Takes Strings And,");
    printf("\n\tPrint Strings with an Animation \33[0m");
    /* Some massages print in terminal with style */

    int i,j,element,maxlen=0,no_of_string,len;
    char *p,str[40];
    /*
        i,j = for loop controling and data accessing
        elements = number of Rows present in pointer string
        maxlen = used for find maximum lenght of structure
        no_of_string = is number of string user want
        len = lenght of user entered string
        *p = dynamicly memory allocation and data swaping
        str[40] = used to store string temprorily
    */
    Sleep(2000);    /* pause screen for 2 sec */
    printf("\33[1;3m\n\nHow Many Strings Do you want: ");
    correctint(&no_of_string);  /* Ask the User to Number of strings */

    if(no_of_string<=0){
        printf("\33[1;3;31m\nThis is not valid! ");
        printf("\33[37m\nPress Any key to return ");
        getch();
        goto start;
    }/* check number 0 or nagative */
    printf("\n");   /* for formating */

    char *strings[no_of_string];
    /* *strings[] = All the data will store in this */

    for(i=0;i<no_of_string;i++){    /* Loop until Number of strings */
        printf("Enter String [%d]: ",i+1);
        scanf(" %[^\n]",str);   /* Ask and store string to str[] temprarily */
        
        len=strlen(str);    /* Find lenght of string */

        p=(char*)malloc(len+1);
        /* Dynamicaly allocate memory size of lenght + 1 is for '\0' */
        if(p==NULL){
            printf("\33[1;31m\nMemory Allocation Error!");
            getch();
            goto start;
        }/* Check Memory Allocate or not */

        strcpy(p,str);  /* Copy entire string to pointer p */
        strings[i]=p;   /* Give adress of p to Strings[i] */
    }
    printf("\33[36m\nPress any key to see Result\33[33m:) ");
    getch();
    printf("\33[0m\n");   /* For formating and Reset colour */

    element=sizeof(strings)/sizeof(strings[0]);
    /* i.e  element= no_of_string*4(byte) / 4(byte) */
    
    for(i=0;i<element;i++){
        maxlen=strlen(strings[i])>maxlen?strlen(strings[i]):maxlen;
    }/* find maximum length of string */

    system("cls");  /* clear scrren */
    printf("\33[1;3;34m\n\t\tANIMATION\n\n"); /* Title */

    for(i=0;i<maxlen;i++){  /* loop run until maxlength */

        for(j=0;j<element;j++){ /* loop run until no of elements */

            if(i<strlen(strings[j])){ /* check value present or not at the index */
                printf("\33[1;3;%dm",31+j%7);   /* Set diffrent colour in diffrent time*/
                printf("%c",strings[j][i]);   /* print charector */
            }
            else{  /* if value not present */
                printf(" "); /* print space */
            }

            Sleep(50);  /* Hold screen for 50 miliseconds */

            if(j!=element-1){   /* if print last Row don't change cursor position */
                printf(DN); /* Move cursor to down */
                printf(LT); /* Move cursor to left */
            }
        }

        if(i==maxlen-1) break;  /* if print last Colume don't change cursor posiotion */

        for(j=1;j<element;j++){ /* change position until first Row */
            printf(UP); /*Move cursor to up */
        }
    }
    printf("\33[0m\n");   /* Reset the colour */
    getch();    /* hold screen */
    return 0;
}

/* Verify integer */
void correctint(int *integer){
    char c;
    while(1){   /* infinite Loop */
        if(scanf("%d%c",integer,&c)==2 && c=='\n'){
            break;
        }/* check user enter integer only or not */
        else{
            printf("\33[1;3;31m\nThis is not valid! ");
            printf("\33[37m\nPlese, retry... : ");
            while((c=getchar())!='\n');   /* take stored value in buffer */
        }
    }
}