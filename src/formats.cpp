#include <vector>

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

// Color - 16
const std::vector<std::string> color_16_foreground_list = {
    "30", // Black
    "31", // Red
    "32", // Green
    "33", // Yellow
    "34", // Blue
    "35", // Magenta
    "36", // Cyan
    "37", // White
    "90", // Bright Black (Gray)
    "91", // Bright Red
    "92", // Bright Green
    "93", // Bright Yellow
    "94", // Bright Blue
    "95", // Bright Magenta
    "96", // Bright Cyan
    "97"  // Bright White
};
std::string color_16_foreground(std::string s, int code)
{
    if (code < 0 || code >= 16)
        return s;
    return "\033[" + color_16_foreground_list[code] + "m" + s + "\033[0m";
}
const std::vector<std::string> color_16_background_list = {
    "40",  // Black
    "41",  // Red
    "42",  // Green
    "43",  // Yellow
    "44",  // Blue
    "45",  // Magenta
    "46",  // Cyan
    "47",  // White
    "100", // Bright Black (Gray)
    "101", // Bright Red
    "102", // Bright Green
    "103", // Bright Yellow
    "104", // Bright Blue
    "105", // Bright Magenta
    "106", // Bright Cyan
    "107"  // Bright White
};
std::string color_16_background(std::string s, int code)
{
    if (code < 0 || code >= 16)
        return s;
    return "\033[" + color_16_background_list[code] + "m" + s + "\033[0m";
}

// Color 256
std::string color_256_foreground(std::string s, int code)
{
    if (code < 0 || code >= 256)
        return s;
    return "\033[38;5;" + std::to_string(code) + "m" + s + "\033[0m";
}
std::string color_256_background(std::string s, int code)
{
    if (code < 0 || code >= 256)
        return s;
    return "\033[48;5;" + std::to_string(code) + "m" + s + "\033[0m";
}

// Color RGB
std::string color_rgb_foreground(std::string s, int r_code, int g_code, int b_code)
{
    if (r_code < 0 || r_code >= 256 || g_code < 0 || g_code >= 256 || b_code < 0 || b_code >= 256)
        return s;
    return "\033[38;2;" + std::to_string(r_code) + ";" + std::to_string(g_code) + ";" + std::to_string(b_code) + "m" + s + "\033[0m";
}
std::string color_rgb_background(std::string s, int r_code, int g_code, int b_code)
{
    if (r_code < 0 || r_code >= 256 || g_code < 0 || g_code >= 256 || b_code < 0 || b_code >= 256)
        return s;
    return "\033[48;2;" + std::to_string(r_code) + ";" + std::to_string(g_code) + ";" + std::to_string(b_code) + "m" + s + "\033[0m";
}