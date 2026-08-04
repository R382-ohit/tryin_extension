class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int currentEnd = 0;
        int farthestEnd = 0;
        int jumps = 0;
        for (int i = 0; i < n - 1; i++) {
            farthestEnd = max(farthestEnd, i + nums[i]);
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthestEnd;

                if (currentEnd >= n - 1) {
                    break;
                }
            }
        }
        return jumps;
    }
};