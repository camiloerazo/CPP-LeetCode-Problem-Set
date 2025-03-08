#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

bool isAnagram(string s, string t){
    unordered_map<char, int> m;
    const int sl = s.length();
    const int tl = t.length();
    if (sl != tl) return false;
    for (int i = 0; i < sl; i ++){
        const char c = s[i];
        auto it = m.find(c);
        if (it != m.end()){
            m[c] ++;
        }else{
            m[c] = 1;
        }
    }
    for (int i = 0; i < tl; i++){
        char c = t[i];
        auto it = m.find(c);
        if (it != m.end()){
            m[c] --;
        }else{
            return false;
        }
    }
    for (const auto& elem : m){
        const int v = elem.second;
        if (v != 0) return false;
    }
    return true;
}

int main(int argc, char const *argv[]){

    return 0;
}
