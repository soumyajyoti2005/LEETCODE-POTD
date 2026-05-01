#include<iostream>
#include<vector>
#include<climits>
using namespace std;


int f(vector<int>& nums){
        int max_f = INT_MIN;
        int f0 = 0;
        int sum = 0;

        for(int i=0;i<nums.size();i++){
            f0 += i * nums[i];
            sum+=nums[i];
        }
        max_f = max(max_f,f0);

        int prev_f = f0;
        int next_f = 0;
        for(int k=1;k<nums.size();k++){
            next_f = prev_f + sum - nums.size() * nums[nums.size()-k];
            max_f = max(next_f,max_f);
            prev_f = next_f;
        }

        return max_f;
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
    cout<<f(nums);
}