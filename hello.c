#include<stdio.h>
#include<string.h>
#include<windows.h>
int main()
{
    char *p[]={
        "sidharth",
        "xyz@t tiranga",
        "abhay chandra"
    };

    // printf("%c",p[1][16]);
    // printf("\n%d",p[1][15]);

    int i,j;
    int siz=sizeof(p)/sizeof(p[0]);
    for(i=0;i<13;i++){
        for(j=0;j<siz;j++){
            if(i<strlen(p[j])){
                printf("%c",p[j][i]);
            }else{
                printf(" ");
            }
            Sleep(150);
            if(j!=siz-1){
                // printf("*");
                printf("\33[1B");
                printf("\33[1D");
            }
            // if(p[j][i]!=j){
            // }
        }
        if(i==13-1) break;
        // break;
        // j=1;
        // while(j<3){
        // printf("\33[1C");
        for(j=1;j<siz;j++){
            // printf("\33[1A");
            printf("\33[1A");
        }
        //     j++;
        // }
    }
    // printf("***");
    return 0;
}
    // int c=0,i;
    // //printf("\33[s");
    // while(p[c]){
    //     for(i=0;i<strlen(p[c]);i++){
    //         // printf("\33[1B");
    //         // printf("\33[s");
    //         // printf("\33[1A");
    //         printf("%c",*(p[c]+i));
    //         Sleep(150);
    //         if(i==strlen(p[c])-1){
    //             break;
    //         }
    //         printf("\33[1B");
    //         //printf("\33[u");
    //         printf("\33[1D");
    //     }
    //     if(c==sizeof(p)) break;
    //     i=1;
    //     while(i<sizeof(p)){
    //         printf("\33[1A");
    //         i++;
    //     }
    //     //printf("\33[1C");
    //     // p++;
    //     c++;
    // }
    // //printf("\n\n\nHello");