#include <iostream>
#include "tui.h"

int main() {
    tui a;
    a.draw();
    std::cout << "\e[H";
    std::cout << "\e[B";
    std::cout << "\e[C";
    putchar('f');
    putchar('f');
    putchar('f');
    putchar('f');
    putchar('\r');
    std::cout << "\e[C";
    putchar('a');
    putchar('b');
    putchar('\n');
}
