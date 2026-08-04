class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxima = 0;
        for (int i = 0; i < n; i++) {
            if (i > maxima) {
                return false;
            }
            maxima = max(maxima, i + nums[i]);
            if (maxima >= n - 1) {
                return true;
            }
        }
        return true;
    }
};