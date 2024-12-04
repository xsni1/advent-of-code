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

  for (int i = 0; i < chars.size(); i++) {
    for (int j = 0; j < chars[i].size(); j++) {
      if (chars[i][j] != 'A') {
        continue;
      }

      if (i + 1 >= chars.size()) {
        continue;
      }
      if (i - 1 < 0) {
        continue;
      }
      if (j + 1 >= chars[i].size()) {
        continue;
      }
      if (j - 1 < 0) {
        continue;
      }

      if (chars[i - 1][j - 1] == 'M') {
        if (chars[i + 1][j + 1] == 'S') {
          if (chars[i - 1][j + 1] == 'M') {
            if (chars[i + 1][j - 1] == 'S') {
              res++;
            }
          }

          if (chars[i - 1][j + 1] == 'S') {
            if (chars[i + 1][j - 1] == 'M') {
              res++;
            }
          }
        }
      }

      if (chars[i - 1][j - 1] == 'S') {
        if (chars[i + 1][j + 1] == 'M') {
          if (chars[i - 1][j + 1] == 'M') {
            if (chars[i + 1][j - 1] == 'S') {
              res++;
            }
          }

          if (chars[i - 1][j + 1] == 'S') {
            if (chars[i + 1][j - 1] == 'M') {
              res++;
            }
          }
        }
      }

      // M M
      //  A
      // S S

      // S M
      //  A
      // S M

      // S S
      //  A
      // M M

      // M S
      //  A
      // M S
    }
  }
  std::cout << "Result: " << res;

  return 0;
}
