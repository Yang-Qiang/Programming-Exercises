#include <iostream>
#include <cstdlib>

using namespace std;

int main( int argc, const char *argv[] ){
    int n = atoi(argv[1]);
    int count = 0;
    while( n >=5 ){
        count++;
        n=n/5;
    }

    cout << count << endl;
    return 0;
}
