class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int prod = 1;
        int tmp = n;
        while(tmp>0){
            int dig = tmp%10;
            tmp /= 10;
            sum += dig;
            prod *= dig;
        }
        return n % (sum+prod) == 0;
    }
};