class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int m = requests.size();
        int total = requests[0];
        int curr = requests[0];
        for (int i = 1; i < m; i++) {
            total = total + abs(requests[i] - curr);
            curr = requests[i];
        }
        return total;
    }
};