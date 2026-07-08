#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>un;
        for(int i=0; i<nums1.size(); i++){
            un[nums1[i]]++;
        }
        vector<int>ans;
        for(int j=0; j<nums2.size(); j++){

            if(un[ nums2[j] ] > 0 ){
                ans.push_back( nums2[j] );
                un[nums2[j]]--;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int>nums1 = {4,9,5};
    vector<int>nums2 = {9,4,9,8,4};
    vector<int>ans = s.intersect(nums1, nums2);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl; 
    return 0;
}