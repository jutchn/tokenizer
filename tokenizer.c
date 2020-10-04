#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

// Extra Credit #2 If string contains // or /*, skip through string until newline or */ is found or the string terminates
// return appropriate index where comment ends 
int isComment(char* input, int index){
    // handle comment formatted as '//'
    if(input[index] == '/' && input[index+1] == '/'){
        // continue until newline or string terminates
        while(input[index] != '\n' && input[index] != '\0'){
            index++;
        }
    // handle comment formatted as '/*', if no */ is found then treat rest of string as comment and 
    // return index of end of string
    } else if(input[index] == '/' && input[index+1] == '*'){
        // skip past the /*
        index+=2;
        while(input[index] != '*' && input[index+1] != '/'){
            // handle end of string
            if(input[index+1] == '\0'){
                index--;
                break;
            }
            index++;
        }
        // skip the */
        index+=2;
    }
    return index;
}

// Extra Credit #3, if string contains " or ', save starting index+1 and find closing " or '. 
// Copy substring of chars inside the quote into new string and print that, return index 
int isQuote(char* input, int index){
    if(input[index] == '\''){
        index++;
        // starting index is index of first char inside the quote
        int start = index;
        while(input[index] != '\''){
            index++;
            // if end of string is reached without end quote return -1
            if(input[index]=='\0'){
                return -1;
            }
        }
        // memory allocate space for the quote plus a null terminator and copy the substring
        char* quote = (char*)malloc((index - start + 1)*sizeof(char));
        strncpy(quote, input+start, index-start);
        // append null terminator to end of substring 
        quote[index-start] = '\0';  
        // print quote token
        printf("quote: \"%s\"\n",quote);
        // escape out of quote
        index++;
        // free quote
        free(quote);
    } else if(input[index] == '\"'){
        index++;
        // starting index is index of first char inside the quote
        int start = index;
        while(input[index]!='\"'){
            index++;
            // if end of string is reached without end quote return -1
            if(input[index]=='\0'){
                return -1;
            }
        }
        // memory allocate space for the quote plus a null terminator and copy the substring
        char* quote = (char*)malloc((index - start + 1)*sizeof(char));
        strncpy(quote, input+start, index-start);
        // append null terminator to end of substring
        quote[index-start] = '\0';  
        // print quote token
        printf("quote: \"%s\"\n",quote);
        // escape out of quote
        index++;
        // free quote
        free(quote);
    }
    return index;
}

int isDelim(char* input, int index){
    //traverse string and skip all the spaces, return index of the first non-space char
    while(isspace(input[index])){
        index++;
    }
    return index;
}

