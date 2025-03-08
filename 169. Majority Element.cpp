#include <iostream>
#include <unordered_map> 
#include <vector>
#include <cmath>

using namespace std;

int majorityElement(vector<int>& nums){
    const int l = nums.size();
    unordered_map<int, int> m;
    const int am = floor(l / 2);
    for (const auto& elem : nums){
        //cout << elem << endl;
        auto it = m.find(elem);
        if (it != m.end()){
            //cout << "Key did exist" << endl;
            m[elem] ++;
        }else{
            //cout << "Key didnt exist" << endl;
            m[elem] = 1;
        }
    }
    //cout << "This is the arithmetic mean = " << am << endl;
    for (const auto& pair : m){
        const auto key = pair.first;
        //cout << "Key in the map = " << key << endl; 
        if (m[key] > am){
            return key;
        }
    }
    return 0;
}

int main(){
    vector<int> v = {3,2,3};
    cout<< majorityElement(v) << endl;
    return 1;
}