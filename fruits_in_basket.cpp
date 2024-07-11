//ques -https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {
        int left=0;
        int right=0;
        int el1=-1,el2=-1;
        int maxi=0;
        int k=fruits[0];
        int initial=0;
        while(right<N){
            if(el1==-1){
                el1=fruits[right];
                k=el1;
                left=right;
            }
            else if(el2==-1 && el1!=fruits[right]){
                el2=fruits[right];
                k=el2;
                left=right;
            }
            else if(fruits[right]==el1 || fruits[right]==el2){
                if(fruits[right]!=k){
                    k=fruits[right];
                    left=right;
                }
            }
            else if(fruits[right]!=el1 && fruits[right]!=el2){
                maxi=max(maxi,right-initial);
                initial=left;
                if(el1!=fruits[left]){
                    el1=fruits[right];
                }
                else el2=fruits[right];
                k=fruits[right];
                left=right;
            }
            right++;
        }
        maxi=max(maxi,N-initial);
        return maxi;
    }
};

// striver's approach
class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {
        int left=0,right=0;
        int maxi=0;
        map<int,int>mpp;
        while(right<N){
            mpp[fruits[right]]++;
            if(mpp.size()<=2){
                maxi=max(maxi,right-left+1);
            }
            else{
                if(mpp[fruits[left]]>1){
                    mpp[fruits[left]]--;
                }
                else{
                    mpp.erase(fruits[left]);
                }
                left++;
            }
            right++;
        }
        return maxi;
    }
};