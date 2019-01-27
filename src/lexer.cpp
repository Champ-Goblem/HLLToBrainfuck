#include "../include/lexer.h"

namespace lexer {
    //Array of our instrcutions in our defined language
    //currently remove binary operators till I know what im doing
    char inst[12][5] = {"pop", "push", "dup", "jump", "add", "sub", "mul", "div", "if"};
    char instOp[12][4] = {"INT", "", "", "INT", "INT", "INT", "INT", "INT", "OP"};
    const int instC = 12;
    //The operands we use for if, loops etc
    char operands[] = {'[', ']', '(', ')', '{', '}'};

    int lineNo = 0;

    void parseArguments(FILE * instream, FILE * outstream) {
        if (!instream) {
            throw invalid_argument("File pointer was null");
        }

        
    }

    char* getNextCodeLine(FILE* instream, FILE* outstream) {
        lineNo ++;
        char chr = fgetc(instream);
        if (chr == '#' || chr == '\n' || chr == '\r'){
            while (chr != '\n' || chr != EOF) {
                chr = fgetc(instream);
            }
        }
        char instruction[100];   
        instruction[0] = chr;
        int i = 1;
        chr = fgetc(instream);
        while (chr != EOF || chr != '\n') {
            instruction[i] = chr;
            i++;
            if (i >= 100) throw overflow_error("Instruction was longer than the buffer");
            chr = fgetc(instream);
        }
        i = 0;
        while(instruction[i] != ' ') {
            i++;
        }

        char op[i+1];
        //lets take our operator from our buffer
        memcpy(op, instruction, sizeof(op));
        //set what we have taken back to zero therefore so for some instructions that should have no parameter
        memset(instruction, 0, sizeof(op));

        //move what we havent taken back to start
        int opS = sizeof(op) + 1;
        i = 0;
        while(instruction[i + opS] != '\0') {
            instruction[i] = instruction[i + opS];
        }

        
        for (i = 0; i < instC; i++) {
           if (strcmp(instruction, inst[i]) == 0) {
                printf("Token: %d, Operator: %s, Line: %d", i, instruction, lineNo);
                if (strcmp(instOp[i], "INT") == 0) {
                    //if the parameter is an int
                } else if (strcmp(instOp[i], "OP") == 0) {
                    //if the parameter is a series of operational statements
                } else if (strcmp(instOp[i], "") == 0 ) {
                    //if there is no parameter
                }
           }
       }

    }
}