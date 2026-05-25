#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        vector<int>ans(m+n);

        int i=0;
        for(int i =0; i<m;i++){
           ans[i] = nums1[i];
        }

        int j=0 , k=m;
        while(j<n){
            ans[k] = nums2[j];
            
            k++;
            j++;
        }

        sort(ans.begin() , ans.end());

        nums1 = ans;

    }
};

int main(){

    vector<int>nums1 = {1,2,3,0,0,0};
    vector<int>nums2 = {2,5,6};

    int m = 3;
    int n = 3;

    Solution s;
    s.merge(nums1 , m , nums2 , n);

    for(int i=0;i<nums1.size();i++){
        cout<<nums1[i]<<" ";
    }
    cout<<endl;

    return 0;
}