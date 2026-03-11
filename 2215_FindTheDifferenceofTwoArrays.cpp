#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() , m = nums2.size();
        unordered_set<int>set1,set2;
        vector<vector<int>> ans(2);

        for(int i=0; i<n; i++){
            set1.insert(nums1[i]);
        }

         for(int j=0; j<m; j++){
            set2.insert(nums2[j]);
        }

        for(const auto &e:set1){
            if(set2.find(e) == set2.end() ){
                ans[0].push_back(e);
            }
        }

        for(const auto &e:set2){
            if(set1.find(e) == set1.end() ){
                ans[1].push_back(e);
            }
        }

        return ans;
    }
}; 

int main(){
    Solution s;
    vector<int> nums1 = {1,2,3}, nums2 = {2,4,6};
    vector<vector<int>> ans = s.findDifference(nums1,nums2);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}