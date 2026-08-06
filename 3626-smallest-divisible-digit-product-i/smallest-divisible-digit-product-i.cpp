class Solution {
public:
    bool isDiv(int n, int t) {
        long long prod = 1;
        while (n > 0) {
            int dig = n % 10;
            prod *= dig;
            n = n / 10;
        }
        return prod % t 
        == 0;
    }

    int smallestNumber(int n, int t) {
        for (int i = n;; i++) {
            if (isDiv(i, t)) {
                return i;
            }
        }
        return -1;
    }
};