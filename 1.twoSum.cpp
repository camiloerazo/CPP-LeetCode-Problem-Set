#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void pm(unordered_map<int, int> m){
    for (const auto& elem : m) cout << elem.first << endl;
}

vector<int> twoSum(vector<int>& nums, int target){
    const int l = nums.size();
    unordered_map<int, int> m;
    m[abs(nums[0] - target)] = 0;
    for (int i = 1; i < l; i++){
        cout << "Entered the loop with element = " << nums[i] << endl;
        //Aproach using absolute value
        //First step: check if the nums[i] is not on the map
        auto it = m.find(abs(nums[i]));
        if (it != m.end()){ //The key exist
            //cout << "They key exist " << endl;
            const auto key = it -> first;
            //cout << "This is the key = " << key << endl;
            const auto value = it -> second;
            if (nums[i] + nums[value] == target){
                return {value, i};
            }else{
                m[abs(nums[i] - target)] = i;
            }
        }else{ //The key does not exist
            m[abs(nums[i] - target)] = i;
            cout << "Added " << abs(nums[i] - target) << " to the map" << endl;
        }
    }
    //pm(m);
    return {};
}

int main(){
    vector<int> v = {-11,7,3,2,1,7,-10,11,21,3}; // [2, 3, 5, 6, 8, 10]
    vector<int> r = twoSum(v, 11);
    for (const auto& elem : r) cout << elem << endl;
    return 0;
}