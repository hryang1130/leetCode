//
// Created by kevin on 2023/6/6.
//

#ifndef LEETCODEGITEE_SOLUTION2352_HPP
#define LEETCODEGITEE_SOLUTION2352_HPP

//https://leetcode.cn/problems/equal-row-and-column-pairs/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int> sets;
        for(auto nums:grid){
            if(sets.count(nums)>0){
                sets[nums]++;
            }else{
                sets[nums]=1;
            }
        }
        int n = grid.size();
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int> tmp;
            for(int j=0;j<n;j++){
                tmp.push_back(grid[j][i]);
            }
            if(sets.count(tmp)>0){
                ans+=sets[tmp];
            }
        }

        return ans;
    }
};

#endif //LEETCODEGITEE_SOLUTION2352_H
