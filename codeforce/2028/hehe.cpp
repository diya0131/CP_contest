#include <iostream>
#include <fstream>
#include <locale>
using namespace std;

// Assuming Solve is defined somewhere
void Solve(int testCase) {
    // Your solution code here
    cout << "Test Case #" << testCase << endl;
}

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");
    if (freopen("in.txt", "r", stdin) == nullptr) {
        cerr << "Failed to open in.txt" << endl;
        return 1;
    }
    if (freopen("out.txt", "w", stdout) == nullptr) {
        cerr << "Failed to open out.txt" << endl;
        return 1;
    }
    cout<<"helasdfasflo\n";
    int t = 1;
    cin >> t;
    cout<<t<<endl;
    for (int i = 1; i <= t; i++) {
        Solve(i);
    }

    // Close the files to ensure output is flushed
    fclose(stdin);
    fclose(stdout);

    return 0;
}
