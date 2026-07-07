#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sp=prices[0];
        int profit =0 , maxProfit=0;
        for(int k=1; k<prices.size(); k++){
            profit=prices[k]-sp;
            maxProfit = max(maxProfit ,profit);
            sp = min(sp , prices[k]);
        }      
        return maxProfit;
    }
};

int main(){
    Solution s;
    vector<int> prices = {7,1,5,3,6,4};
    cout<<s.maxProfit(prices);
    cout<<endl;
    return  0;
}