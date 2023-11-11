//
// Created by kevin on 2023/11/11.
//

#ifndef LEETCODEGITHUB_SOLUTION1654_H
#define LEETCODEGITHUB_SOLUTION1654_H
#include <iostream>
#include <vector>
using namespace std;
class Solution {
        int dfs(vector<int>& roads, int i, int a, int b, int x, bool flag) {
            if (i <0 || roads[i]==-1) {
                return -1;
            }
            if(i>=x){
                return 0;
            }
            int r = dfs(roads,i+a, a, b, x, true);
            int l = -1;
            if (flag) {
                l = dfs(roads,i-b, a, b, x, false);
            }
            if (l==-1 && r!=-1) {
                return 1+r;
            }
            if(l!=-1 && r==-1) {
                return 1+l;
            }
            if (l!=-1 && r!=-1) {
                return 1+min(l,r);
            }
            return -1;
        }
        public:
        int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
            vector<int> roads(2010,0);
            for(auto idx : forbidden) {
                roads[idx]=-1;
            }
            int res  = dfs(roads,0,a,b,x, true);
            return res;
        }
};

#endif //LEETCODEGITHUB_SOLUTION1654_H
