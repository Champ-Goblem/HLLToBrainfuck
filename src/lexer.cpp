#include "../include/lexer.h"

namespace lexer {
    int lineNo = 0;
    void parseArguments(FILE * instream, FILE * outstream) {
        if (!instream) {
            throw invalid_argument("File pointer was null");
        }

        while()
    }

    char* getNextCodeLine(FILE* instream, FILE* outstream) {
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
        

    }
}