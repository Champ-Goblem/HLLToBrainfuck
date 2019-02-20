#include <fstream>
#include <exception>
#include <iostream>
#include <stdint.h>
#include <string.h>
#include <stdexcept>
#include <stdlib.h>

using namespace std;
namespace lexer {
    class lexerException;
    lexerException* parseArguments(FILE * instream, FILE * outstream);
    enum lexerError {
        BAD_ARGUMENT,
        UNDEFINED_SYMBOL
    };
    class lexerException : public exception {
        private:
        enum lexerError err;
        int lineNo;
        const char * msg;
        
        public:
        lexerException(const char* msg_, enum lexerError err_, int lineNo_);
        const char* getMessage() const;
        int getLineNo() const;
        const char* getLexerError() const;
    };
}   