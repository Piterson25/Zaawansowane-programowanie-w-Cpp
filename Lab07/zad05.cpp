#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

int main() {
    std::vector<int> numbers;
    std::string input;

    std::cout << "Podaj liczby calkowite (wpisz 'e', aby zakonczyc):\n";

    while (std::getline(std::cin, input)) {
        if (input == "e") {
            break;
            return 0;
        }

        try {
            int number = std::stoi(input);

            numbers.push_back(number);
        }
        catch (std::invalid_argument& ex) {
            std::cout << "Blad w konwersji znaku: " << ex.what() << '\n';
        }
    }

    if (numbers.empty()) {
        std::cout << "Nie wprowadzono zadnych liczb!\n";
        return 0;
    }

    int sum = 0;
    int min = numbers[0];
    int max = numbers[0];

    for (int number : numbers) {
        sum += number;

        if (number < min) {
            min = number;
        }

        if (number > max) {
            max = number;
        }
    }

    double average = static_cast<double>(sum) / numbers.size();

    std::cout << "Suma: " << sum << '\n';
    std::cout << "Srednia: " << average << '\n';
    std::cout << "Minimalna wartosc: " << min << '\n';
    std::cout << "Maksymalna wartosc: " << max << '\n';

    return 0;
}
