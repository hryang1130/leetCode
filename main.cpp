//
// Created by kevin on 2023/5/24.
//
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int> S(forbidden.begin(), forbidden.end());
        queue<pair<int,int>> q;    // pair<idx ,can_jump_left_flag>
        q.emplace(0,0);
        int n = 6000;
        bool vis[n][2];
        int ans = 0;
        memset(vis,false, sizeof(vis));
        ans++;
        while(!q.empty()) {
            int t = q.size();
            for (t;t>0;t--){
                auto [i,k]=q.front();
                q.pop();
                if (x==i){
                    return ans;
                }
                vector<pair<int,int>> nxts = {{i+a,1}};
                if(k==1){
                    nxts.push_back({i-b,0});
                }
                for (auto [i,k] :nxts) {
                    if (i >= 0 && i < n && !S.count(i) && !vis[i][k]) {
                        vis[i][k] = true;
                        q.emplace(i, k);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
int main(){
    vector<int> forbidens = {1,6,2,14,5,17,4};
    int a = 16;
    int b = 9;
    int x = 7;
    Solution s;
    std::cout << "res :" << s.minimumJumps(forbidens,16,9,7) << std::endl;
    return 0;
}
