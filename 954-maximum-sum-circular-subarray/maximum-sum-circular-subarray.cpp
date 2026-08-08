class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        /* if (nums.size() == 1) {
            return nums[0];
        }
        */
        int total = 0;
        int c_max = 0;
        int max_sum = nums[0];
        int c_min = 0;
        int min_sum = nums[0];
        for (int x : nums) {
            c_max = max(c_max + x, x);
            max_sum = max(max_sum, c_max);
            c_min = min(c_min + x, x);
            min_sum = min(min_sum, c_min);
            total += x;
        }
        if (max_sum < 0)
            return max_sum;
        return max(max_sum, total - min_sum);
    }
};