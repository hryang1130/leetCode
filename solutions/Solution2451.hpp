//
// Created by kevin on 2023/5/25.
//

#ifndef LEETCODEGITEE_SOLUTION2451_HPP
#define LEETCODEGITEE_SOLUTION2451_HPP
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    string oddString(vector<string>& words) {
        int num=words.size();
        int index =0;
        std::map<string,int> remark;
        std::map<string,int> idx;
        for(int i=0;i<num;i++){
            int len = words[i].size();
            string tem;
            for(int j=0;j<len-1;j++){
                tem+=words[i][j+1]-words[i][j]+'a';
            }
            if(remark.count(tem)){
                idx[tem]=-1;
                remark[tem]++;
            } else{
                remark[tem]=1;
                idx[tem]=i;
            }
        }
        for(auto r:idx){
            if(r.second!=-1){
                return words[r.second];
            }
        }
        return "";


    }
};

#endif //LEETCODEGITEE_SOLUTION2451_HPP
