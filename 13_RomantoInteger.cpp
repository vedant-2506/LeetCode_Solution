#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {

         unordered_map<string,int>un;
        un["I"]=1;
        un["II"]=2;
        un["III"]=3;
        un["IV"]=4;
        un["V"]=5;
        un["IX"]=9;
        un["X"]=10;
        un["XL"]=40;
        un["L"]=50;
        un["XC"]=90;
        un["C"]=100;
        un["CD"]=400;
        un["D"]=500;
        un["CM"]=900;
        un["M"]=1000;

        int n =s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='I' && s[i+1]=='V' && i+1 < n ){
               ans+= un["IV"];
               i++;
            }

            else if(s[i]=='I' && s[i+1]=='X' && i+1 < n ){
                ans+= un["IX"];
                i++;
            }

            else if(s[i]=='X' && s[i+1]=='L' && i+1 < n ){
                ans+= un["XL"];
                i++;
                
            }

            else if(s[i]=='X' && s[i+1]=='C' && i+1 < n ){
                    ans+= un["XC"];
                    i++;
            }

            else if(s[i]=='C' && s[i+1]=='D' && i+1 < n ){
               ans+= un["CD"];
               i++;
            }
            
            else if(s[i]=='C' && s[i+1]=='M' && i+1 < n ){
              
                ans+= un["CM"];
                i++;            
           }

            else{
                ans += un[string(1,s[i])];
            }
        }//end of for 

        return ans;
    }
};


int main(){
    Solution s;
    string str="MCMXCIV";
    cout<<s.romanToInt(str)<<endl;
    return 0;
}
