#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int sz= height.size();

        int i=0 , j=sz-1;
        int cap =0, max_cap = 0;

        while(i<j){
            cap = min (height[i] , height[j]) * (j-i) ;
            max_cap = max(cap , max_cap);

            if(height[i] < height[j ]){
                i++;
            }
            else{ j--;}
        }

        return max_cap;
        
    }
};

int main(){
    Solution s;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout<<s.maxArea(height);
    cout<<endl;
    return 0;
}