#ifndef PRINTER
#define PRINTER
#include <iostream>
namespace Utility {
    enum BG_COLOR {
        DEF = 0,
        BG_YELLOW   = 43,
        BG_GREEN    = 42,
    };

    class PrinterWriter {
        std::ostream& os = std::cout;
        std::istream& is = std::cin;
        public:
            void hello();
            void colorprint(char, BG_COLOR);
            void nocolorprint(char);
            void print(std::string);
            std::string prompt(std::string);
    };
}
#endif