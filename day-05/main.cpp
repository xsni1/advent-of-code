#include <fstream>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <sstream>

void test(int target, std::unordered_map<int, std::vector<int>> graph, std::unordered_set<int>* deps, std::unordered_set<int>* visited) {
    std::vector<int> cur = graph[target];
    /* for (auto a : cur) { */
    /*     std::cout << a << " "; */
    /* } */
    /* std::cout << std::endl; */

    for (int i = 0; i < cur.size(); i++) {
        /* if ((*visited).find(cur[i]) != (*visited).end()) { */
        /*     return; */
        /* } */

        /* (*visited).insert(cur[i]); */

        if ((*deps).find(cur[i]) == (*deps).end()) {
            (*deps).insert(cur[i]);
            test(cur[i], graph, deps, visited);
        }
    }
}

bool isOrdered(std::unordered_map<int, std::vector<int>> m, std::vector<int> line) {
    for (int i = 0; i < line.size(); i++) {
        std::vector<int> abc = m[line[i]];

        for (int j = i+1; j < line.size(); j++) {
            for (int k = 0; k < abc.size(); k++) {
                if (abc[k] == line[j]) {
                    return false;
                }
            }
        }
    }

    return true;
}

int main() {
    std::ifstream file("input");
    std::string line;
    std::unordered_map<int, std::vector<int>> m;
    int res = 0;

    while (std::getline(file, line) && line != "") {
        int idx = line.find("|");
        int dependency = std::stoi(line.substr(0, idx));
        int dependant = std::stoi(line.substr(idx+1, line.size()-idx));

        m[dependant].push_back(dependency);
    }
    std::vector<std::vector<int>> lines;

    while (std::getline(file, line) && line != "") {
        std::istringstream ss(line);
        std::string token;
        std::vector<int> vline;

        while (std::getline(ss, token, ',')) {
            vline.push_back(std::stoi(token));
        }
        lines.push_back(vline);
    }

    for (std::vector<int> line : lines) {
        int s = 0;
        bool notSorted = false;

        do {
            notSorted = false;

            for (int i = 0; i < line.size(); i++) {
                std::vector<int> abc = m[line[i]];

                for (int j = i+1; j < line.size(); j++) {
                    for (int k = 0; k < abc.size(); k++) {
                        if (abc[k] == line[j]) {
                            notSorted = true;

                            int tmp = line[i];
                            line[i] = line[j];
                            line[j] = tmp;
                            s++;

                            break;
                        }
                    }

                    if (notSorted) {
                        break;
                    }
                }
            }
        } while(notSorted);

        if (s > 0) {
            res += line[line.size()/2];
        }

    }

    std::cout << "Result: " << res << std::endl;
    return 0;
}
