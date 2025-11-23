class Solution {
public:
    vector<string> result;
    vector<string> mapping = {
        "",    // 0
        "",    // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs",// 7
        "tuv", // 8
        "wxyz" // 9
    };

    void backtrack(string &digits, int index, string current) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        string letters = mapping[digits[index] - '0'];

        for (char c : letters) {
            backtrack(digits, index + 1, current + c);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        backtrack(digits, 0, "");
        return result;
    }
};
