class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.empty()) {
            return true;
        }
        bool allCaps = true;
        bool allSmall = true;
        bool firstOne = true;
        int n = word.size();
        if (n == 1 && word[0] >= 'A' && word[0] <= 'Z') {
            return true;
        }
        for (auto it : word) {
            if (it >= 'A' && it <= 'Z') {
                allSmall = false;
            } else if (it >= 'a' && it <= 'z') {
                allCaps = false;
            }
        }
        if (!(word[0] >= 'A' && word[0] <= 'Z')) {
            firstOne = false;
        }
        int j = 1;
        while (j < n) {
            char ch = word[j];
            if ((ch >= 'A' && ch <= 'Z')) {
                firstOne = false;
                break;
            }
            j++;
        }
        return allCaps || allSmall || firstOne;
    }
};