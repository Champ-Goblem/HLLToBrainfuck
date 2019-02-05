#include "../include/lexer.h"

namespace lexer {
    char* getNextCodeLine(FILE* instream, FILE* outstream);
    //Array of our instrcutions in our defined language
    //currently remove binary operators till I know what im doing
    char inst[12][5] = {"pop", "push", "dup", "jump", "add", "sub", "mul", "div", "if"};
    char instOp[12][4] = {"", "INT", "", "INT", "INT", "INT", "INT", "INT", "OP"};
    const int instC = 12;
    //The operands we use for if, loops etc
    char operands[] = {'[', ']', '(', ')', '{', '}'};

    int lineNo = 0;

    lexerException* parseArguments(FILE * instream, FILE * outstream) {
        if (!instream) {
            throw invalid_argument("File pointer was null");
        }

        while (!feof(instream)) {
            char* inst = getNextCodeLine(instream, outstream);
        }
        
    }

    char* getNextCodeLine(FILE* instream, FILE* outstream) {
        lineNo ++;
        int chr = fgetc(instream);
        //check for if its a newline, or if its a comment and skip it
        if (chr == '#' || chr == '\n' || chr == '\r'){
            while (chr != '\n' && chr != EOF) {
                chr = fgetc(instream);
            }
            return NULL;
        }

        char instruction[100];
        //Remove the tabs from the start of line if that line is a dud then just return
        if (chr == '\t') {
            chr = fgetc(instream);
            while ((chr = fgetc(instream)) == '\t') {
            }
            if (chr == '\n' || chr == EOF || chr == '\r') {
                return NULL;
            }
        }

        //fill up our buffer with the stuff from the line
        int i = 1;
        instruction[0] = chr;
        chr = fgetc(instream);
        while (chr != EOF && chr != '\n') {
            instruction[i] = chr;
            i++;
            if (i >= 100) throw overflow_error("Instruction was longer than the buffer");
            chr = fgetc(instream);
        }
        
        //012345
        //PUSH 4

        //find the gap between the operator and operand or eol
        i = 0;
        while(instruction[i] != ' ' && instruction[i] != '\n' && instruction[i] != '\r' && instruction[i] != '\0') {
            i++;
        }

        char op[i];
        //lets take our operator from our buffer
        memcpy(op, instruction, sizeof(op));
        //set what we have taken back to zero for instructions with no parameters
        memset(instruction, 0, sizeof(op));
        char buff[100];
        memcpy(buff, instruction, 100);
        memset(instruction, 0, sizeof(instruction));
        //move what we havent taken back to start
        int opS = sizeof(op) + 1;
        i = 0;
        while(buff[i + opS] != '\0') {
            instruction[i] = buff[i + opS];
            i++;
        }
        for (i = 0; i < instC; i++) {
           if (strcmp(op, inst[i]) == 0) {
                printf("Token: %d, Operator: %s, Line: %d, Arg: %s \n", i, op, lineNo, instruction);
                if (strcmp(instOp[i], "INT") == 0) {
                    //if the parameter is an int
                    //if () {}
                } else if (strcmp(instOp[i], "OP") == 0) {
                    //if the parameter is a series of operational statements
                } else if (strcmp(instOp[i], "") == 0 ) {
                    //if there is no parameter
                    if (instruction[0] != '\0') {
                        throw lexerException("Parameter is set for ", BAD_ARGUMENT, lineNo);
                    }
                }
           }
       }

    }

    bool checkInteger(char* string) {
        //if()
    }

}