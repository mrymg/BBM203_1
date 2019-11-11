#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//      LINE COUNT
int lineCount(const char *filename)
{
    int ch = 0;
    int count = 1;
    FILE *fileHandle;

    if ((fileHandle = fopen(filename, "r")) == NULL) {
        return -1;
    }

    do {
        ch = fgetc(fileHandle);
        if ( ch == '\n')
            count++;
    } while (ch != EOF);

    fclose(fileHandle);

    return count;
}
//  ======== INITILALIZATION OPERATIONS ========

int * veczeros(char *name, int length){
    int *vZeros;

    name = (int *)malloc(length* sizeof(int));
    vZeros = name;
    int i;
    for (i  = 0;  i<length ; i++) {
        vZeros[i] =0;
    }

    return vZeros;
}
int** matzeros(int *name, int x, int y){

    return 0;
}
int vecread(char *filename){
    return 0;
}
int matread(char *filename){
    return 0;
}
//  ================================================


//  ======== CONCATENATIONS ========
//  ================================================


//  ======== PADDINGS ========
//  ================================================


//  ======== SLICINGS ========
//  ================================================


int main(){
    char *FUNCTIONS[16] = {"veczeros", "matzeros", "vecread", "matread",
                        "vecstack", "matstack", "mvstack", "pad",
                        "padvar", "vecslice", "matslicecol", "matslicerow",
                        "matslice", "add", "multiply", "substract"};
    /*
     * FUNCTION LIST
     veczeros       = 0
     matzeros       = 1
     vecread         = 2
     matread        = 3
     vecstack       = 4
     matstack       = 5
     mvstack        = 6
     pad            = 7
     padvar         = 8
     vecslice       = 9
     matslicecol    = 10
     matslicerow    = 11
     matslice       = 12
     add            = 13
     multiply       = 14
     substract      = 15

     * */
    char *m1 = "inputs/m1.mat";
    char *m2 = "inputs/m2.mat";
    char *m3 = "inputs/m3.mat";
    char *m4 = "inputs/m4.mat";
    char *m5 = "inputs/m5.mat";
    char *v1 = "inputs/v1.vec";
    char *v2 = "inputs/v2.vec";
    char *v3 = "inputs/v3.vec";
    char *v4 = "inputs/v4.vec";
    char *v5 = "inputs/v5.vec";
    char *commands = "inputs/commands5.txt";

    // File Reading

    
    int i=0; //Loop variable
    int j=0; //Loop variable
    FILE *myFile = fopen(commands, "r");
    int lineNum = lineCount(commands);
    //Allocate memory for row
    char **commandArray=NULL;
    commandArray =(char **)malloc(sizeof(char)*lineNum);
    //Allocate memory for column
    for (i = 0; i< lineNum; i++) {
        commandArray[i] = (char *)malloc(50 * sizeof(char));
    }

    char * line = NULL;
    size_t len = lineNum;

    while ((getline(&line, &len, myFile)) != -1) {

            commandArray[j++] = strdup(line);

    }
    char *ch;
    int k;
    for (k= 0; k < lineNum; k++) {
        ch = strtok(commandArray[k], " ");
        if(strcmp(ch, "\n") == 0 || strcmp(ch,"\r\n") == 0){
            printf("ERROR\n");
        }
        else if(strcmp(ch,FUNCTIONS[0]) == 0){ //veczeros
            ch=strtok(NULL, " ");
            char *vname= ch;
            ch=strtok(NULL, " ");
            int len=atoi(ch);
            veczeros(vname, len);


        }else if(strcmp(ch,FUNCTIONS[1]) == 0){
            ch=strtok(NULL, " ");
            printf("%s\n", ch);

        }else if(strcmp(ch,FUNCTIONS[2]) == 0){
            ch=strtok(NULL, " ");
            printf("%s\n", ch);

        }else if(strcmp(ch,FUNCTIONS[3]) == 0){
            ch=strtok(NULL, " ");
            printf("%s\n", ch);

        }else if(strcmp(ch,FUNCTIONS[4]) == 0){
            ch=strtok(NULL, " ");
            printf("%s\n", ch);

        }else if(strcmp(ch,FUNCTIONS[5]) == 0){
            ch=strtok(NULL, " ");
            printf("%s\n", ch);

        }else if(strcmp(ch,FUNCTIONS[6]) == 0){
            ch=strtok(NULL, " ");
            printf("%s\n", ch);

        }else if(strcmp(ch,FUNCTIONS[7]) == 0){
            ch=strtok(NULL, " ");
            printf("%s\n", ch);


        }else if(strcmp(ch,FUNCTIONS[8]) == 0){
            ch=strtok(NULL, " ");
            printf("%s\n", ch);

        }else if(strcmp(ch,FUNCTIONS[9]) == 0){
            ch=strtok(NULL, " ");
            printf("%s\n", ch);

        }else if(strcmp(ch,FUNCTIONS[10]) == 0){
            ch=strtok(NULL, " ");
            printf("%s\n", ch);

        }else if(strcmp(ch,FUNCTIONS[11]) == 0){
            ch=strtok(NULL, " ");
            printf("%s\n", ch);

        }else if(strcmp(ch,FUNCTIONS[12]) == 0){
            ch=strtok(NULL, " ");
            printf("%s\n", ch);

        }else if(strcmp(ch,FUNCTIONS[13]) == 0){
            ch=strtok(NULL, " ");
            printf("%s\n", ch);

        }else if(strcmp(ch,FUNCTIONS[14]) == 0){
            ch=strtok(NULL, " ");
            printf("%s\n", ch);

        }else if(strcmp(ch,FUNCTIONS[15]) == 0){
            ch=strtok(NULL, " ");
            printf("%s\n", ch);

        }
        else{
            printf("FONKSIYON VAR\n");
        }
    }



    fclose(myFile);
    free(commandArray);
    for (i = 0; i< 50; i++) {
        free(commandArray[i]);
    }


}