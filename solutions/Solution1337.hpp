//
// Created by kevin on 2023/5/24.
//

#ifndef LEETCODEGITEE_SOLUTION1337_HPP
#define LEETCODEGITEE_SOLUTION1337_HPP

#include <vector>
#include <queue>
#include <cstring>
using namespace std;

class Solution {
public:
    double frogPosition(int n,vector<vector<int>>& edges,int t,int target){
        vector<vector<int>> g(n+1);
        for(auto edge:edges){
            int u=edge[0],v=edge[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        queue<pair<int,double>> q;q.emplace(1,1.000);
        bool isVis[n+1];
        memset(isVis, false, sizeof(isVis));
        isVis[1]= true;
        for(;q.size() && t>=0;t--){//走t步
            for(int k=q.size();k>0;k--){
                auto [u,p]=q.front();
                q.pop();
                int cnt = g[u].size()-(u!=1);//1没有父节点，其他都有
                if(u==target){
                    return cnt*t==0 ? p:0;
                }else{
                    for(int v:g[u]){
                        if(!isVis[v]){
                            isVis[v]= true;
                            q.emplace(v,p/cnt);
                        }
                    }
                }
            }
        }
        return 0;
    }


};


#endif //LEETCODEGITEE_SOLUTION1337_HPP
