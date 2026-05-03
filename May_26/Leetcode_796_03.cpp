#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void LPS(vector<int>& lps,string& pattern){
    int length =0;

    for(int i=1;i<pattern.length();i++){
        while(length>0 && pattern[i]!=pattern[length]) length = lps[length - 1];

        if(pattern[i] == pattern[length]){
            length++;
            lps[i] = length;
        }
    }
}

int KMP(string& s,string& pattern){
       vector<int> lps(pattern.length());
       LPS(lps,pattern);

       int m = pattern.length(), n = s.length(); 
       int i=0,j=0;

       while(i<n && j<m){
         if(s[i] == pattern[j]){
            i++;
            j++;
         }

         else{
            if(j!=0) j= lps[j-1];
            else i++;
         }
       }

       if(j==m) return i-j;
       else return -1;
}

bool rotateString(string& s, string& goal) {
        if(s.length() != goal.length()) return false;
        
        string t = s+s;
        int idx = KMP(t,goal);

        if(idx == -1) return false;
        else return true;

 }


int main(){
    string s,goal;
    cin>>s>>goal;

    cout<<rotateString(s,goal);
}