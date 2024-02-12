#include <iostream>
#include <string>
#include <fstream>


//prototypes
void searchString(std::string search_string, std::string input_string);
void searchFile(std::string fileName, std::string search_string);



int main(int argc, char *argv[]) {



        if (argc == 1 ){
            std::string search_string;
            std::string input_string;
            std::cout << "Give a string from which to search for: ";
            getline(std::cin, input_string);

            std::cout << "Give search string: ";
            getline(std::cin, search_string);

            searchString(search_string, input_string);

        } else if (argc == 3) {

            std::string fileName = argv[1];
            std::string search_string = argv[2];

            searchFile(fileName, search_string);
        }



        std::cin.get();
        return 0;
}

void searchString(std::string search_string, std::string input_string) {
    int found = input_string.find(search_string);
    if (found != std::string::npos) {
        std::cout << "'" << search_string << "' Found in '" << input_string << "' in position " << found
                  << std::endl;
    } else {
        std::cout << "'" << search_string << "' NOT found in '" << input_string << "'" << std::endl;
    }
}

void searchFile(std::string fileName, std::string search_string) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cout << "File '" << fileName << "' not found" << std::endl;
        return;
    }
    std::string line;
    while (getline(file, line)) {

        int found = line.find(search_string);
        if (found != std::string::npos) {
            std::cout << line << std::endl;
        }

    }
    file.close();
}


