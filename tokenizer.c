#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>


int isDelim(char* input, int index){
    if(isspace(input[index])){
        index++;
    }
    return index;
}



void isKeyword(char input){
    //called by isword
}

int isWord(char* input, int index){
    int start = index;
    printf("%d, %s\n",start, input);
    if(isalpha(input[index])){
        index++;
        while(isalnum(input[index])){
            index++;
        }
    }
    printf("%d, %s\n",index, input);
    char* banana = (char*)malloc((index - start)*sizeof(char));
    strncpy(banana, input+start, index-start);
    
    printf("%s\n\n",banana);
    //isKeyword(char* banana);
    return index;
}

void isDecimal(char input){

}

void isNum(char input){

}

void tokenizer(char* input){
    int index = 0;

    while(input[index]!='\0'){
        index = isDelim(input, index);

        //isOperator(input[index]);
        index = isWord(input, index);
        //isDecimal(input[index]);
        
        index+=1;
    }
}

int main(int argc, char **argv)
{
    if(argc!=2){
        return -1;
    }
    char* input = argv[1];
    //printf("%c",input[0]);
    
    //printf("%d\n",len);

    //printf("%s",input+1);
    tokenizer(input);
}
