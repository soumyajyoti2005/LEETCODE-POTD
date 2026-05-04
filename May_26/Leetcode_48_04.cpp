#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void reverse(vector<int> &v, int x, int y)
{
    int t;
    for (int i = x, j = y; i < j; i++, j--)
    {
        t = v.at(i);
        v.at(i) = v.at(j);
        v.at(j) = t;
    }
    return;
}
    
void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
    return;
}

void rotate(vector<vector<int>>& matrix) {
   
    int n= matrix.size();
    for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j > i)
                    swap(&matrix[i][j], &matrix[j][i]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            reverse(matrix[i], 0, n - 1);
        }
    return;
}


int main(){
    vector<vector<int>> nums;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        vector<int> v;
        for(int j=0;j<n;j++) {
            int x;
            cin>>x;
            v.push_back(x);
        }
        nums.push_back(v);
    }
    
    rotate(nums);
    
    cout<<"Rotated Array: ";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) {
            cout<<nums[i][j]<<" ";
        }
        cout<<endl;
    }

}