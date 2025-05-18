    struct pair_hash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };

    class Solution {
    public:
        vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
            unordered_map<pair<int,int>,bool,pair_hash> mp;
            priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
            vector<vector<int>> res;

            int m=nums1.size();
            int n=nums2.size();

            pq.push({nums1[0]+nums2[0],0,0});
            mp[{0,0}]=true;

            while(!pq.empty()){
                int ind1=pq.top()[1];
                int ind2=pq.top()[2];
                pq.pop();

                if(k){
                    res.push_back({nums1[ind1],nums2[ind2]});
                    k--;
                    if(!k)break;
                }

                if(ind1+1 < m && mp[{ind1+1,ind2}]==false){
                    pq.push({nums1[ind1+1]+nums2[ind2],ind1+1,ind2});
                    mp[{ind1+1,ind2}]=true;
                }
                if(ind2+1 < n && mp[{ind1,ind2+1}]==false){
                    pq.push({nums1[ind1]+nums2[ind2+1],ind1,ind2+1});
                    mp[{ind1,ind2+1}]=true;
                }
                if(ind1+1<m && ind2+1<n && mp[{ind1+1,ind2+1}]==false){
                    pq.push({nums1[ind1+1]+nums2[ind2+1],ind1+1,ind2+1});
                    mp[{ind1+1,ind2+1}]=true;
                }
            }
            return res;
        }
    };