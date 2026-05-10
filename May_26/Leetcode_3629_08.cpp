#include<iostream>
#include<vector>
#include<climits>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<queue>
using namespace std;

void Sieve(int n,vector<int>& ans) {
        ans[0] = 0;
        ans[1] = 0;
        for (int i = 2; i <= sqrt(n); i++){
            if (ans[i] == 1){
                int j = i + i;

                while (j < n){
                    ans[j] = 0;
                    j = j + i;
                }
            }
        }
    }

bool isprime(vector<int>& nums,int num){
    
    return (bool)nums[num];
}

int minJumps(vector<int>& nums) {
    if(nums.size() == 1) return 0;
    int Max = INT_MIN;

    for(int i=0;i<nums.size();i++){
        Max = max(Max,nums[i]);
    }

    vector<int> ans(Max + 1, 1);
    Sieve(Max+1,ans);

    unordered_map<int,unordered_set<int>> index_map;
    unordered_set<int> usedPrime;

    for(int i=0;i<nums.size();i++){
        index_map[nums[i]].insert(i);
    }
    
    int cost = 0;
    queue<int> q;
    vector<bool> visited(nums.size(),false);
    
    q.push(0);
    visited[0] = true;
    while(q.size() != 0){
        int n = q.size();

        for(int i=1;i<=n;i++){
            int x = q.front();
            q.pop();

            if(x+1 < nums.size() && !visited[x+1]){
                    q.push(x+1);
                    visited[x+1] = true;
            }
            if(x-1 >= 0 && !visited[x-1]){
                    q.push(x-1);
                    visited[x-1] = true;
            }

            if(isprime(ans,nums[x]) && !usedPrime.count(nums[x])){
                int num = nums[x];
                usedPrime.insert(num);

                for(int multiple = num; multiple <= Max; multiple += num){

                    if(index_map.count(multiple)){

                        for(auto idx : index_map[multiple]){

                            if(!visited[idx]){
                                q.push(idx);
                                visited[idx] = true;
                            }
                        }
                    }
                }
            }
        }
        cost++;
        if(visited[nums.size() - 1]) break;
    }

    return cost;
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
    
    int min_jumps = minJumps(nums);
    cout<<min_jumps;
}