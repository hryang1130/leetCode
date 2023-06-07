//
// Created by kevin on 2023/6/7.
//

#ifndef LEETCODEGITEE_SOLUTION0443_HPP
#define LEETCODEGITEE_SOLUTION0443_HPP

#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size()==1){
            return 1;
        }
        int cnt=1;
        int index=1;
        char tmp =chars[0];
        //string res;res+=chars[0];
        for(int i=1;i<chars.size();i++){
            if(chars[i]==tmp){
                cnt++;
            }else{
                if(cnt > 1){
                    //添加数字
                    for(auto ch:to_string(cnt)){
                        chars[index++]=ch;
                    }
                }
                cnt=1;
                chars[index++]=chars[i];
                tmp=chars[i];
            }
        }
        if(cnt!=1){
            for(auto ch:to_string(cnt)){
                chars[index++]=ch;
            }
        }
        if(index < chars.size()){
            chars[index]='\0';
        }
        return index;
    }
};

#endif //LEETCODEGITEE_SOLUTION0443_H
