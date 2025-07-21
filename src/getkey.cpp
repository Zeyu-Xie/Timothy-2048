#include "../include/getkey.hpp"

#include <cstdio>
#include <termios.h>
#include <unistd.h>

int getkey()
{
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    unsigned char buf[4] = {0};
    read(STDIN_FILENO, buf, 1);

    // Start with ESC
    if (buf[0] == 27)
    {
        char seq[2];
        if (read(STDIN_FILENO, seq, 2) == 2)
        {
            tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
            if (seq[0] == '[')
            {
                switch (seq[1])
                {
                case 'A':
                    return -1; // Up
                case 'B':
                    return -3; // Down
                case 'C':
                    return -2; // Right
                case 'D':
                    return -4; // Left
                }
            }
        }
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        return -99;
    }

    // General unicode characters
    int more = 0;
    if ((buf[0] & 0x80) == 0x00)
        more = 0;
    else if ((buf[0] & 0xE0) == 0xC0)
        more = 1;
    else if ((buf[0] & 0xF0) == 0xE0)
        more = 2;
    else if ((buf[0] & 0xF8) == 0xF0)
        more = 3;

    if (more > 0)
        read(STDIN_FILENO, buf + 1, more);

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    // Character to unicode (UTF-8)
    if (more == 0)
        return buf[0];
    if (more == 1)
        return ((buf[0] & 0x1F) << 6) | (buf[1] & 0x3F);
    if (more == 2)
        return ((buf[0] & 0x0F) << 12) | ((buf[1] & 0x3F) << 6) | (buf[2] & 0x3F);
    if (more == 3)
        return ((buf[0] & 0x07) << 18) | ((buf[1] & 0x3F) << 12) | ((buf[2] & 0x3F) << 6) | (buf[3] & 0x3F);
    return -100;
}