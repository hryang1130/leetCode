//
// Created by kevin on 2023/6/7.
//

#ifndef LEETCODEGITEE_SOLUTION2611_HPP
#define LEETCODEGITEE_SOLUTION2611_HPP

#include <vector>
#include <algorithm>
using namespace std;
//https://leetcode.cn/problems/mice-and-cheese/

class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        int res=0;
        for(int i=0;i<n;i++){
            res+=reward2[i];
            reward1[i]-=reward2[i];
        }
        sort(reward1.rbegin(), reward1.rend());
        for(int i=0;i<k;i++){
            res+=reward1[i];
        }
        return res;

    }
};

#endif //LEETCODEGITEE_SOLUTION2611_H
