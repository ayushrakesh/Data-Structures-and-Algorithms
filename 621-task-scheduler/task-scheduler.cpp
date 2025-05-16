class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m=tasks.size();
        int timer=1;

        multiset<pair<int,char>> maxheap;
        unordered_map<char,int> np,mp;

        for(int i=0;i<m;i++){
            np[tasks[i]]++;
        }
        for(auto it:np){
            maxheap.insert(make_pair(it.second,it.first));
        }
        
        while(true){
            auto it=maxheap.rbegin();

            while(it != maxheap.rend()){
                char c=it->second;
                int fre=it->first;

                if(mp[c] == 0 || (timer-mp[c])>n){
                    maxheap.erase(prev(it.base()));
                    if(fre-1 > 0){
                        maxheap.insert(make_pair(fre-1,c));
                    }
                    mp[c]=timer;
                    break;
                }
                ++it;
            }
            if(maxheap.empty())break;
            timer++;
        }
        return timer;
    }
};