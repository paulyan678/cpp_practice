#include <string>
#include <iostream>
using namespace std;

int main() {
    string s1 {"Hello World!"};
    s1.at(0) = 'f';
    string s2 = s1;
    string s3 (3, 'H');
    string s4 = s1 + s2 + s3;
    cout << s1 << " " << s2 << " " << s3 << " " << s4 << endl;
    
    string s5 {s1, 0, 5};
    cout << s5 << endl;
    
    for (char c : s4) {
        cout << c << endl;
    }
    

    for (auto c : s4) {
        cout << c << endl;
    }
    
    return 0;
}