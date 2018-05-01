#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(const string str){
    int i = 0;
    int len = str.length();
    for( i; i < len/2; i++){
        if( str[i] != str[len - 1 - i] ){
            return false;
        }
    }
    return true;
}

int main(int argc, const char *argv[]){
    string s1 = string(argv[1]);
    string s2 = string(argv[2]);
    
    int len = s1.length();
    int count = 0;
    string tmp;
    for( int i = 0; i <= len; i++ ){
        tmp = s1;
        tmp.insert(i, s2);
#ifdef DEBUG
        cout << tmp << endl;
#endif
        if( is_palindrome(tmp) ){
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
