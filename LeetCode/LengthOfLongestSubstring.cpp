#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>

class Solution {
public: 
    int lengthOfLongestSubstring(std::string s) {
        int n = s.length();
        int maxLength = 0;
        std::unordered_map<char, int> charIndexMap;
        int start = 0;

        for (int end = 0; end < n; ++end) {
            char currentChar = s[end];

            if (charIndexMap.find(currentChar) != charIndexMap.end()) {
                start = std::max(start, charIndexMap[currentChar] + 1);
            }

            charIndexMap[currentChar] = end;
            maxLength = std::max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    std::string input = "abcabcbb";
    // input = "bbbbb";
    // input = "pwwkew";
    int result = solution.lengthOfLongestSubstring(input);
    std::cout << "Length of longest substring without repeating characters: " << result << std::endl;
    return 0;
}