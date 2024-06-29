#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>num2,int n){
    int m=num2.size();
    vector<int>temp(m);
    stack<int>st;
    st.push(-1);
    for(int i=m-1;i>=0;i--){
        while(st.top()!=-1 && st.top()<=num2[i]){
            st.pop();
        }
        temp[i]=st.top();
        st.push(num2[i]);
    }
    for(int i=0;i<m;i++){
        if(num2[i]==n){
            return temp[i];
        }
    }
    return -1;
}
vector<int>nextgreaterelement(vector<int>num1,vector<int>num2){
    vector<int>ans;
    for(int i=0;i<num1.size();i++){
        int t=solve(num2,num1[i]);
        ans.push_back(t);
    }
    return ans;
}
int main(){
    vector<int>num1={4,1,2};
    vector<int>num2={1,3,4,2};
    vector<int>change=nextgreaterelement(num1,num2);
    for(int i=0;i<change.size();i++){
        cout<<change[i]<<" ";
    }
}