#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

int main() {
  int res = 0;
  std::string line;
  std::ifstream file("input");
  std::vector<std::string> left;
  std::unordered_map<std::string, int> right;

  while (std::getline(file, line) && line != "") {
    std::istringstream iss(line);
    std::string l, r;

    iss >> l;
    iss.ignore(3);
    iss >> r;

    left.push_back(l);
    right[r] += 1;
  }

  for (int i = 0; i < left.size(); i++) {
    int l = std::stoi(left[i]);
    int r = right[left[i]];

    res += l * r;
  }

  std::cout << "Result: " << res << "\n";

  return 0;
}
