//
// Created by kevin on 2023/6/2.
//

#ifndef LEETCODEGITEE_SOLUTION2559_HPP
#define LEETCODEGITEE_SOLUTION2559_HPP

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<int> nums;
        int cnt=0;
        for(auto word:words){
            char ch =word[0];
            int ch_ = word.back();
            if(ch=='a' || ch== 'e' || ch=='i' || ch=='o' || ch=='u'){
                if(ch_=='a' || ch_== 'e' || ch_=='i' || ch_=='o' || ch_=='u'){
                    cnt++;
                }
            }
            nums.push_back(cnt);
        }
        for(auto qu:queries){
            if(qu[0]==0){
                ans.push_back(nums[qu[1]]);
                continue;
            }
            ans.push_back(nums[qu[1]]-nums[qu[0]-1]);
        }

        return ans;
    }
};

#endif //LEETCODEGITEE_SOLUTION2559_HPP
