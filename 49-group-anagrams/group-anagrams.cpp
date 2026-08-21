class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty()) {
            return {{}};
        }
        if (strs.size() == 1) {
            return {strs};
        }
        unordered_map<string, vector<string>> mpp;
        for (auto it : strs) {
            auto tmp = it;
            sort(tmp.begin(), tmp.end());
            mpp[tmp].push_back(it);
        }
        vector<vector<string>> ans;
        for (auto it : mpp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};