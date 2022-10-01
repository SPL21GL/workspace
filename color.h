// Color Terminal Output Library
// MIT Licensed Library
// Based on: https://gist.github.com/Ph0enixKM/5a0d48c440a6dd664d7ae4c807c53008


#include <iostream>
#include <string>

enum ConsoleColor
{
    black = 0,
    blue = 1,
    green = 2,
    cyan = 3,
    red = 4,
    magenta = 5,
    yellow = 6,
    white = 7
};

#ifdef _WIN32
#include <windows.h>
std::ostream &color(std::ostream &out, ConsoleColor color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int col = color;
    SetConsoleTextAttribute(hConsole, col);
    out.flush();
    return out;
}

std::ostream &resetColor(std::ostream &out)
{
    return color(out, ConsoleColor::white);
}

#else

std::ostream &color(std::ostream &out, ConsoleColor color)
{
    const std::string colorStrings[] = {"\033[0;30m", "\033[0;36m", "\033[0;32m", "\033[0;36m", "\033[0;31m", "\033[0;35m", "\033[0;33m", "\033[0;37m"};
    out << colorStrings[color];
    return out;
}

std::ostream &resetColor(std::ostream &out)
{
    std::cout << "\033[0m";
    return out;
}

#endif

std::ostream &colorBlack(std::ostream &out)
{
    return color(out, ConsoleColor::black);
}

std::ostream &colorBlue(std::ostream &out)
{
    return color(out, ConsoleColor::blue);
}

std::ostream &colorGreen(std::ostream &out)
{
    return color(out, ConsoleColor::green);
}

std::ostream &colorCyan(std::ostream &out)
{
    return color(out, ConsoleColor::cyan);
}

std::ostream &colorRed(std::ostream &out)
{
    return color(out, ConsoleColor::red);
}

std::ostream &colorMagenta(std::ostream &out)
{
    return color(out, ConsoleColor::magenta);
}

std::ostream &colorYellow(std::ostream &out)
{
    return color(out, ConsoleColor::yellow);
}

std::ostream &colorWhite(std::ostream &out)
{
    return color(out, ConsoleColor::white);
}
