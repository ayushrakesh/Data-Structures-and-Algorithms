class Solution {
public:
    multiset<int> max;
    multiset<int> min;

    void insert(int num) {
        if (max.empty() || num <= *max.rbegin()) {
            max.insert(num);
        } else
            min.insert(num);
        balance();
    }
    void remove(int num) {
        if(max.find(num) != max.end()){
            max.erase(max.find(num));
        }
        else if(min.find(num) != min.end()){
            min.erase(min.find(num));
        }
        balance();
    }
    void balance() {
        if (max.size() > min.size() + 1) {
            min.insert(*max.rbegin());
            max.erase(prev(max.end()));
        } else if (min.size() > max.size() + 1) {
            max.insert(*min.begin());
            min.erase(min.begin());
        }
    }
    double getMedian() {
        if (max.size() == min.size()) {
            double c = *max.rbegin();
            double d = *min.begin();
            return (c + d) / 2.00;
        }
        return max.size() > min.size() ? *max.rbegin() : *min.begin();
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        int n = nums.size();

        for (int i = 0; i < k; i++) {
            insert(nums[i]);
        }

        res.push_back(getMedian());

        for (int i = k; i < n; i++) {
            insert(nums[i]);
            remove(nums[i - k]);
            res.push_back(getMedian());
        }
        return res;
    }
};