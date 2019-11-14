#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char *name;
    int length;
    int *arr;
}vectors;

typedef struct{
    char *name;
    int x;
    int y;
    int **arr;
} matrix;
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
int nameCheck(int);
int size_of_line(char *filename){
    int size_of_line = 0;
    char *linem;
    FILE *vectorFile ;
    vectorFile= fopen(filename, "r");

    char * line = NULL;

    int i =0;
    size_t len = 1;
    getline(&line, &len, vectorFile);
    size_of_line = (strlen(line)+1)/2;
    return size_of_line;
}


vectors veczeros(char *name, int length, int index, vectors *varr){

    varr[index].name = name;
    varr[index].length=length;
    varr[index].arr = (int*)malloc(sizeof(int)*length);

    //free?
    return varr[index];
}

// Zero Vectors Initialized


matrix matzeros(char *name, int x, int y, int index, matrix *mat){
   int iter,i,j,k;

   mat[index].name=name;
   mat[index].x=x;
   mat[index].y=y;
   mat[index].arr= (int **)malloc(x * sizeof(int *));
    for (int i = 0; i < x ; i++) {
        mat[index].arr[i]= (int *)malloc(y * sizeof(int));
    }


    return mat[index];
}

// ========== ZERO MATRICES INITIALIZED.



vectors vecread(char *filename, vectors *vec, int index){
    char *linem;
    FILE *vectorFile ;
    vectorFile= fopen(filename, "r");
    if(vectorFile == NULL){
        printf("Error while opening file.\n");
    }
    char * line = NULL;

    int i =0;
    size_t len = 1;
    getline(&line, &len, vectorFile);
    vec[index].name = strtok(filename, ".");
    vec[index].length = (strlen(line)+1)/2;
    vec[index].arr = (int*)malloc(sizeof(int)*vec[index].length);


    linem = strtok(line," ");

    while(linem != NULL){
        vec[index].arr[i]=atoi(linem);
        linem = strtok(NULL, " " );
        i++;
    }
   return vec[index];
}

//   ====== VECTOR READ.


