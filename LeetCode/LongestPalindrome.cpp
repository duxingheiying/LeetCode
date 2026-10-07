#include <string>
#include <iostream>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        const int n = s.length();
        if (n < 2) {
            return s;
        }
        else {
            int start = 0;
            int maxLength = 1;

            for (int i = 0; i < n; ++i) {
                // Odd length palindrome
                int left = i, right = i;
                while (left >= 0 && right < n && s[left] == s[right]) {
                    if (right - left + 1 > maxLength) {
                        start = left;
                        maxLength = right - left + 1;
                    }
                    --left;
                    ++right;
                }

                // Even length palindrome
                left = i, right = i + 1;
                while (left >= 0 && right < n && s[left] == s[right]) {
                    if (right - left + 1 > maxLength) {
                        start = left;
                        maxLength = right - left + 1;
                    }
                    --left;
                    ++right;
                }
            }

            return s.substr(start, maxLength);
        }
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    std::string input = "babad";
    // input = "cbbd";
     input = "abcdefga";
    std::string result = solution.longestPalindrome(input);
    std::cout << "Longest palindromic substring: " << result << std::endl;
    return 0;
}