//
// Created by kevin on 2023/5/26.
//

#ifndef LEETCODEGITEE_SOLUTION1091_HPP
#define LEETCODEGITEE_SOLUTION1091_HPP
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
class Solution {
public:
    int row_d[3]={-1,0,1};
    int col_d[3]={-1,0,1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1){
            return -1;
        }
        queue<pair<int,int>> que;que.emplace(0,0);
        int ans=1;
        grid[0][0]=1;
        int n=grid.size();
        while(que.size() > 0){
            for(int k=que.size();k>0;k--){
                auto [u,v]=que.front();
                que.pop();
                if(u==n-1 && v==n-1){
                    return ans;
                }else{
                    for(int i=0;i<3;i++){
                        for(int j=0;j<3;j++){
                            if(u+row_d[i]>=0 && u+row_d[i]<n && v+col_d[j]>=0 && v+col_d[j]<n){
                                if(grid[u+row_d[i]][v+col_d[j]]==0){
                                    que.emplace(u+row_d[i],v+col_d[j]);
                                    grid[u+row_d[i]][v+col_d[j]]=1;
                                }
                            }
                        }
                    }
                }
            }
            if(!que.empty()){
                ans++;
            }
        }
        return -1;
    }
};
#endif //LEETCODEGITEE_SOLUTION1091_HPP
