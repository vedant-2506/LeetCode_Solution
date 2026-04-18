#include<iostream>
#include<vector>
#include<unordered_map>


using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int,int>un;
        vector<int>ans;

        for(int i=0; i<nums1.size(); i++){
            un[nums1[i]]++;
        }

        for(int j=0; j<nums2.size(); j++){
            if(un.find( nums2[j]) != un.end() && un[nums2[j]] > 0){
                ans.push_back(  nums2[j]  );
                un[nums2[j]] = 0;
            }
        }
        
        return ans;
    }
};

int main(){

    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};

    Solution sol;
    vector<int> ans = sol.intersection(nums1,nums2);

    for(int i : ans){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}

