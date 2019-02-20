#include "../include/lexer.h"

int main(int argc, char* argv[]){
    FILE* file;
    file = fopen(argv[1], "r");
    try{
        lexer::parseArguments(file, NULL);
    } catch (lexer::lexerException e) {
        printf("%s:%d: %s: %s \n", argv[1], e.getLineNo(), e.getLexerError(), e.getMessage());
    }
    return 0;
}