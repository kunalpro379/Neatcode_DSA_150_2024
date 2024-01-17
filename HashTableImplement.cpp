#include<iostream>
#include<string>
#include<list>
#include<vector>
using namespace std;

class HashTable{
    private:
     static const int tabsize=10;
     vector<list<pair<int, string>>>tab;



     public:
     HashTable(): tab(tabsize){}
     int hashFn(int key){return key% tabsize;}
//insert key_value pair in the hashtable
     void insert(int key,string value){
        int index=hashFn(key);
        tab[index].push_back(make_pair(key,value));
     }

     string search(int key){int index=hashFn(key);
     for(const auto& entry: tab[index]){
        if(entry.first==key)
            return entry.second;
     }
     return "KeyNotFound";
     
     }
     void remove(int key){
        int index=hashFn(key);
        auto& bucket=tab[index];
        for(auto it =bucket.begin();it!=bucket.end();it++){if(it->first==key){bucket.erase(it);break;}}

     }
};


int main() {
    HashTable myHashTable;

    myHashTable.insert(1, "John");
    myHashTable.insert(2, "Doe");
    myHashTable.insert(11, "Alice");

    std::cout << "Value for key 1: " << myHashTable.search(1) << std::endl;
    std::cout << "Value for key 2: " << myHashTable.search(2) << std::endl;
    std::cout << "Value for key 11: " << myHashTable.search(11) << std::endl;

    myHashTable.remove(2);
    std::cout << "Value for key 2 after removal: " << myHashTable.search(2) << std::endl;

    return 0;
}