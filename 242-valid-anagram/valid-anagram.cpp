class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freq;
        int n = s.length();
        int m = t.length();
        if (n != m) {
            return false;
        }
        for (auto it : s) {
            freq[it]++;
        }
        for (auto it : t) {
            if (freq.find(it) == freq.end()) {
                return false;
            } else {
                freq[it]--;
                if (freq[it] == 0) {
                    freq.erase(it);
                }
            }
        }
        return freq.size() == 0 ? true : false;
    }
};