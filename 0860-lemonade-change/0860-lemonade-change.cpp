class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();

        int a = 0, b = 0, c = 0;

        for (int i = 0; i < n; i++) {
            if (bills[i] == 5) {
                a++;
            } else if (bills[i] == 10) {
                if (a > 0) {
                    b++;
                    a--;
                } else
                    return false;
            } else {
                if (b >= 1 && a >= 1) {
                    c++;
                    b--;
                    a--;
                } else if (a >= 3) {
                    c++;
                    a = a - 3;
                } else
                    return false;
            }
        }
        return true;
    }
};