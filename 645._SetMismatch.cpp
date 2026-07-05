#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<unordered_map>


using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        // //find dublicate & missing TC=O(n^2) SC=O(1)
        // int n = nums.size();
        // int duplicate=-1, missing =-1;
        // for(int i=1; i<=n; i++){
        //     int count=0;
        //     for(int j=0; j<n; j++){
        //         if(nums[j] ==i)
        //           count++;
        //     }
        //     if(count == 2) duplicate = i;
        //     if(count == 0) missing = i;
        // }
        // return {duplicate , missing};
       

        //using hash map TC=O(n) SC=O(n)
        unordered_map<int,int>un;
        vector<int>ans;
        int n=nums.size();
        //for finding repeting or dublicate 
        for(int i=0; i<n; i++){
            un[nums[i]]++;
        }
       //dublicate number store in ans 
       for(auto i : un){
        if(i.second== 2)
         ans.push_back(i.first);
       }
       //find number how not in array 
       for(int l=1; l<=n; l++){
        if( un.find(l) == un.end()){
           ans.push_back(l);
           break;
        }
       }
       return ans;


    }
};

int main() {

    Solution sol;

    int n;

    cout << "Find Duplicate and Missing Number " << endl;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter " << n << " elements (Numbers should be between 1 and " << n << "):" << endl;

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> result = sol.findErrorNums(nums);

    cout << "\nResult:" << endl;
    cout<<result[0]<<","<<result[1]<<endl;
    
    return 0;
}
