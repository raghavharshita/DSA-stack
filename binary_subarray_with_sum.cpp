// ques-https://leetcode.com/problems/binary-subarrays-with-sum/description/
#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //normally
        map<int,int>mpp;
        mpp[0]=1;
        int sum=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int res=sum-goal;
            if(mpp.find(res)!=mpp.end()){
                count+=mpp[res];
            }
            mpp[sum]++;
        }
        return count;
    }
};
class Solution {
public:
    int solve(vector<int>&nums,int goal){
        if(goal<0)return 0;
        int left=0;
        int right=0;
        int sum=0;
        int count=0;
        while(right<nums.size()){
            sum+=nums[right];
            while(sum>goal){
                sum-=nums[left];
                left++;
            }
            count+=(right-left+1);
            right++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //sliding window
        return solve(nums,goal)-solve(nums,goal-1);
    }
};