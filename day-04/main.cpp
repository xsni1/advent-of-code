#include <fstream>
#include <iostream>
#include <vector>

int main() {
  std::ifstream file("input");
  std::string line;
  std::vector<std::vector<char>> chars;
  int res = 0;

  while (std::getline(file, line) && line != "") {
    std::vector<char> l;

    for (int i = 0; i < line.size(); i++) {
      l.push_back(line[i]);
    }
    chars.push_back(l);
  }

  std::string word = "XMAS";
  for (int i = 0; i < chars.size(); i++) {
    for (int j = 0; j < chars[i].size(); j++) {
      bool found = true;

      for (int k = 0; k < word.size(); k++) {
          if (j+k >= chars[i].size()) {
              found = false;
              break;
          }
          if (word[k] != chars[i][k+j]) {
              found = false;
              break;
          }
      }
      res += found ? 1 : 0;


      found = true;
      for (int k = 0; k < word.size(); k++) {
          if (j-k < 0) {
              found = false;
              break;
          }
          if (word[k] != chars[i][j-k]) {
              found = false;
              break;
          }
      }
      res += found ? 1 : 0;


      found = true;
      for (int k = 0; k < word.size(); k++) {
          if (i-k < 0) {
              found = false;
              break;
          }
          if (word[k] != chars[i-k][j]) {
              found = false;
              break;
          }
      }
      res += found ? 1 : 0;


      found = true;
      for (int k = 0; k < word.size(); k++) {
          if (i+k >= chars.size()) {
              found = false;
              break;
          }
          if (word[k] != chars[i+k][j]) {
              found = false;
              break;
          }
      }
      res += found ? 1 : 0;

      found = true;
      for (int k = 0; k < word.size(); k++) {
        int x = j + k;
        int y = i + k;

        if (y >= chars.size()) {
          found = false;
          break;
        }

        if (x >= chars[i].size()) {
          found = false;
          break;
        }

        if (word[k] != chars[x][y]) {
          found = false;
          break;
        }
      }
      res += found ? 1 : 0;

      found = true;
      for (int k = 0; k < word.size(); k++) {
        int x = j - k;
        int y = i - k;

        if (y < 0) {
          found = false;
          break;
        }

        if (x < 0) {
          found = false;
          break;
        }

        if (word[k] != chars[x][y]) {
          found = false;
          break;
        }
      }
      res += found ? 1 : 0;

      found = true;
      for (int k = 0; k < word.size(); k++) {
        int x = j + k;
        int y = i - k;

        if (y < 0) {
          found = false;
          break;
        }

        if (x >= chars[i].size()) {
          found = false;
          break;
        }

        if (word[k] != chars[x][y]) {
          found = false;
          break;
        }
      }
      res += found ? 1 : 0;

      found = true;
      for (int k = 0; k < word.size(); k++) {
        int x = j - k;
        int y = i + k;

        if (y >= chars.size()) {
          found = false;
          break;
        }

        if (x < 0) {
          found = false;
          break;
        }

        if (word[k] != chars[x][y]) {
          found = false;
          break;
        }
      }
      res += found ? 1 : 0;
    }
  }
  std::cout << "Result: " << res;

  return 0;
}
