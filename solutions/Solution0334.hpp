//
// Created by kevin on 2023/6/6.
//

#ifndef LEETCODEGITEE_0334_HPP
#define LEETCODEGITEE_0334_HPP
//https://leetcode.cn/problems/increasing-triplet-subsequence/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3){
            return false;
        }
        int min=INT_MAX,mid = INT_MAX;
        for(auto num:nums){
            if(num<=min){
                min=num;
            }else if(num <= mid){
                mid=num;
            }else if(num > mid){
                return true;
            }
        }
        return false;
    }
};

#endif //LEETCODEGITEE_0334_H
