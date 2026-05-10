#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int f(int i,vector<int>& nums, int target,vector<int>& dp){
        if( i >= nums.size() ) return INT_MIN;
        if( i == nums.size()-1 ) return 0; 

        if(dp[i] != -1) return dp[i];

        int res = INT_MIN;
        for(int j=i+1;j<nums.size();j++){
            int x = nums[j]-nums[i];

            if(x <= target && x >= -target){
                int next = f(j,nums,target,dp);

                if(next != INT_MIN)
                   res = max(res,1+next);
            }
        }

        return dp[i] = res;
    }

int maximumJumps(vector<int>& nums, int target) {
        
    vector<int> dp(nums.size(),-1);
    
    int res = f(0,nums,target,dp);

    if(res == INT_MIN) return -1;
    return res;
}

int main(){
    vector<int> nums;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
       int x;
       cin>>x;
       nums.push_back(x);
    }

    int target;
    cin>>target;

    cout<<maximumJumps(nums,target);
    
}