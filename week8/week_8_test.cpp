#include <iostream>
#include <string>

int main() {
    std::string line;

    std::cout << "Enter lines of text (type 'exit' to quit):" << std::endl;
    while (std::getline(std::cin, line)) {
        if (line == "exit") {
            break;
        }
        std::cout << "You entered: " << line << std::endl;
    }

    return 0;
}

