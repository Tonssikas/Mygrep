#include <iostream>
#include <string>
#include <fstream>


// prototyypit
void searchString(const std::string& search_string, const std::string& input_string);
void searchFile(const std::string& fileName, const std::string& search_string, bool showLineNumbers = false, bool countOccurrences = false);



int main(int argc, char *argv[]) {

    //Argumenttien käsittely ja aliohjelmien kutsu oikeilla argumenteilla

        if (argc == 1 ){
            std::string search_string;
            std::string input_string;
            std::cout << "Give a string from which to search for: ";
            getline(std::cin, input_string);

            std::cout << "Give search string: ";
            getline(std::cin, search_string);

            searchString(search_string, input_string);

        } else if (argc == 3) {

            std::string fileName = argv[2];
            std::string search_string = argv[1];

            searchFile(fileName, search_string);
        } else if (argc == 4) {
            std::string fileName = argv[3];
            std::string search_string = argv[2];
            std::string option = argv[1];

            if (option == "-ol") {
                searchFile(fileName, search_string, true);
            } else if (option == "-oo") {
                searchFile(fileName, search_string, false, true);
            } else if (option == "-olo" || option == "-ool") {
                searchFile(fileName, search_string, true, true);
            } else {
                std::cout << "Invalid option" << std::endl;
            }
        } else {
            std::cout << "Invalid number of arguments" << std::endl;
        }




        std::cin.get();
        return 0;
}
// 1. inkrementin aliohjelma, joka etsii merkkijonon toisesta merkkijonosta. Molemmat käyttäjän syöttämiä.
void searchString(const std::string& search_string, const std::string& input_string) {
    int found = input_string.find(search_string);
    if (found != std::string::npos) {
        std::cout << "'" << search_string << "' Found in '" << input_string << "' in position " << found << std::endl;
    } else {
        std::cout << "'" << search_string << "' NOT found in '" << input_string << "'" << std::endl;
    }
}

 //aliohjelma, joka etsii merkkijonon tiedostosta. Käyttäjä syöttää tiedoston nimen ja etsittävän merkkijonon.
void searchFile(const std::string& fileName, const std::string& search_string, bool showLineNumbers, bool countOccurrences) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cout << "File '" << fileName << "' not found" << std::endl;
        return;
    }
    std::string line;
     int lineCount = 1;
     int occurrences = 0;
    while (getline(file, line)) {

        int found = line.find(search_string);
        if (found != std::string::npos) {
            occurrences++;
            if (showLineNumbers) {
                std::cout << lineCount << ": " << line << std::endl;
            } else std::cout << line << std::endl;
        }
        lineCount++;
    }
    if (countOccurrences) {
        std::cout << "\n" << "Occurrences of lines containing '" << search_string << "': " << occurrences << std::endl;
    }
    file.close();
}


