//
// Created by kevin on 2023/6/5.
//

#ifndef LEETCODEGITEE_SOLUTION0238_HPP
#define LEETCODEGITEE_SOLUTION0238_HPP

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int left[n];left[0]=nums[0];
        int right[n];right[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            left[i]=left[i-1]*nums[i];
            right[n-1-i]=right[n-i]*nums[n-1-i];
        }
        for(int i=0;i<n;i++){
            if(i>0 && i<n-1){
                nums[i]=right[i+1]*left[i-1];
                continue;
            }
            if(i==0){
                nums[i]=right[1];
                continue;
            }
            if(i==n-1){
                nums[i]=left[i-1];
                continue;
            }
        }

        return nums;

    }
};

#endif //LEETCODEGITEE_SOLUTION0238_H
