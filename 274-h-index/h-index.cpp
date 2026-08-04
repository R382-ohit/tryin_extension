class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int h = 0;
        for (int i = 1; i <= n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (citations[j] >= i) {
                    cnt++;
                }
            }
            if (cnt >= i) {
                h = i;
            }
        }
        return h;
    }
};