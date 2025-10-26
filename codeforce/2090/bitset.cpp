#include <iostream>
#include <bitset>
using namespace std;

int main() {
    bitset<8> bs("10101010");

    bs.set(0);        // 10101011
    bs.flip(1);       // 10101001
    bs.reset(2);      // 10100001

    cout << bs << endl;         // prints 10100001
    cout << bs.count() << endl; // prints 3
    cout << bs[0] << endl;      // prints 1
    cout << (bs.any() ? "Yes" : "No") << endl; // Yes
}
