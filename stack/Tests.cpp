//--------------------------------------
//!@file StackTest.cpp
//!@brief Contains tests for Stack class
//!@author vanyabelikh, 2017
//--------------------------------------

#include <iostream>
using namespace std;
#include "stack_class.h"

#define TEST(what,case) printf("\nObject: " #what "    test: "#case"\n")

#define ASSERT_EQ(p,eq)\
if(!p){\
assert(!"Object passed the "#eq" test");\
}\
else{\
cout<<"Object passed the "#eq " test\n";\
}

int main() {
    
    TEST(Stack,TopFromEmptyStack);
    {
        Stack s;
        ASSERT_EQ(isnan(s.top()),TopFromEmptyStack);
    }

    TEST(Stack,CannotPopMore);
    {
        Stack s;
        for (int i=0; i<s.capacity(); i++)
            s.push(23);
        while (!isnan(s.top())){
            s.pop();
        }
        ASSERT_EQ(isnan(s.pop()),CannotPopMore);
    }

}
