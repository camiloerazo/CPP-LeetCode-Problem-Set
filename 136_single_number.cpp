#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums){ //Solution could use xor operator in all the array elments but this worked, just not O(1) memory
    const int l = nums.size();
    unordered_map<int, int> map;

    for (int i = 0; i < l; i++){
        if (map.find(nums[i]) == map.end()){
            map[nums[i]] = 1;
        }else{
            map[nums[i]]++;
        }
    }
    for (const auto& pair : map){
        if (pair.second == 1) return pair.first;
    }
    return 0;
}

int main(int argc, char const *argv[]){
    vector<int> nums = {6,2,4,1,1,6,4};
    cout << singleNumber(nums) << endl;
    return 0;
}
