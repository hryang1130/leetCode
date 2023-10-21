#include <iostream>
#include <vector>
#include <cstring>
#include <functional>
using namespace std;
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> path[n];
        for(auto k : edges) {
            path[k[0]].push_back(k[1]);
            path[k[1]].push_back(k[0]);
        }
        bool vis[n];
        memset(vis,0,sizeof(vis));
        function<int(int)>dfs = [&](int i) {
            if(vis[i]== true) {
                return 0;
            }
            vis[i] = true;
            int cnt=1;
            for (int j:path[i]){
                cnt+=dfs(j);
            }
            return cnt;
        };
        long long ans =0,s=0;
        for(int i=0;i<n;i++) {
            int t = dfs(i);
            ans+=s*t;
            s+=t;
        }
        return ans;

    }
};