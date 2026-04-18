#pragma once
#include <string>

/// Returns a lowercase copy of the given string
std::string ToLower(const std::string& text);

/// Wraps text in ANSI bold escape codes
std::string Bold(const std::string& text);

/// Renders a description string, bolding any {word} markup (we will use it to bold names)
std::string Render(const std::string& text);
