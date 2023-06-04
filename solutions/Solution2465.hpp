//
// Created by kevin on 2023/6/4.
//

#ifndef LEETCODEGITEE_SOLUTION2465_HPP
#define LEETCODEGITEE_SOLUTION2465_HPP
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        set<float> cnts;
        sort(nums.begin(),nums.end());
        int r=nums.size()-1,l=0;
        while(l<r){
            cnts.insert(float(nums[l]+nums[r])/2.0);
            l++;
            r--;
        }

        return cnts.size();
    }
};


#endif //LEETCODEGITEE_SOLUTION2465_HPP
