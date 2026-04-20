#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int maxDistance(vector<int>& colors) {
    unordered_map<int,int> high;
    unordered_map<int,int> low;

    for(int i=0;i<colors.size();i++){
        if(low.find(colors[i]) == low.end()) low[colors[i]] = i;
        high[colors[i]] = i;
    }

    int res = -1;
    for(auto l : low){
        for(auto h : high){
        if(l.first != h.first){
            int diff = h.second - l.second;
            if(diff < 0) diff *= -1;

            res = max(res,diff);
        }
        }
    }

    return res;
}

int main(){
    vector<int> colors;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
       int x;
       cin>>x;
       colors.push_back(x);
    }
    cout<<maxDistance(colors);
}
