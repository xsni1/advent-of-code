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

    // spsrawdzic czy inny tez to tak laduja czy co
    while (ss >> cur) {
      numbers.push_back(std::stoi(cur));
    }

    std::vector<int> copy = numbers;

    for (int j = 0; j < numbers.size()+1; j++) {
      for (int g = 0; g < copy.size(); g++) {
          std::cout << copy[g] << " ";
      }
      std::cout << std::endl;

      bool safe = true;

      for (int i = 1; i < copy.size(); i++) {
        if (copy[i - 1] <= copy[i] || std::abs(copy[i - 1] - copy[i]) > 3) {
          safe = false;
          break;
        }
      }

      if (safe) {
        res++;
        break;
      }

      safe = true;

      for (int i = 1; i < copy.size(); i++) {
        if (copy[i - 1] >= copy[i] || std::abs(copy[i - 1] - copy[i]) > 3) {
          safe = false;
          break;
        }
      }

      if (safe) {
        res++;
        break;
      }

      copy = numbers;
      copy.erase(copy.begin() + j);
    }
  }

  std::cout << "Result: " << res << "\n";

  return 0;
}
