#include <bits/stdc++.h>
using namespace std;

int removeStones(vector<vector<int>> &stones)
{
    int n = stones.size();
    unordered_map<pair<int, int>, int> mp;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int r = stones[i][0];
        int c = stones[i][1];
        if (mp.find({r, c}) == mp.end())
        {
            mp[{r, c}] = cnt;
            cnt++;
        }
    }

    for (auto it : mp)
    {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}
class Solution
{
public:
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        unordered_map<pair<int, int>, int> mp;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int r = stones[i][0];
            int c = stones[i][1];
            if (mp.find({r, c}) == mp.end())
            {
                mp[{r, c}] = cnt;
                cnt++;
            }
        }

        for (auto it : mp)
        {
            cout << it.first.first << " " << it.first.second << it.second << endl;
        }
        return 0;
    }
};
int main()
{
    vector<vector<int>> v = {{0, 0}, {1, 0}, {0, 1}};
    Solution s;
    cout << removeStones(v) << endl;
}
