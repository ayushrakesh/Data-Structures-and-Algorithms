class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> gaps;
        int res=0;
        gaps.push_back(startTime[0]);
        int n=startTime.size();
        for(int i=1;i<n;i++){
            gaps.push_back(startTime[i]-endTime[i-1]);
        }
        gaps.push_back(eventTime-endTime[n-1]);

        int d=k+1;
        int m=gaps.size();
        int temp=0;

        for(int i=0;i<d;i++){
            temp+=gaps[i];
        }
        res=max(temp,res);
        for(int i=1;i<m-d+1;i++){
            temp+=gaps[i+d-1];
            temp-=gaps[i-1];
            res=max(res,temp);
        }
        return res;
    }
};