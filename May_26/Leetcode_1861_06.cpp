#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> res(n,vector<char>(m));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res[i][j] = box[j][i];
            }
        }

        for(auto &v : res){
            reverse(v.begin(),v.end());
        }

        for(int j=0;j<m;j++){
            for(int i=n-1;i>=0;i--){
                int stone_row = -1;

                if(res[i][j] == '.'){
                    for(int k=i-1;k>=0;k--){
                        if(res[k][j] == '*') break;
                        if(res[k][j] == '#'){
                            stone_row = k;
                            break;
                        }
                    }

                    if(stone_row != -1){
                         res[i][j] = '#';
                         res[stone_row][j] = '.';
                    }
                }
            }
        }

        return res;
    }

int main(){
    int m,n;
    cin>>m>>n;

    vector<vector<char>> box;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>box[i][j];
        }
    }

    rotateTheBox(box);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<box[i][j];
        }
        cout<<endl;
    }
    

}