#include <iostream>
#include <cstring>

int main() {
    const char* cstr = "Hello, World!";
    int start = 7; // Starting index of the substring
    int length = 5; // Length of the substring

    // Create a buffer to hold the substring, including space for the null terminator
    char substring[length + 1];

    // Copy the substring from the source string
    std::strncpy(substring, cstr + start, length);

    // Null-terminate the new string
    substring[length] = '\0';

    std::cout << "Substring: " << substring << std::endl;

    return 0;
}
