//
// Created by kevin on 2023/6/24.
//

#ifndef LEETCODEGITHUB_SOLUTION1647_HPP
#define LEETCODEGITHUB_SOLUTION1647_HPP

#include <string>
#include <map>
#include <cstring>
using namespace std;



class Solution {
public:
    int minDeletions(string s) {
        int cnts[26];memset(cnts,0,sizeof(cnts));
        for(auto ch:s){
            cnts[ch-'a']++;
        }
        map<int,int> nums;
        for(int i=0;i<26;i++){
            if(cnts[i]>0){
                if(!nums.count(cnts[i])){
                    nums[cnts[i]]=1;
                }else{
                    nums[cnts[i]]++;
                }

            }
        }
        int res=0;
        for(auto it:nums){
            while(it.second > 1){
                int tmp =it.first;
                int j;
                for(j=tmp-1;j>=0;j--){
                    if(nums.count(j)==0){
                        res+=tmp-j;
                        break;
                    }
                }
                if(j>0){
                    nums[j]=1;
                }
                it.second--;
            }
        }

        return res;

    }
};



#endif //LEETCODEGITHUB_SOLUTION1647_H
