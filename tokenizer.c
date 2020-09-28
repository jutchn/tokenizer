#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>


int isDelim(char* input, int index){
    //traverse string and skip all the spaces
    while(isspace(input[index])){
        index++;
    }
    return index;
}

int isOperator(char* input, int index){


}

void isKeyword(char* input){
    // go through a million if statements and check if the word is a keyword :( if not then print as regular word
    if(strcmp(input,"auto")==0){
        printf("%s: \"%s\"",input,input);
    } else if(strcmp(input,"const")==0) {
        printf("%s: \"%s\"",input,input);
    } else if(strcmp(input,"double")==0) {
        printf("%s: \"%s\"",input,input);
    } else if(strcmp(input,"float")==0) {
        printf("%s: \"%s\"",input,input);
    } else if(strcmp(input,"int")==0) {
        printf("%s: \"%s\"",input,input);
    } else if(strcmp(input,"short")==0) {
        printf("%s: \"%s\"",input,input);
    } else if(strcmp(input,"struct")==0) {
        printf("%s: \"%s\"",input,input);
    } else if(strcmp(input,"unsigned")==0) {
        printf("%s: \"%s\"",input,input);
    } else if(strcmp(input,"break")==0) {
        printf("%s: \"%s\"",input,input);
    } else if(strcmp(input,"continue")==0) {
        printf("%s: \"%s\"",input,input);
    } else if(strcmp(input,"else")==0) {
        printf("%s: \"%s\"",input,input);
    } else if(strcmp(input,"for")==0) {
        printf("%s: \"%s\"",input,input);
    } else if(strcmp(input,"long")==0) {
        printf("%s: \"%s\"",input,input);
    } else if(strcmp(input,"signed")==0) {
        printf("%s: \"%s\"",input,input);
    } else if(strcmp(input,"switch")==0) {
        printf("%s: \"%s\"",input,input);
    } else if(strcmp(input,"void")==0) {
        printf("%s: \"%s\"",input,input);
    } else if(strcmp(input,"case")==0) {
        printf("%s: \"%s\"",input,input);
    } else if(strcmp(input,"default")==0) {
        printf("%s: \"%s\"",input,input);
    } else if(strcmp(input,"enum")==0) {
        printf("%s: \"%s\"",input,input);
    } else if(strcmp(input,"goto")==0) {
        printf("%s: \"%s\"",input,input);
    } else if(strcmp(input,"register")==0) {
        printf("%s: \"%s\"",input,input);
    } else if(strcmp(input,"typedef")==0) {
        printf("%s: \"%s\"",input,input);
    } else if(strcmp(input,"volatile")==0) {
        printf("%s: \"%s\"",input,input);
    } else if(strcmp(input,"char")==0) {
        printf("%s: \"%s\"",input,input);
    } else if(strcmp(input,"do")==0) {
        printf("%s: \"%s\"",input,input);
    } else if(strcmp(input,"extern")==0) {
        printf("%s: \"%s\"",input,input);
    } else if(strcmp(input,"if")==0) {
        printf("%s: \"%s\"",input,input);
    } else if(strcmp(input,"return")==0) {
        printf("%s: \"%s\"",input,input);
    } else if(strcmp(input,"static")==0) {
        printf("%s: \"%s\"",input,input);
    } else if(strcmp(input,"union")==0) {
        printf("%s: \"%s\"",input,input);
    } else if(strcmp(input,"while")==0) {
        printf("%s: \"%s\"",input,input);
    } else if(strcmp(input,"sizeof")==0) {
        printf("%s: \"%s\"",input,input);
    } else {
        printf("word: \"%s\"",input);
    }
}

int isWord(char* input, int index){
    // store starting index
    int start = index;
    // traverse through the word and increment index to find ending index
    if(isalpha(input[index])&&input[index]!='\0'){
        index++;
        while(isalnum(input[index])){
            index++;
        }
    }
    // memory allocate space for the word plus a null terminator and copy the indexed substring of the word into word
    char* word = (char*)malloc((index - start + 1)*sizeof(char));
    strncpy(word, input+start, index-start);
    // add null terminator to prevent memory skaboodle
    word[index-start] = '\0';  
    // enter printing sicko mode
    isKeyword(word);
    printf("\n");
    // free word memory 
    free(word);
    // go back to tokenizer with updated 
    return index;
}

int isDecimal(char input){

}

int isNum(char input){

}

void tokenizer(char* input){
    int index = 0;
    while(input[index]!='\0'){
        int wee = index;
        index = isDelim(input, index);
        if(input[index]=='\0'){
            break;
        }
        //isOperator(input[index]);
        index = isWord(input, index);
        //isDecimal(input[index]);
        
        if(wee == index){
            printf("ERROR: you fucked up");
            break;
        }
    }
}

int main(int argc, char **argv)
{
    // check if arguments
    if(argc!=2){
        return -1;
    }
    char* input = argv[1];

    tokenizer(input);
}
