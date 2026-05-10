#include<iostream>
#include<vector>
using namespace std;

void reverse_part_array(vector<int>& v,int si,int li){
        int t;
        for(int i=si,j=li;i<j;i++,j--){
            t=v[i];
            v[i]=v[j];
            v[j]=t;
        }
    }

void rotate(vector<int>& nums, int k) {
int l = nums.size();

k = k % l;

reverse_part_array(nums, 0, k - 1);
reverse_part_array(nums, k, l - 1);
reverse_part_array(nums, 0, l - 1);
}

vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
    int m = grid.size();
    int n = grid[0].size();

    int layers = min(m/2,n/2);

    for(int layer=0;layer<layers;layer++){

        int minr = layer;
        int minc = layer;
        int maxr = m-layer-1;
        int maxc = n-layer-1;

        vector<int> rotated;
        
        for(int i=minc;i<=maxc;i++){
            rotated.push_back(grid[minr][i]);
        }
        minr++;

        for(int i=minr;i<=maxr;i++){
            rotated.push_back(grid[i][maxc]);
        }
        maxc--;

        for(int i=maxc;i>=minc;i--){
            rotated.push_back(grid[maxr][i]);
        }
        maxr--;

        for(int i=maxr;i>=minr;i--){
            rotated.push_back(grid[i][minc]);
        }
        minc++;

        rotate(rotated,k);

        minr = layer;
        minc = layer;
        maxr = m-layer-1;
        maxc = n-layer-1;

        int k = 0;
        for(int i=minc;i<=maxc;i++){
            grid[minr][i] = rotated[k++];
        }
        minr++;

        for(int i=minr;i<=maxr;i++){
            grid[i][maxc] = rotated[k++];
        }
        maxc--;

        for(int i=maxc;i>=minc;i--){
            grid[maxr][i] = rotated[k++];
        }
        maxr--;

        for(int i=maxr;i>=minr;i--){
            grid[i][minc] = rotated[k++];
        }
        minc++;

    }

    return grid;
}

int main(){
    vector<vector<int>> grid;
    int m,n;
    cin>>m>>n;
    
    for(int i=0;i<m;i++){
        vector<int> nums;
        for(int j=0;j<n;j++){

        int x;
        cin>>x;
        nums.push_back(x);
        }
        grid.push_back(nums);
    }

    int k;
    cin>>k;
    
    rotateGrid(grid,k);

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }

    
}