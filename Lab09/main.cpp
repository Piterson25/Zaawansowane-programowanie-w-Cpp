#include <iostream>
#include <map>
#include <list>
#include <string>

std::string capitalize(const std::string& str) {
    if (str.empty()) {
        return str;
    }
    std::string result(str);
    result[0] = toupper(result[0]);
    for (size_t i = 1; i < result.length(); ++i) {
        result[i] = tolower(result[i]);
    }
    return result;
}

int main() {
    std::list<std::pair<std::string, int>> peopleData;
    std::string input;

    std::cout << "Program do operacji na imionach i wieku\n";
    std::cout << "=======================================\n";
    std::cout << "Wpisz 'e', aby zakonczyc w dowolnym momencie\n\n";


    while (true) {
        std::string name;
        int age;

        std::cout << "Podaj imie: ";

        std::cin >> input;

        if (input == "e") {
            break;
        }

        name = input;

        std::cout << "Podaj wiek: ";

        std::cin >> input;

        if (input == "e") {
            break;
        }

        try {
            age = std::stoi(input);

            peopleData.emplace_back(name, age);
        }
        catch (std::invalid_argument& ex) {
            std::cout << "Podano nieprawidlowy wiek, blad: " << '\n';
        }

        std::cout << '\n';
    }

    std::cout << '\n';

    peopleData.sort();

    std::map<std::string, int> numberOfNames;
    std::map<int, int> numberOfAges;

    double average = 0.0;
    double averageOdd = 0.0;
    double median = 0.0;
    int oddSize = 0;

    bool isEven = peopleData.size() % 2 == 0;

    int it = 0;

    for (auto& person : peopleData) {

        average += person.second;

        if (person.second % 2 != 0) {
            averageOdd += person.second;
            oddSize++;
        }

        if (isEven) {
            if (it == peopleData.size() / 2 || it == peopleData.size() / 2 + 1) {
                median += person.second;
            }
        }
        else {
            if (it == peopleData.size() / 2) {
                median += person.second;
            }
        }

        numberOfAges[person.second]++;
        numberOfNames[capitalize(person.first)]++;

        it++;
    }

    average /= static_cast<double>(peopleData.size());
    averageOdd /= static_cast<double>(oddSize);

    if (isEven) {
        median /= 2;
    }


    std::cout << "Srednia wieku: " << average << '\n';
    std::cout << "Srednia wieku dla wiekow nieparzystych: " << averageOdd << '\n';
    std::cout << "Mediana wieku: " << median << '\n';
    std::cout << "Ilosc imion:\n";
    for (auto& e : numberOfNames) {
        std::cout << e.first << ": " << e.second << '\n';
    }
    std::cout << "Ilosc osob w danym wieku:\n";
    for (auto& e : numberOfAges) {
        std::cout << "Wiek " << e.first << ": " << e.second << '\n';
    }

    return 0;
}
