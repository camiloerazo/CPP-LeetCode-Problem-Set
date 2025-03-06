#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool f(string s){
    stack<char> st;
    for (int i = 0; i < s.length(); i++){
        cout << "Im the the loop with s = " << s[i] << endl;
        if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
            //cout << "Entered the fisrt if and pushed " << s[i] << endl;
            st.push(s[i]);
        }
        else{
            cout << "right parenthesis detected" << endl;
            char clp = st.top();
            //cout << "the top element at this moment is = " << clp << endl;
            bool band = false;
            switch (s[i]){
                case '}':
                    if (clp == '{') {
                        st.pop();
                        band = true;
                    }
                    break;
                case ']':
                    if (clp == '[') {
                        st.pop();
                        band = true;
                    }
                    break;
                case ')':
                    if (clp == '('){
                        st.pop();
                        band = true;
                    }
                    break;
            }
            if (!band) return false;
        }
    }
    if (st.empty()) return true;
}


int maini(int argc, char const *argv[]){
    stack<char> st;
    string s =  "([{}[()]])"; //| {[]([)]} el primero que cierrre que se encuentre, ese tiene que ser de su tipo
    s = "{[]([)]}";
    s = "]";
    for (int i = 0; i < s.length(); i++){
        //cout << "Im the the loop with s = " << s[i] << endl;
        if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
            //cout << "Entered the fisrt if and pushed " << s[i] << endl;
            st.push(s[i]);
        }
        else{
            //cout << "right parenthesis detected" << endl;
            char clp = st.top();
            //cout << "the top element at this moment is = " << clp << endl;
            bool band = false;
            switch (s[i]){
                case '}':
                    if (clp == '{') {
                        st.pop();
                        band = true;
                    }
                    break;
                case ']':
                    if (clp == '[') {
                        st.pop();
                        band = true;
                    }
                    break;
                case ')':
                    if (clp == '('){
                        st.pop();
                        band = true;
                    }
                    break;
            }
            if (!band) cout << "this string is false" << endl;;
        }
    }
    if (st.empty()) cout << "this string is true" << endl;
    return 0;
}

int main(){
    cout << f("]") << endl;
    return 0;
}