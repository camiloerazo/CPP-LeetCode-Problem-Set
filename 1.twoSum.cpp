#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target){
    const int l = nums.size();
    unordered_map<int, int> m;
    for (int i = 0; i < l; i++){
        cout << "Entered the loop with element = " << nums[i] << endl;
        
    }
    for (const auto& pair : m){
        cout << pair.first << endl;
    }
    return {};
}

int main(){
    vector<int> v = {8,2,3,6,10,5}; // [2, 3, 5, 6, 8, 10]
    twoSum(v, 7);
    return 0;
}