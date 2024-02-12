#include <iostream>
#include <string>

int main(int argc, char *argv[]) {

    std::string search_string;
    std::string input_string;

    std::cout << "Give a string from which to search for: ";
    getline(std::cin, input_string);

    std::cout << "Give search string: ";
    getline(std::cin, search_string);

    int found = input_string.find(search_string);
    if (found != std::string::npos) {
        std::cout << "'" << search_string << "' Found in '" << input_string << "' in position " << found << std::endl;
    } else {
        std::cout << "'" << search_string << "' NOT found in '" << input_string << "'a" << std::endl;
    }

    return 0;
}
