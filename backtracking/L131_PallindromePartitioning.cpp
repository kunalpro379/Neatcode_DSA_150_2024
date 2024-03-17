#include<iostream>
#include<vector>
using namespace std;
#include <unordered_map>
class Solution{

public:
    bool isPalindrome( string &s, int start, int end){
        while(start<end){
            if(s[start]!=s[end]){return false;}
            start++;
            end--;
        }
        return true;
    }
    void BackTrack(string &s,
        int start,
        vector<string >&current, 
        vector<vector<string >>&result, 
        unordered_map<int, vector<vector<string>>>&momos){
                    if(start==s.length()){
                        result.push_back(current);
                        return ;
                    }

                    for(int end=start;end<s.length();end++){
                        if(isPalindrome(s,start,end)){//if substr is pallindrome add it to the cureent pos
                            current.push_back(s.substr(start,end-start+1));//continure for remainging strings 
                            BackTrack(s,end+1,current,result,momos);//backtrack 
                            current.pop_back();
                        }
                    }
                    momos[start]=result;

    }

    vector<vector<string>> partition(string s) {
    vector<vector<string>>result;
    vector<string>current;
    unordered_map<int, vector<vector<string>>>momos;
    BackTrack(s,0,current, result,momos);
    return result;
    }
};

int main() {
    Solution solution;
    std::string input = "aab";
    std::vector<std::vector<std::string>> result = solution.partition(input);

    for (const auto& partition : result) {
        std::cout << "[";
        for (const auto& str : partition) {
            std::cout << "\"" << str << "\", ";
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}