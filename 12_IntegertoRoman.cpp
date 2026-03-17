#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int , string>un;

        un[1] ="I" ,un[2] ="II" ,un[3] ="III" ,un[4] ="IV",
        un[5]="V",un[6]="VI",un[7] ="VII",un[8] ="VIII",un[9] ="IX";

        un[10] ="X",un[20] ="XX",un[30] ="XXX",un[40] ="XL",un[50] ="L",
        un[60] ="LX",un[70] ="LXX",un[80] ="LXXX",un[90] ="XC";

        un[100] ="C",un[200] ="CC",un[300] ="CCC",un[400] ="CD",
        un[500] ="D", un[600] ="DC",un[700] ="DCC",un[800] ="DCCC";

        un[900] ="CM",un[1000] ="M",un[2000] ="MM",
        un[3000]="MMM";          

    
        //int n = num.size();
        int m=1;
        vector<string>ans;

       
        while(num>0){
            int mul=0;
            int mod = num %10;
            mul = m * mod;

            if(un.find(mul) != un.end()){
                ans.push_back(un[mul]);
            }

            num /= 10;
            m *= 10;
        }

        reverse(ans.begin(),ans.end());

        
        string result = "";
        for(string& s : ans) result +=s;

        return result; 
        
    }
};

int main(){
    Solution s;
    int num=1994;
    cout<<s.intToRoman(num)<<endl;
    return 0;
}