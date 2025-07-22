#pragma once

#include <iostream>

std::string bold(std::string s);
std::string italic(std::string s);
std::string underline(std::string s);

std::string color_16_foreground(std::string s, int code);
std::string color_16_background(std::string s, int code);
std::string color_256_foreground(std::string s, int code);
std::string color_256_background(std::string s, int code);
std::string color_rgb_foreground(std::string s, int r_code, int g_code, int b_code);
std::string color_rgb_background(std::string s, int r_code, int g_code, int b_code);
