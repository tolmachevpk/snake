#include "view.h"
#include <sys/ioctl.h>
#include <unistd.h>

class tui : view {
public:
    void draw();

private:
    unsigned short x_characters;
    unsigned short y_characters;
};

void tui::draw() {
    struct winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);

    x_characters = size.ws_col;
    y_characters = size.ws_row;

    for(int i = 0; i < y_characters; i++){
        for(int j = 0; j < x_characters; j++) {
            if ((i == 0) || (i == (y_characters - 1))) {
                putchar('-');
                continue;
            }
            if ((j == 0) || (j == (x_characters - 1))) {
                putchar('|');
                continue;
            }
            putchar(' ');
        }
        if (i != (y_characters - 1)) {
            putchar('\n');
        }
    }
}