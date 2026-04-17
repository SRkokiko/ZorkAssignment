#pragma once
#include <string>

/// Wraps text in ANSI bold escape codes
std::string Bold(const std::string& text);

/// Renders a description string, bolding any {word} markup (we will use it to bold names)
std::string Render(const std::string& text);
