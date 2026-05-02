#include<iostream>
#include<vector>
#include<climits>
using namespace std;


bool isgood(int n){
    bool good = false;

    while(n){
        int r = n%10;
        
        if(r == 3 || r == 4 || r == 7) return false;
        if(r == 2 || r == 5 || r == 6 || r == 9) good = true;

        n/=10;
    }

    return good;
   }

int rotatedDigits(int n) {
    int good_nums = 0;

    for(int i=1;i<=n;i++){
        bool is_good_num = isgood(i);
        if(is_good_num) good_nums++;
    }

    return good_nums;
   }


int main(){
    vector<int> nums;
    int n;
    cin>>n;
    
    cout<<rotatedDigits(n);
}