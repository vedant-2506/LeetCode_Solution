#include<vector>
#include<climits>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>ans(2*n);

        for(int i=0; i<n; i++){
            ans[i]   = nums[i];
            ans[n+i] = nums[i];
        }

        return ans;
    }
};

int main(){

    int n=0,i=0;
    cout<<"Enter size of array:";
    cin>>n;

    vector<int>nums(n);
    cout<<"Enter elements in array :";
    for(i=0;i<n;i++){
        cin>>nums[i];
    }

    Solution obj;

    vector<int>ans(2*n);

    ans = obj.getConcatenation(nums);

    cout<<"Answer arry is :";
    for(i=0;i<2*n;i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}