int isOperator(char* input, int index) {
	int newIndex = index;
	// Switch statements and nested switch statements to cover all the possible operators
	// Ordered by amount of possible operators with each starting character, for example '<' has 4 possible operators it could become so it is at the top
	switch (input[newIndex]) {
		case '<':
			switch (input[newIndex + 1]) {
			case '<':
				switch (input[newIndex + 2]) {
				case '=':
					printf("shift left equals: \"<<=\"\n");
					return newIndex + 3;
				default:
					printf("shift left: \"<<\"\n");
					return newIndex + 2;
				}
				break;
			case '=':
				printf("less than or equal test: \"<=\"\n");
				return newIndex + 2;
			default:
				printf("less than test: \"<\"\n");
				return newIndex + 1;
			}
			break;
		case '>':
			switch (input[newIndex + 1]) {
			case '>':
				switch (input[newIndex + 2]) {
				case '=':
					printf("shift right equals: \">>=\"\n");
					return newIndex + 3;
				default:
					printf("shift right: \">>\"\n");
					return newIndex + 2;
				}
				break;
			case '=':
				printf("greater than or equal test: \">=\"\n");
				return newIndex + 2;
			default:
				printf("greater than test: \">\"\n");
				return newIndex + 1;
			}
			break;
		case '-':
			switch (input[newIndex + 1]) {
			case '>':
				printf("structure pointer: \"->\"\n");
				return newIndex + 2;
			case '-':
				printf("decrement: \"--\"\n");
				return newIndex + 2;
			case '=':
				printf("minus equals: \"-=\"\n");
				return newIndex + 2;
			default:
				printf("minus/subtract operator: \"-\"\n");
				return newIndex + 1;
			}
			break;
		case '|':
			switch (input[newIndex + 1]) {
			case '=':
				printf("bitwise OR equals: \"|=\"\n");
				return newIndex + 2;
			case '|':
				printf("logical OR: \"||\"\n");
				return newIndex + 2;
			default:
				printf("bitwise OR: \"|\"\n");
				return newIndex + 1;
			}
			break;
		case '+':
			switch (input[newIndex + 1]) {
			case '+':
				printf("increment: \"++\"\n");
				return newIndex + 2;
			case '=':
				printf("plus equals: \"+=\"\n");
				return newIndex + 2;
			default:
				printf("addition: \"+\"\n");
				return newIndex + 1;
			}
			break;
		case '&':
			switch (input[newIndex + 1]) {
			case '=':
				printf("bitwise AND equals: \"&=\"\n");
				return newIndex + 2;
			case '&':
				printf("logical AND: \"&&\"\n");
				return newIndex + 2;
			default:
				printf("AND/address operator: \"&\"\n");
				return newIndex + 1;
			}
			break;
		case '!':
			switch (input[newIndex + 1]) {
				case '=':
					printf("inequality test: \"!=\"\n");
					return newIndex + 2;
				default:
					printf("negate: \"!\"\n");
					return newIndex + 1;
			}
			break;

		case '^':
			switch (input[newIndex + 1]) {
				case '=':
					printf("bitwise XOR equals: \"^=\"\n");
					return newIndex + 2;
				default:
					printf("bitwise XOR: \"^\"\n");
					return newIndex + 1;
			}
			break;
		case '/':
			switch (input[newIndex + 1]) {
				case '=':
					printf("divide equals: \"/=\"\n");
					return newIndex + 2;
				default:
					printf("division: \"/\"\n");
					return newIndex + 1;
			}
			break;

		case '=':
			switch (input[newIndex + 1]) {
				case '=':
					printf("equality test: \"==\"\n");
					return newIndex + 2;
				default:
					printf("assignment: \"=\"\n");
					return newIndex + 1;
			}
			break;
		case '*':
			switch (input[newIndex + 1]) {
				case '=':
					printf("times equals: \"*=\"\n");
					return newIndex + 2;
				default: 
					printf("multiply/dereference operator: \"*\"\n");
					return newIndex + 1;
			}
			break;
		case '%':
			switch (input[newIndex+1]) {
				case '=':
					printf("mod equals: \"%%=\"\n");
					return newIndex + 2;
			}
			break;
		case '(':
			printf("left parenthesis: \"(\"\n");
			return newIndex + 1;
		case ')':
			printf("right parenthesis: \"(\"\n");
			return newIndex + 1;
		case '[':
			printf("left bracket: \"[\"\n");
			return newIndex + 1;
		case ']':
			printf("right bracket: \"]\"\n");
			return newIndex + 1;
		case '.':
			printf("structure member: \".\"\n");
			return newIndex + 1;
		case ',':
			printf("comma: \",\"\n");
			return newIndex + 1;
		case '?':
			printf("conditional true: \"?\"\n");
			return newIndex + 1;
		case ':':
			printf("conditional false: \":\"\n");
			return newIndex + 1;
		case '~':
			printf("1s complement: \"~\" \n");
			return newIndex + 1;
	}
	return index;
}

// Extra Credit #1, also handles printing of regular words
void isKeyword(char* input){
    // go through if statements and check if the word is a keyword, if not then print as regular word
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
    } else {
        return index;
    }
    // memory allocate space for the word plus a null terminator and copy the substring into space
    char* word = (char*)malloc((index - start + 1)*sizeof(char));
    strncpy(word, input+start, index-start);
    // append null terminator to end of substring
    word[index-start] = '\0';  
    // enter printing function
    isKeyword(word);
    printf("\n");
    // free word memory 
    free(word); 
    return index;
}

