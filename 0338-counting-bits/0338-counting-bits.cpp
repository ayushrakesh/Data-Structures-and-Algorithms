class Solution {
public:
    int countsetbits(int n) {
        int cnt = 0;
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i))
                cnt++;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int> res(n + 1, -1);

        for (int i = 0; i <= n; i++) {
            res[i] = countsetbits(i);
        }
        return res;
    }
};