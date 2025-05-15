class Solution {
public:
    long long fun(long long m) {
        long long sum = 0;
        while (m) {
            int r = (m % 10);
            sum += (r * r);
            m = m / 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        long long slow = n;
        long long fast = n;
        while (true) {
            slow=fun(slow);
            fast=fun(fun(fast));

            if(slow==fast){
                break;
            }
        }
        return fast==1;
    }
};