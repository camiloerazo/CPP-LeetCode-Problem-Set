#include <iostream>
#include <vector>
#include <typeinfo>
#include <cmath>

using namespace std;

int hammingWeight(int n) {
    int c = 0;
    while(n > 0){
        //cout << "Entering loop with n = " << n << endl;
        if (n % 2 == 1){
            c++;
            n = n >> 1;
        }else{
            n = n >> 1;
        }
    }
    return c;
}

int main(){
    cout << hammingWeight(358) << endl;
    return 1;
}