#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

int main() {
  int res = 0;
  std::string line;
  std::ifstream file("input");
  std::vector<int> left;
  std::vector<int> right;

  while (std::getline(file, line) && line != "") {
    // czemu to dziala?
    int i = line.find(" ");

    int l = std::stoi(line.substr(0, i));
    int r = std::stoi(line.substr(i, line.length()));

    left.push_back(l);
    right.push_back(r);
  }

  std::sort(left.begin(), left.end());
  std::sort(right.begin(), right.end());

  for (int i = 0; i < left.size(); i++) {
    res += std::abs(left[i] - right[i]);
  }

  std::cout << "Result: " << res << "\n";

  return 0;
}
