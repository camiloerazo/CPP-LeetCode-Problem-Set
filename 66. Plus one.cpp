#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    //Cases: 1. [1,2,5,7] the last digit just adds 1
    //       2. [8,8,9,9] the last digit increments the second
    //       3. [9,8,9] the last digit increments all
    const int l = digits.size();
    //Checks if the last digit + 1 is < 10
    if (digits[l - 1] < 9){
        digits[l -1] ++;
        return digits;
    }
    else{
        vector<int> arr(l + 1);
        const int fd = digits[0];
        //int c = 0;
        //if the first digit isnt 9, meaning i dont have to create anything, just change
        if (1){
            int i = l - 1;
            int j = i + 1;
            while(i >= 0 && digits[i] > 8){
                digits[i] = 0;
                arr[i + 1] = 0;
                i--;
            }
            if(fd == 9 && i == -1){
                arr[0] = 1;
                return arr;
            }
            digits[i]++;
            return digits;
        }
    }
}
template <typename any>
void printVector(vector<any> v){
    for (const auto& elem : v){
    cout << elem << endl;
    }
}

int main(){
    vector<int> v = {9};
    printVector(plusOne(v));
    return 1;
}