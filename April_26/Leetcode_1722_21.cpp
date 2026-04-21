#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> parent,rankv;

int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void Union(int a,int b){
    a = find(a);
    b = find(b);
    if(a==b) return;

    if(rankv[a] < rankv[b]) swap(a,b);
    parent[b] = a;
    if(rankv[a] == rankv[b]) rankv[a]++;
}

int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        rankv.resize(n,0);

        for(int i=0;i<n;i++) parent[i] = i;

        for(auto &ele : allowedSwaps){
        Union(ele[0],ele[1]);
        }

        unordered_map<int,vector<int>> groups;

        for(int i=0;i<n;i++){
        groups[find(i)].push_back(i);
        }

        int ans = 0;

        for(auto &[p,idxs] : groups){
        unordered_map<int,int> freq;

        for(int i : idxs) freq[source[i]]++;

        for(int i: idxs){
            if(freq[target[i]] > 0) freq[target[i]]--;
            else ans++;
        }
        }

        return ans;
}

int main(){
    vector<int> source,target;
    int n;
    int s;
    cin>>n;
    cin>>s;
    vector<vector<int>> allowedswaps;
    for(int i=0;i<n;i++){
       int x,y;
       cin>>x,y;
       source.push_back(x);
       target.push_back(y);
    }

    for(int i=0;i<s;i++){
       int x,y;
       cin>>x,y;
       vector<int> v(2);
       v[0]=x;
       v[1]=y;
       allowedswaps.push_back(v);
    }

    cout<<minimumHammingDistance(source,target,allowedswaps);
    
}