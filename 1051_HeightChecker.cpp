#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {

        int sz= heights.size();
        vector<int>sorted(heights);

        sort(sorted.begin() ,sorted.end() );

        int count=0;
        for(int i=0; i<sz;i++){
            if(heights[i] != sorted[i]){
                count ++;

            }
        }
        
        return count;
    }
};

int main(){

    int n;
    cout<<"Enter a sutdent height and output give how many students are not in the right position"<<endl;
    cout<<"Enter number of student :";
    cin>>n;

    vector<int>height(n);
    for(int i=0; i<n; i++){
        cin>>height[i];
    }

    Solution sol;

    int result = sol.heightChecker(height);

    cout<<"Number of students not in the right position is  "<<result<<endl;

    return 0;

}