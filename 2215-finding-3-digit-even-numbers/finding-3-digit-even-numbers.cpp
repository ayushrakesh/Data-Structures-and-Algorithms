class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> res;
        int n = digits.size();
        int t = 0;

        for (int i = 0; i < n; i++) {
            if (digits[i] == 0)
                continue;
            int a = digits[i] + t * 10;

            for (int j = 0; j < n; j++) {
                if(j==i)continue;
                int b = digits[j] + a * 10;
                for (int k = 0;
                     k < n; k++) {
                    if(k==i || k==j || (digits[k]%2==1))continue;
                    int c = digits[k] + b * 10;
                    res.insert(c);
                }
            }
        }
        vector<int> v;
        for(auto it:res){
                v.push_back(it);
        }
        sort(v.begin(),v.end());
        return v;
    }
};