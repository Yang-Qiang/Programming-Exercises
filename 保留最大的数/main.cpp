#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

void save_max_num(string &nums, int n){
    int length = nums.size();
    int j = n;
    int i = 0;
    while( j > 0 && i < length - 1 ){
        if( nums[i] > nums[i+1] ){
            i++;
            continue;
        }

        nums.erase(i, 1);
        j--;
        if( i > 0 )
            i--;
    }

    if( j > 0 )
        nums.erase(nums.size() - j, j);
}

int main(int argc, const char *argv[]){
    string nums = string(argv[1]);
    int n = atoi(argv[2]);
    save_max_num(nums, n);
    cout << nums << endl;
    return 0;
}
