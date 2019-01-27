#include <fstream>
#include <exception>
#include <iostream>
#include <stdint.h>

using namespace std;
namespace lexer {

}

char inst[12][5] = {"pop", "push", "dup", "jump", "add", "sub", "mul", "div", "and", "or", "xor", "if"};

char operands[] = {'[', ']', '(', ')', '{', '}'};

