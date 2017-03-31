// https://www.reddit.com/r/dailyprogrammer/comments/5zxebw/20170317_challenge_306_hard_generate_strings_to/

#include <iostream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

typedef std::pair<std::string, std::string> string_pair;

inline bool isspecial(char const c)
{
    if (c == '*' || c == '+' ||
        c == '[' || c == ']') {
        return true;
    } else {
        return false;
    }
}

std::string generate_match(std::string const &pattern)
{
    std::string ret;
    char cur;
    char prev = '\0';
    auto it = std::begin(pattern);

    // Generate the minimal passing string
    while (it != pattern.end()) {
        cur = *it++;

        if (cur == '*') {
            // Ignore previous char
            prev = '\0';
        } else if (cur == '+') {
            // Append previous char
            if (prev != '\0' && !isspecial(prev))
                ret += prev;
            prev = '\0';
        } else if (cur == '[') {
            // Append only the last char in range, skip everything else
            if (prev != '\0' && !isspecial(prev))
                ret += prev;
            while (cur != ']') {
                cur = *it++;
                if (!isspecial(cur))
                    prev = cur;
            }
            continue;
        } else if (isprint(cur)) {
            // Append previous char and set previous to current
            if (prev != '\0' && !isspecial(prev))
                ret += prev;
            prev = cur;
        }
    }

    if (!isspecial(cur))
        ret += cur;

    return ret;
}

int main(int argc, char *argv[])
{
    std::vector<string_pair> challenges = {
        {"a+b", "ab"},
        {"a+b+", "ab"},
        {"abcd", "abcd"},
        {"abc*d", "abd"},
        {"[az]b", "zb"},
        {"[c-z]b", "zb"},
        {"[c-z]+b", "zb"},
        {"[c-zA-Z]*b+", "b"},
        {"[A-Za-z0-9$.+!*'(){},~:;=@#%_\\-]*", ""},
        {"ab[c-l]+jkm9*10+", "abljkm10"},
        {"iqb[beoqob-q]872+0qbq*", "iqbq8720qb"}
    };

    for (auto && p : challenges) {
        std::string output = generate_match(p.first);
        std::cout << "Input:     " << p.first << "\n";
        std::cout << "Expecting: " << p.second << "\n";
        std::cout << "Output:    " << output << "\n";
        std::cout << "Result:    " << (output == p.second) << "\n\n";
    }

    return 0;
}
