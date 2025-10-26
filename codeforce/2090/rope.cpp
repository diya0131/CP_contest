#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;

int main() {
    rope<char> r;

    // Append
    r += "hello";

    // Insert at position 2
    r.insert(2, "XX"); // heXXllo

    // Erase 3 characters from index 1
    r.erase(1, 3);     // hllo

    // Substring from index 1, length 2
    rope<char> sub = r.substr(1, 2);  // "ll"

    // Access element at index 2
    char ch = r[2]; // 'l'

    cout << "Final rope content: " << r << endl;
    cout << "Substring: " << sub << endl;
    cout << "Character at index 2: " << ch << endl;

    return 0;
}