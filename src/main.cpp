#include "../include/lexer.h"

int main(int argc, char* argv[]){
    FILE* file;
    file = fopen(argv[1], "r");
    lexer::parseArguments(file, NULL);
    return 0;
}