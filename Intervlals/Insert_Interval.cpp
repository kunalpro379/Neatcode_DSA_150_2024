//Insert_Interval.cpp
#include<iostream>
using namespace std;
#include<vector>
#include<stack>
/*
Input: Set : [1, 3], [6, 9]
    New Interval : [2, 5] 
Output: [1, 5], [6, 9]
*/



class Solution1 {
public:

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>answer;
        int n=intervals.size();
        intervals.push();
        



    }
};

class Solution2 { //using stacks 
public:

void mergeInterval(pair<int,int>Pair[],int n, pair<int,int>newPair){
//stack of pair type
stack<pair<int,int>>St;
St.push(Pair[0]);
//top elemnt
pair<int,int>top=St.top();
if(newPair.first<top.second){//cheak if pair is intersecting with old pair


St.pop();

top.first=min(top.first,newPair.first);
top.first=max(top.second,newPair.second);

St.push(top);

}

else{



}
// iterate i from 1 to n-1
for(int i=1;i<n;i++){

pair<int,int>top=St.top();
//cheak if pair is intersecting with old pair
if(newPair.first<top.second){
St.pop();
top.first=min(top.first,newPair.first);
top.first=max(top.second,newPair.second);
St.push(top);
}
else{
St.push(Pair[i]);

}

}
///final interval
stack<pair<int,int>>finalInterval;
while(!St.empty()){
    pair<int,int>element=St.top();
    St.pop();
    finalInterval.push(element);
}
while(!finalInterval.empty()){
pair<int,int>element=finalInterval.top();
finalInterval.pop();
cout<<element.first<<"||"<<element.second<<endl;
}


}
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        



    }
};