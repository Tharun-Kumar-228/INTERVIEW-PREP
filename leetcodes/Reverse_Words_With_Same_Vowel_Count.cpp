class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int countVowels(const string &word) {
        int cnt = 0;
        for (char c : word) {
            if (isVowel(c)) cnt++;
        }
        return cnt;
    }

    string reverseWords(string s) {
        string parivontel = s;

        vector<string> words;
        string temp = "";

        
        for (char c : parivontel) {
            if (c == ' ') {
                words.push_back(temp);
                temp.clear();
            } else {
                temp += c;
            }
        }
        words.push_back(temp);

        int firstVowelCount = countVowels(words[0]);

        for (int i = 1; i < words.size(); i++) {
            if (countVowels(words[i]) == firstVowelCount) {
                reverse(words[i].begin(), words[i].end());
            }
        }
        string result = words[0];
        for (int i = 1; i < words.size(); i++) {
            result += " " + words[i];
        }

        return result;
    }
};
