//dynamic programming
//top down approach---> usign recurrssion
//  memoriazation

//bottom up approach--->use fof recurssion
//   tabulation

// Ex 1 :-  word break

/*
Consider the following dictionary 
{ i, like, sam, sung, samsung, mobile, ice, 
  cream, icecream, man, go, mango}
Input:  ilike
Output: Yes 
The string can be segmented as "i like".

*/

#include<algorithm>
#include<iostream>
#include<string>
#include<vector>

using namespace std;
bool WordBreak(vector<string>&wordList, const string &word)
{
    if(word.empty())
    return true;

    int wordlen=word.length();

    for(int i=1;i<wordlen;i++){
        string prefix=word.substr(0,i);
        if(find(wordList.begin(), wordList.end(),prefix)!=wordList.end()&&WordBreak(wordList, word.substr(i))){
            return true;
        }

    }
return false;

}

int main(){
vector<int>myself={23,2,2,1,1,2,3,3,3,3,2,2,2,5};

vector<string>wordList={"taa", "tarara","ratara","tataaaa"};
bool result =WordBreak(wordList, "taatarararatara");
cout<<result<<endl;

}


