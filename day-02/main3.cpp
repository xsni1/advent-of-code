#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

bool is_safe_report(const std::vector<int>& levels) {
    // Check if levels are consistently changing within 1-3 range
    auto is_consistent_change = [](const std::vector<int>& seq) {
        for (size_t i = 0; i < seq.size() - 1; ++i) {
            int diff = std::abs(seq[i+1] - seq[i]);
            if (diff == 0 || diff > 3) return false;
        }
        return true;
    };

    // Check original report
    if (is_consistent_change(levels)) return true;

    // Try removing each level
    for (size_t i = 0; i < levels.size(); ++i) {
        std::vector<int> modified_levels = levels;
        modified_levels.erase(modified_levels.begin() + i);
        if (is_consistent_change(modified_levels)) return true;
    }

    return false;
}

int count_safe_reports(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    int safe_count = 0;

    while (std::getline(file, line)) {
        std::vector<int> levels;
        std::istringstream iss(line);
        int num;
        while (iss >> num) {
            levels.push_back(num);
        }

        if (is_safe_report(levels)) {
            ++safe_count;
        }
    }

    return safe_count;
}

int main() {
    std::string s = "icodeinpython";
    std::string res = s;
    std::vector<int> spaces = {1, 5, 7, 9};

    for (int i = 0; i < spaces.size(); i++) {

        res = res.substr(0, spaces[i]+i) + " " + res.substr(spaces[i]+i, res.size() - spaces[i]);
    }

        /* res = res.substr(0, 1) + " " + res.substr(1, res.size() - 1); */
    std::cout << res;

    return 0;
}
