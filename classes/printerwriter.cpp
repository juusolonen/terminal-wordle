#include "printerwriter.h"
#include <iostream>
#include <cctype>

using namespace Utility;


void PrinterWriter::hello() {
    os << "Hello" << std::endl;
    colorprint('a', BG_GREEN);
    colorprint('a', BG_YELLOW);
    os << std::endl;
}

void PrinterWriter::colorprint(char c, BG_COLOR color = DEF)
{
    char ac = toupper(c);
    os << "\033[" << 37 << ";" << color << "m";
    os << (char)ac;
    os << "\033[0m"; //<< std::endl;
}

void Utility::PrinterWriter::nocolorprint(char c)
{
    char ac = toupper(c);
    os << (char)ac;
}

void PrinterWriter::print(std::string message)
{
    os << message << std::endl;
}

