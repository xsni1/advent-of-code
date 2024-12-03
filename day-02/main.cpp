#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
  int res = 0;
  std::string line;
  std::ifstream file("input");

  while (std::getline(file, line) && line != "") {
    std::stringstream ss(line);
    std::string cur;
    std::string prev;
    std::vector<int> numbers;

    while (ss >> cur) {
      numbers.push_back(std::stoi(cur));
    }

    bool asc = numbers[0] < numbers[1];
    bool safe = true;

    for (int i = 1; i < numbers.size(); i++) {
      if (asc && numbers[i] <= numbers[i - 1]) {
        safe = false;
        break;
      }
      if (!asc && numbers[i] >= numbers[i - 1]) {
        safe = false;
        break;
      }
      if (std::abs(numbers[i] - numbers[i - 1]) > 3) {
        safe = false;
        break;
      }
    }

    if (safe) {
      for (int i = 0; i < numbers.size(); i++) {
          std::cout << numbers[i] << " ";
      }
      std::cout << std::endl;
      res++;
    }
  }

  std::cout << "Result: " << res << "\n";

  return 0;
}
