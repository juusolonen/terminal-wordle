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
        public:
            void hello();
            void colorprint(char, BG_COLOR);
            void nocolorprint(char);
            void print(std::string);
    };
}
#endif