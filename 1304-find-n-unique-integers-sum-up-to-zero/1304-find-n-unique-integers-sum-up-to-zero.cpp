class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        int cnt=1;
        for(int i=0;i<(n/2);i++){
            res.push_back(cnt);
            res.push_back(-cnt);
            cnt++;
        }
        if(n%2==1)res.push_back(0);
        return res;
    }
};