#include "../include/lexer.h"

namespace lexer {
    lexerException::lexerException(const char* msg_, enum lexerError err_, int lineNo_) : 
    msg (msg_),
    err (err_),
    lineNo (lineNo_)
    {}

    const char* lexerException::getMessage() const {return msg;}
    int lexerException::getLineNo() const {return lineNo;}
    const char * lexerException::getLexerError() const {
        switch(err){
            case lexerError::BAD_ARGUMENT :
                return "BAD_ARGUMENT";
            case lexerError::UNDEFINED_SYMBOL :
                return "UNDEFINED_SYMBOL";
        }
    }
}