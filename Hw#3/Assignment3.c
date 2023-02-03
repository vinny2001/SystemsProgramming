#include<stdio.h>

int main(int argc,char* argv[]){

//Variable declarations
int i,j,indexCount,currIndex,charCount;

//if the increment variable < number of arguments, enter loop
//Outer loop defines the number of strings in the 'outer' array.
for (i=1; i<argc; i++){
    charCount=0;
    //Inner array iterates the current index of outer array (each character of the selected string)
    for(currIndex=0;*(*(argv+i)+currIndex)!='\0';currIndex++){
        //Filters out each string's parameters, limiting output to a value between all capitial and all lowercase A-Z
        if((*(*(argv+i)+currIndex)<='z' && *(*(argv+i)+currIndex)>='a')||(*(*(argv+i)+currIndex)<='Z' && *(*(argv+i)+currIndex)>='A')){
            //Character count incremented after condition satisfied
            charCount++;
        }   
    }
    //Loop increments to next string in 'outer' array after all the indices of the current string are printed
    for(j=1;j<=charCount;j++){
        //Inner loop prints each index of the current argument for the number of indices that string contains (current string being parsed through)
        for(indexCount=0;indexCount<j;indexCount++){
            printf("%c",*(*(argv+i)+indexCount));   
        }
    // New line printed after each execution of inner and outer loop.
    printf("\n");
    }
}
return 0;
}