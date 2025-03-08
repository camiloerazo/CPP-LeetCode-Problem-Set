#include <iostream>
#include <vector>
#include <random>
#include <unordered_map>
#include <ctime>

using namespace std;

template <typename any>
void printVector(vector<any> v){
    for (const auto& elem : v){
        cout << elem << endl;
    }
}

class Solution{
    public:
        vector<int> oa;
        vector<int> aa;
        mt19937 gen;  // Define the generator once

        Solution(vector<int>& nums): gen(static_cast<unsigned>(time(nullptr))) {
            oa = nums;
            aa = nums;
        }
        
        vector<int> reset(){
            return oa;
        }
        
        vector<int> shuffle(){
            vector<int> a = oa;
            vector<int> b;
            unordered_map<int, int> m;
            const int l = a.size();
            //cout << "this is l= " << l << endl;
            uniform_int_distribution<int> dist(0, l - 1); // Range [1, 100]
            int i = 0;
            int j;
            while(i < l){
                //cout << "Inside the while with i = " << i << endl;
                j = dist(gen);
                //cout << "the random number is =" << j << endl;
                auto it = m.find(j);
                if (it == m.end()){
                    //cout << "the random number wasnt find in the map" << endl;
                    m[j] = 1;  // Mark as used
                    b.push_back(a[j]);
                    //cout << "pushed back =" << a[j] << endl;
                    i++;
                }
            }
            return b;
        }
};

int main(){
    vector<int> v = {1,2,3,4,5};
    Solution*  s = new Solution(v);
    printVector(s->shuffle());
    return 1;
}
