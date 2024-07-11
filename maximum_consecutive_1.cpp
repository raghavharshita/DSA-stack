//ques- https://leetcode.com/problems/max-consecutive-ones-iii/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int zero=0;
        int left=0;
        int right=0;
        int maxlen=0;
        while(right<n){
            if(nums[right]==0)zero++;
            if(zero<=k)maxlen=max(maxlen,right-left+1);
            else{
                if(nums[left]==0)zero--;
                left++;
            }
            right++;
        }
        return maxlen;
    }
};