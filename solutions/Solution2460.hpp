//
// Created by kevin on 2023/6/5.
//

#ifndef LEETCODEGITEE_SOLUTION2460_HPP
#define LEETCODEGITEE_SOLUTION2460_HPP
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]=2*nums[i];
                nums[i+1]=0;
            }
            if(nums[i]!=0){
                nums[cnt++]=nums[i];
            }
        }
        if(nums.back()!=0){
            nums[cnt++]=nums.back();
        }
        for(int j=cnt;j<nums.size();j++){
            nums[j]=0;
        }
        return nums;

    }
};

#endif //LEETCODEGITEE_SOLUTION2460_HPP
