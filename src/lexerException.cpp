#include "../include/lexer.h"

namespace lexer {
    lexerException::lexerException(const char* msg_, enum lexerError err_, int lineNo_) : 
    msg (msg_),
    err (err_),
    lineNo (lineNo_)
    {}

    const char* lexerException::getMessage() const {return msg;}
    int lexerException::getLineNo() const {return lineNo;}
    enum lexerError lexerException::getLexerError() const {return err;}
}