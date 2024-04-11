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

    // emptuy constructor
    string s6;

    // copy constructor
    string s7(s1);

    // substring constructor
    string s8(s1, 0, 5);

    // c string
    char cstr[] = "Hello World!";

    // c string constructor
    string s9(cstr);

    // copies constructor
    string s10(5, 'H');

    string s11 = "Hello World!";

    // no error
    // cout << s11[1000] << endl;

    // error, out of range 
    // cout << s11.at(1000) << endl;

    cout << s11.front() << " " << s11.back() << endl;

    
    const char * cstr2 = s11.c_str();
    
    
    return 0;
}