//
// Created by kevin on 2023/6/22.
//

#ifndef LEETCODEGITHUB_PONDNUM_HPP
#define LEETCODEGITHUB_PONDNUM_HPP
#include <vector>
#include <algorithm>
using namespace std;

//https://leetcode.cn/problems/pond-sizes-lcci/description/
class Solution {
public:
    int dfs(vector<vector<int>>& land,int i,int j){
        land[i][j]=1;
        int res=1;
        int m=land.size(),n=land[0].size();
        for(int x=i-1;x<=i+1;x++){
            for(int y=j-1;y<=j+1;y++){
                if(x>=0 && x<m && y>=0 && y<n && land[x][y]==0){
                    res+=dfs(land,x,y);
                }
            }
        }
        return res;

    }
    vector<int> pondSizes(vector<vector<int>>& land) {
        vector<int> res;
        int m=land.size(),n=land[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(land[i][j]==0){
                    res.push_back(dfs(land,i,j));
                }
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};

#endif //LEETCODEGITHUB_PONDNUM_H
