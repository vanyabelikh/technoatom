#include <iostream>
#include <cassert>
#include <fstream>

using namespace std;
#include "stack_class.h"

int main() {
    Stack s1;
    for (int i=0;i<4;i++)
        s1.push(i+50);
    cout<<s1.size()<<endl;
    for (int i=0;i<6;i++){
        cout<<s1.top()<<endl;
        s1.pop();
    }
    return 0;
}