matrix matread( char *filename, matrix *mat, int index){
    int i;
    FILE *matrixFile ;
    matrixFile= fopen(filename, "r");
    if(matrixFile == NULL){
        printf("Error while opening file.\n");
    }

    int lineNum = lineCount(filename);
    int lineSize = size_of_line(filename);
    mat[index].name=strtok(filename, ".");
    mat[index].x = lineNum;
    mat[index].y = lineSize;
    mat[index].arr= (int **)malloc(lineNum * sizeof(int *));
    for (i = 0; i < lineNum ; i++) {
        mat[index].arr[i]= (int *)malloc(lineSize * sizeof(int));
    }
    char * line = NULL;
    size_t len = lineNum;
    char *command;
    int j,k;
    while ((getline(&line, &len, matrixFile)) != -1) {
        for (j = 0; j < lineNum ; j++) {
            for (k = 0; k < lineSize; k++) {
                mat[index].arr[j][k] = atoi(strtok(line, " "));
            }
        }
    }
    return mat[index];
}
//  ================================================
//  ================================================
//  ================================================
//  ================================================
//  ======== CONCATENATIONS ========================
//  ================================================
//  ================================================
int find_vector_index(char *name, vectors *vArr, int vSize){
    int i, index;
    for (i = 0; i <vSize ; i++) {
        if(strcmp(vArr[i].name, name)==0){
            return i;
        }
    }
    return 0;
}
matrix vecstack(char *vector1, char *vector2, char *direction, char *name, int index, matrix *mat,vectors *v, int vSize){
    if(strcmp(direction, "row") == 0 && v[find_vector_index(vector1, v, vSize)].length == v[find_vector_index(vector2, v, vSize)].length){
        mat[index].name=name;
        mat[index].x = 2;
        mat[index].y = v[find_vector_index(vector1, v, vSize)].length;
        mat[index].arr = (int **)malloc(2 * sizeof(int *));
        for (int i = 0; i < 2 ; i++) {
            mat[index].arr[i]= (int *)malloc(mat[index].y * sizeof(int));
        }
        int y;
        for ( y = 0; y < mat[index].y ; y++) {
                mat[index].arr[0][y] = v[find_vector_index(vector1, v, vSize)].arr[y];
        }
        for ( y = 0; y < mat[index].y ; y++) {
                mat[index].arr[1][y] = v[find_vector_index(vector2, v, vSize)].arr[y];
        }



    }else if(strcmp(direction, "column") == 0 && v[find_vector_index(vector1, v, vSize)].length == v[find_vector_index(vector2, v, vSize)].length){
        mat[index].name=name;
        mat[index].x=  v[find_vector_index(vector1, v, vSize)].length;
        mat[index].y=2;
        mat[index].arr = (int **)malloc(mat[index].x * sizeof(int *));
        for (int i = 0; i < 2 ; i++) {
            mat[index].arr[i]= (int *)malloc(2 * sizeof(int));
        }
        int i,j;
        for ( i = 0; i < mat[index].x; ++i) {
            mat[index].arr[i][0] = v[find_vector_index(vector1, v, vSize)].arr[i];
        }
        for ( i = 0; i < mat[index].x; ++i) {
            mat[index].arr[i][1] = v[find_vector_index(vector2, v, vSize)].arr[i];
        }

    }else{
        printf("error12122");
    }
    return mat[index];

}
// vecstack function
// ================================================
int find_matrix_index(char *name, matrix *mArr,int mSize){
    int i, index;
    for (i = 0; i <mSize ; i++) {
        if(strcmp(mArr[i].name, name)==0){
            return i;
        }
    }
    return 0;

}
matrix matstack(char *mat1, char *mat2, char *where, matrix *m, int mSize ){
    int i1,i2;
    i1 = find_matrix_index(mat1, m, mSize);
    i2 = find_matrix_index(mat2, m, mSize);
    int old_size_m1x = m[find_matrix_index(mat1, m, mSize)].x;
    int old_size_m1y = m[find_matrix_index(mat1, m, mSize)].y;
    int old_Size_m2x = m[find_matrix_index(mat2, m, mSize)].x;
    int old_Size_m2y = m[find_matrix_index(mat2, m, mSize)].y;
    if(strcmp(where,"d")==0 && m[i1].y == m[i2].y){
        int new_size_x= old_size_m1x + old_Size_m2x;
        int new_size_y= old_size_m1y;
        m[i1].x = new_size_x;
        m[i1].arr = (int **)  realloc(m[i1].arr, sizeof(int *) * m[i1].x);
        int i;
        for (i = 0; i < old_size_m1x ; i++) {
            m[i1].arr[i]= (int *) realloc(m[i1].arr[i], sizeof(int) * new_size_y);
        }
        for (i = old_size_m1x; i < new_size_x ; i++) {
            m[i1].arr[i]= (int *) malloc( sizeof(int) * new_size_y);
        }


        int k,l;


        for ( k = 0; k < old_Size_m2x ; k++) {
            for (l = 0; l < new_size_y ; l++) {
                m[i1].arr[new_size_x-old_size_m1x+k][l] = m[i2].arr[k][l];
            }
        }
        return m[i1];

    }
    else if(strcmp(where,"r")==0 && m[i1].x == m[i2].x){
        int new_size_x = old_size_m1x;
        int new_size_y = old_size_m1y+old_Size_m2y;
        int **p = m[i1].arr;
        p=(int **)realloc(p, sizeof(int) * new_size_x);
        int i;
        for (i = 0; i < new_size_y; i++) {
            *(p+i) = (int *)realloc(*(p+i) , sizeof(int) * new_size_x);
        }
    }
    else{printf("error");}



    return m[0];
}


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

    int vecCount = 0;
    int matCount = 0;
    // variable for counters.

    char *commands = "commands1.txt";

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
    char *command;

    int iterNum=0;
    while ((getline(&line, &len, myFile)) != -1) {

        commandArray[j++] = strdup(line);
        // getting lines from file

        command = strtok(line," ");
        if(strcmp(command, "matzeros") == 0 || strcmp(command, "matread") == 0 || strcmp(command, "matslice") == 0 || strcmp(command, "vecstack") == 0){
            matCount++;
        }else if(strcmp(command, "veczeros") == 0 || strcmp(command, "vecread") == 0 || strcmp(command, "vecslice") == 0 || strcmp(command, "matslicerow") == 0 || strcmp(command, "matslicecol") == 0){
            vecCount++;
        }
        // vector and matrix number detected.

    }
    // file reading completed.

    vectors *vectorArray = (vectors *)malloc(sizeof(vectors)*vecCount);
    matrix *matrixArray = (matrix*)malloc(sizeof(matrix)*matCount);
    // vector and matrix arrays defined.

    // functions directors below.
    int mIndex = 0; int vIndex =0;
    char *ch;
    int k;
    for (k= 0; k < lineNum; k++) {
        ch = strtok(commandArray[k], " ");
        if(strcmp(ch, "\n") == 0 || strcmp(ch,"\r\n") == 0){
            printf("error\n");
        }
        else if(strcmp(ch,FUNCTIONS[0]) == 0){ //veczeros


            ch=strtok(NULL, " ");
            char *vname= ch;
            ch=strtok(NULL, " ");
            int vlen=atoi(ch);
            vectors v=veczeros(vname, vlen, vIndex,vectorArray);
            printf("created vector %s %d\n", v.name, v.length);
            int iter;
            for (iter = 0; iter <v.length ; iter++) {
                v.arr[iter]=0;
                printf("%d ", v.arr[iter]);
            }printf("\n");

//
        vIndex++;

        }else if(strcmp(ch,FUNCTIONS[1]) == 0){ //matzeros
            ch=strtok(NULL, " ");
            char *name = ch;
            ch=strtok(NULL, " ");
            int row = atoi(ch);
            ch=strtok(NULL, " ");
            int col = atoi(ch);
            matrix m=matzeros(name, row, col, mIndex, matrixArray);
            printf("created matrix %s %d %d\n", m.name,m.x,m.y);
            for(j=0; j<m.x; j++){
                for(k=0; k<m.y; k++){
                    m.arr[j][k] = 0;
                    printf("%d ", m.arr[j][k]);
                }
                printf("\n");
            }

        mIndex++;
        }else if(strcmp(ch,FUNCTIONS[2]) == 0){ // vecread

            ch=strtok(NULL, " ");
            char *readVectorName =strtok(ch,"\n");
            vectors v = vecread(readVectorName, vectorArray, vIndex);
            printf("read vector %s %d \n", v.name, v.length);
            int l;
            for ( l = 0; l < v.length-1; l++) {
                printf("%d ", v.arr[l]);
            }printf("\n");
        vIndex++;


        }else if(strcmp(ch,FUNCTIONS[3]) == 0){ //matread
            ch=strtok(NULL, " ");
            char *readMatrixName=strtok(ch, "\n");
            matrix m=  matread(readMatrixName, matrixArray, mIndex);
            printf("read matrix %s %d %d\n",m.name,m.x,m.y);
            int t,y;
            for ( t = 0; t < m.x ; t++) {
                for ( y = 0; y < m.y ; y++) {
                    printf("%d ",m.arr[t][y]);
                }printf("\n");
            }
        mIndex++;

        }else if(strcmp(ch,FUNCTIONS[4]) == 0){ //vecstack
            ch=strtok(NULL, " ");
            char *v1 = ch;
            ch=strtok(NULL, " ");
            char *v2 = ch;
            ch=strtok(NULL, " ");
            char *direction= ch;
            ch=strtok(NULL, " ");
            char *name = ch;
            matrix m = vecstack(v1,v2,direction,name,mIndex,matrixArray,vectorArray,matCount);
            printf("vectors concatenated %s %d %d\n",m.name,m.x,m.y );
            int a,b;
            for (a = 0; a < m.x ; a++) {
                for ( b = 0; b <m.y ; b++) {
                    printf("%d ", m.arr[a][b]);
                }printf("\n");
            }
        mIndex++;
        }else if(strcmp(ch,FUNCTIONS[5]) == 0){ //matstack
            ch=strtok(NULL, " ");
            matrix m = matstack("m1","m1","d", matrixArray, matCount);
            printf("matrices concatenated %s %d %d\n", m.name, m.x, m.y);
            for (int l = 0; l < m.x; l++) {
                for (int n = 0; n < m.y ; n++) {
                    printf("%d ", m.arr[l][n]);
                }printf("\n");
            }
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
            printf("errorr\n");
        }

        //free all of memoryler

    }


    fclose(myFile);
    free(commandArray);
    for (i = 0; i< 50; i++) {
        free(commandArray[i]);
    }
    free(matrixArray);
    free(vectorArray);


}