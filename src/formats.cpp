#include "../include/formats.hpp"

std::string bold(std::string s)
{
    return "\033[1m" + s + "\033[0m";
}

std::string italic(std::string s)
{
    return "\033[3m" + s + "\033[0m";
}

std::string underline(std::string s)
{
    return "\033[4m" + s + "\033[0m";
}

std::string color(std::string code, std::string s)
{
    return "\033[" + code + "m" + s + "\033[0m";
}