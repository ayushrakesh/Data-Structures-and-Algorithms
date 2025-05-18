class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        priority_queue<pair<int, char>> p;
        unordered_map<char, int> m;

        // Count character frequencies
        for (char c : s) 
            m[c]++;
        
        // Push into max-heap (priority queue)
        for (auto it : m) {
            // if (it.second > (n + 1) / 2)  // Early check for impossible case
            //     return "";
            p.push({it.second, it.first});
        }

        string res = "";

        while (!p.empty()) {
            int f = p.top().first;
            char c = p.top().second;
            p.pop();

            if (res.empty() || res.back() != c) {
                res.push_back(c);
                if (--f > 0) 
                    p.push({f, c});
            } 
            else {
                if (p.empty()) 
                    return "";  

                int g = p.top().first;
                char d = p.top().second;
                p.pop();

                res.push_back(d);
                if (--g > 0) 
                    p.push({g, d});

                p.push({f, c});  
            }
        }

        return res;
    }
};
