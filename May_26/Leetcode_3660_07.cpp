#include<iostream>
#include<vector>
using namespace std;

vector<int> pre_max(vector<int>& nums){
        vector<int> prefix_max(nums.size());
        prefix_max[0] = nums[0];

        int Max = nums[0];
        for(int i=1;i<nums.size();i++){
          Max = max(Max,nums[i]);
          prefix_max[i] = Max;
        }
        
        return prefix_max;
    }

vector<int> suf_min(vector<int>& nums){
    vector<int> suffix_min(nums.size());
    suffix_min[nums.size()-1] = nums[nums.size()-1];

    int Min = nums[nums.size()-1];
    for(int i=nums.size()-2;i>=0;i--){
    Min = min(Min,nums[i]);
    suffix_min[i] = Min;
    }

    return suffix_min;
}

vector<int> maxValue(vector<int>& nums) {
    int n = nums.size();
    vector<int> prefix_max = pre_max(nums);
    vector<int> suffix_min = suf_min(nums);
    vector<int> max_point(n);

    max_point[n-1] = prefix_max[n-1];
    for(int i = n-2;i>=0;i--){
        if(prefix_max[i] <= suffix_min[i+1]) max_point[i] = prefix_max[i];
        else max_point[i] = max_point[i+1];
    }


    return max_point;
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
    vector<int> max_point = maxValue(nums);
    for (auto x: max_point){
        cout<<x;
    }
}