#include <cctype>
#include <fstream>
#include <iostream>

int main() {
  std::ifstream file("input");
  std::string line;
  std::string word;
  std::string cond = "";
  int res = 0;

  while (std::getline(file, line) && line != "") {
    for (int i = 0; i < line.size(); i++) {
      if (std::isalpha(line[i]) || line[i] == '\'') {
          if (word == "" && line[i] == '\'') {
              continue;
          }
        word += line[i];
        std::cout << word << std::endl;
      } else if (word == "mul") {
        if (line[i] == '(') {
          i++;
          std::string a, b;
          char cur = line[i];

          while (std::isdigit(cur)) {
            a += cur;
            cur = line[++i];
          }

          if (a == "") {
            word = "";
            continue;
          }
          if (line[i] != ',') {
            word = "";
            continue;
          }

          i++;

          cur = line[i];
          while (std::isdigit(cur)) {
            b += cur;
            cur = line[++i];
          }

          if (b == "") {
            word = "";
            continue;
          }
          if (line[i] != ')') {
            word = "";
            continue;
          }

          /* std::cout << cond << " "; */
          if (cond == "do" || cond == "") {
            int c = std::stoi(a) * std::stoi(b);
            /* std::cout << a << " * " << b << " = " << c << std::endl; */
            res += c;
          }

          word = "";
          continue;
        } else {
          word = "";
          continue;
        }
      } else if (word == "don't") {
        std::cout << "aha? " << word << std::endl;
        if (line[i] == '(') {
          i++;
          if (line[i] == ')') {
            cond = "don't";
          }
        }

        word = "";
      } else if (word == "do") {
        std::cout << "aha? " << word << std::endl;
        if (line[i] == '(') {
          i++;
          if (line[i] == ')') {
            cond = "do";
          }
        }

        word = "";
      } else {
        std::cout << "aha? " << word << std::endl;
        word = "";
      }
    }
  }

  std::cout << "Result: " << res;

  return 0;
}
/* 158643511 too high */
/* 91365315 too low */
