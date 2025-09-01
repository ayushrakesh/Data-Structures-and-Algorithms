class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n=classes.size();
        priority_queue<pair<double,pair<int,int>>> pq;

        for(int i=0;i<n;i++){
            int p=classes[i][0];
            int t=classes[i][1];
            pq.push({ ((double)(p+1)/(double)(t+1)) - ((double)p/(double)t) , {p,t}});
        }

        while(extraStudents--){
            double gain=pq.top().first;
            int p = pq.top().second.first;
            int t=pq.top().second.second;
            pq.pop();

            pq.push({ ((double)(p+2)/(double)(t+2)) - ((double)(p+1)/(double)(t+1)) ,{p+1,t+1}});
        }
        double res=0.0;
        while(!pq.empty()){
            double p=pq.top().second.first;
            double t=pq.top().second.second;
            pq.pop();

            res+= p/t;
        }
        return res/n;
    }
};