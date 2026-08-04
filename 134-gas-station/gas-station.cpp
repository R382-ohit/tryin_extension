class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        // begin the journey with an empty tank at one of the gas stations
        // we need to return the starting index if can travel around the circle
        // once in clockwise direction

        /*Edge case checking*/
        long long gas_tot = accumulate(gas.begin(), gas.end(), 0);
        long long cost_tot = accumulate(cost.begin(), cost.end(), 0);
        if (gas_tot < cost_tot) {
            return -1;
        }
        /*now begins the real traversing problem*/
        vector<int> check(n, 0);
        for (int i = 0; i < n; i++) {
            check[i] = gas[i] - cost[i];
        }

        long long curr = 0;
        long long start = 0;
        for (int i = 0; i < n; i++) {
            curr += check[i];
            if (curr < 0) {
                curr = 0;
                start = i + 1;
            }
        }
        return start;
    }
};