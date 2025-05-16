// class Solution {
// public:
//     int leastInterval(vector<char>& tasks, int n) {
//         int m=tasks.size();
//         int timer=1;

//         multiset<pair<int,char>> maxheap;
//         unordered_map<char,int> mp;

//         for(int i=0;i<m;i++){
//             mp[tasks[i]]++;
//         }
//         for(auto it:mp){
//             maxheap.insert(make_pair(it.second,it.first));
//             it.second=0;
//         }
        
//         while(!maxheap.empty()){
//             auto it=maxheap.rbegin();

//             while(it != maxheap.rend()){
//                 char c=it->second;
//                 int fre=it->first;

//                 if(mp[c] == 0 || (timer-mp[c])>n){
//                     maxheap.erase(prev(it.base()));
//                     if(fre-1 > 0){
//                         maxheap.insert(make_pair(fre-1,c));
//                     }
//                     mp[c]=timer;
//                     break;
//                 }
//                 ++it;
//             }
//             // if(maxheap.empty())break;
//             timer++;
//         }
//         return timer;
//     }
// };

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m = tasks.size();
        int timer = 1;

        multiset<pair<int, char>> maxheap;
        unordered_map<char, int> mp;  // char -> last used time

        // Count frequencies
        unordered_map<char, int> freq;
        for (char c : tasks) {
            freq[c]++;
        }

        // Build initial heap
        for (auto& it : freq) {
            maxheap.insert({it.second, it.first});
        }

        while (!maxheap.empty()) {
            bool task_scheduled = false;

            auto it = maxheap.rbegin();
            while (it != maxheap.rend()) {
                char c = it->second;
                int f = it->first;

                if (mp[c] == 0 || (timer - mp[c]) > n) {
                    // Can schedule this task
                    maxheap.erase(prev(it.base())); // safely convert reverse iterator
                    if (f - 1 > 0) {
                        maxheap.insert({f - 1, c});
                    }
                    mp[c] = timer;
                    task_scheduled = true;
                    break;
                }
                ++it;
            }

            // If no task scheduled, CPU idles but time still passes
            timer++;
        }

        return timer - 1; // subtract 1 because last increment happens after last task
    }
};
