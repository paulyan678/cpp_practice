#include <iostream>
#include <string>
using namespace std;
int main() {
    // Your code here
    string empty_string;
    string s1 {"Hello World!"};
    string copy_s1(s1);
    string copies(10, 'P');
    string substring(s1, 0, 5);

    cout << empty_string << endl;
    cout << s1 << endl;
    cout << copy_s1 << endl;
    cout << copies << endl;
    cout << substring << endl;
    
    
    return 0;
}
