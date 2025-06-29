class Solution {
public:
    bool isUgly(int n) {
        return (n > 0) && (1073741824LL * 1162261467LL % n * 1220703125LL % n == 0);
    }
};