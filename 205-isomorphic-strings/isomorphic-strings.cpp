class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s_t;
        unordered_map<char, char> t_s;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            char s_i = s[i];
            char t_i = t[i];
            // s->t mapping
            if (s_t.find(s_i) != s_t.end()) {
                if (s_t[s_i] != t_i) {
                    return false;
                }
            } else {
                s_t[s_i] = t_i;
            }
            // t->s mapping
            if (t_s.find(t_i) != t_s.end()) {
                if (t_s[t_i] != s_i) {
                    return false;
                }
            } else {
                t_s[t_i] = s_i;
            }
        }
        return true;
    }
};