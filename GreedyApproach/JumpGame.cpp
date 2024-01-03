#include<iostream>
#include<vector>
using namespace std;

class Solution1 {
public:
    bool canJump1(std::vector<int>& nums) {
        int n = nums.size();
        int reachable = 0;
        for (int i = 0; i < n ; i++) {
            if (i > reachable) {
                return false;
            }
            reachable = max(reachable, i + nums[i]);
        }
        return true;
    }
};

 /// DP solution
 class Solution2{
    public: 
         bool canJump2(std::vector<int>& nums){
                vector<bool>dp(nums.size(),false);
                dp[0]=false;
                int n=nums.size();
                int i;
               while(i<n&&!dp[n-1]){}



         }

 };

// if we having src and dest in array
 class Solution3{
    public:
    int minJump3(vector<int>nums, int src,int dest){
        //base case when source and dest same
            if(src=dest){return 0; }
            if(nums[src]=0){return -1;}
        int min=-1;

        for(int i=src+1;i<= &&  ;i++){
            int jumps=minJumps(nums,i,dest);

        }

    }
 };

 class Solution4{};

 class Solution5{};

int main() {
    Solution1 s1;
    Solution2 s2;
        Solution1 s3;
    Solution2 s4;
        Solution1 s5;

   vector<int> v = {2999, 3999, 100099, 1999, 49999, 99999, 9999};
    cout <<"SOLUTION 1 ::::"<< s1.canJump1(v) << endl;
        cout <<"SOLUTION 2 ::::"<< s2.canJump2(v) << endl;
 cout <<"SOLUTION 3 ::::"<< s3.canJump3(v) << endl;
        cout <<"SOLUTION 4 ::::"<< s4.canJump4(v) << endl;
         cout <<"SOLUTION 5 ::::"<< s5.canJump5(v) << endl;

    return 0;
}