enum numType {Decimal, Octal, Hexadecimal, Float}; 
int isNum(char* input, int index) {
	int newIndex = index;
	// Check if first char is a number
	if (isdigit(input[index])) { 
		enum numType type;
		// Default typing is a decimal integer
		type = Decimal; 
		// Check for leading zero for hexadecimal and octal
		int leadingZero = input[newIndex] == '0'; 
		newIndex++;

		//Hexadecimal Case checks if thee is a leading zero followed by an x
		if (leadingZero && (tolower(input[newIndex]) == 'x')) { 
			// Then check if the next character is either 0-9, A-F, or a-f
			if (isdigit(input[newIndex + 1]) || (input[newIndex+1] >= 65 && input[newIndex+1] <= 70) || (input[newIndex+1] >= 97 && input[newIndex+1] <= 102)) { 
				// Change type to Hexadecimal if all criteria is met
				type = Hexadecimal;
				newIndex++;
				while (isdigit(input[newIndex]) || (input[newIndex] >= 65 && input[newIndex] <= 70) || (input[newIndex] >= 97 && input[newIndex] <= 102)) {
					//Loop until the element at new index isn't 0-9, A-F, or a-f
					newIndex++;
				}
			}
		}
		else {
			// Octal Case
			int octalBool = leadingZero; 
			//Loop through and increment newIndex until element at the newIndex isn't a number
			while (isdigit(input[newIndex])) {
				// Set octal typing to false if any of the numbers aren't 0-7
				if (input[newIndex] - '0' > 7 || input[newIndex] - '0' < 0) { 
					octalBool = 0;
				}
				newIndex++;
			}
			// Depending on the value of octalBool change typing to octal or keep as default decimal
			if (octalBool) {
				type = Octal;
			}

			// Float Case with decimal point
			if (input[newIndex] == '.') {
				// Make sure char after decimal point is a number
				if (isdigit(input[newIndex + 1])) {
					type = Float;
					newIndex++;
					//Increment newIndex until value at newIndex isn't a number
					while (isdigit(input[newIndex])) {
						newIndex++;
					}

					//Check for scientific notation
					if (tolower(input[newIndex]) == 'e') {
						// Make sure char after notation is either a number, a negative sign followed by a number, or a positive sign followed by a number
						if (isdigit(input[newIndex + 1]) || (((input[newIndex + 1] == '-') || input[newIndex + 1] == '+'))) {
							newIndex++;

							// If there is a + or - check to make sure the next char is a number
							if (((input[newIndex] == '-') || input[newIndex] == '+') && isdigit(input[newIndex + 1])) {
								newIndex++;
							}
							// If it isn't a number, do not include the +, -, or e in the index range
							else if (((input[newIndex] == '-') || input[newIndex] == '+') && !isdigit(input[newIndex + 1])) {
								newIndex--;
							}
                            //Again increment until value at newIndex isn't a number
							while (isdigit(input[newIndex])) {
								newIndex++;
							}
						}
					}
				}
			}
		}

		// Switch statement to print the typing 
		switch (type) {
			case 0:
				printf("decimal integer: \"");
				break;
			case 1: 
				printf("octal integer: \"");
				break;
			case 2:
				printf("hexadecimal integer: \"");
				break;
			case 3:
				printf("floating point: \"");
				break;
		}

		// Create and print substring of all chars between initial index and new index
		char* print = (char*)malloc((newIndex - index + 1) * sizeof(char));
		memcpy(print, &input[index], newIndex - index);
		print[newIndex - index] = '\0';
		printf("%s\"\n", print);
		free(print);
		// Return the new index
		return newIndex;
	}
	//If first char isn't a number return false
	return newIndex;
}

void tokenizer(char* input){
    int index = 0;
    while(input[index]!='\0'){
        int startindex = index;
        index = isDelim(input, index);
        if(input[index]=='\0'){
            break;
        }
        index = isComment(input, index);
        if(input[index]=='\0'){
            break;
        }
        index = isQuote(input, index);
        // isQuote returns -1 if no end quote is found, print error in this case
        if(index == -1){
            printf("ERROR: unmatched quote\n");
            break;
        }
        if(input[index]=='\0'){
            break;
        }
        index = isOperator(input, index);
        if(input[index]=='\0'){
            break;
        }
        index = isWord(input, index);
        if(input[index]=='\0'){
            break;
        }
        index = isNum(input, index);
        if(input[index]=='\0'){
            break;
        }
        // if no updates were made to index then that indicates the program tried to tokenize an unrecognized char
        if(startindex == index){
            printf("ERROR: invalid input\n");
            break;
        }
    }
}

int main(int argc, char **argv)
{
    // check if only 1 argument
    if(argc!=2){
        printf("ERROR: invalid number of arguments\n");
        return -1;
    }
    char* input = argv[1];
    tokenizer(input);
}
