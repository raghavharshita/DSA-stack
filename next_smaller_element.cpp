#include<bits/stdc++.h>
using namespace std;
vector<int>nextsmaller(vector<int>num){
    int n=num.size();
    vector<int>ans(n);
    stack<int>st;
    st.push(-1);
    for(int i=n-1;i>=0;i--){
        while(st.top()!=-1 && num[i]<=st.top()){
            st.pop();
        }
        ans[i]=st.top();
        st.push(num[i]);
    }
    return ans;
}
int main(){
    vector<int>num={4,5,2,3,9,8,1,6,1};
    vector<int>ans=nextsmaller(num);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}