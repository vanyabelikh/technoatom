//
//  Header.h
//  stack
//
//  Created by Иван Белых on 27.02.17.
//  Copyright © 2017 Иван Белых. All rights reserved.
//

#ifndef Header_h
#define Header_h


#endif /* Header_h */


#include <cassert>
#include <math.h>
#include <fstream>

using namespace std;

#define ASSERT_OK()\
if (!ok())\
{\
dump();\
assert(!"object is ok");\
}\

class Stack{
public:
    typedef float value_type;
    
    value_type top();
    
    bool empty();
    
    bool pop();
    
    void push(value_type value_to_push);
    
    size_t size();
    
    
    Stack();
    ~Stack(){ }
    
private:
    
    static const size_t capacity_=4;
    
    value_type data_[capacity_];
    size_t size_;
    
    bool ok();
    void dump();

};


Stack::Stack(){
    size_=0;
}

size_t Stack::size(){
    ASSERT_OK();
    return size_;
}

bool Stack::empty(){
    ASSERT_OK();
    if(size_)
        return false;
    return true;
}

bool Stack::pop(){
    ASSERT_OK();
    if(!empty()){
        size_--;
        return true;
    }
    return false;
}

Stack::value_type Stack::top(){
    ASSERT_OK();
    if(!empty())
        return data_[size_-1];
    return __nan();
}

void Stack::push(value_type value_to_push){
    ASSERT_OK();
    data_[size_]=value_to_push;
    size_++;
    ASSERT_OK();
}

bool Stack::ok(){
    return size_<=capacity_;
}

void Stack::dump(){
    ofstream dump_file;
    dump_file.open("/Users/IvanBelykh/Desktop/Prog/stack/stack/File.txt");
    dump_file<<"size = "<<size_<<endl<<"data:"<<endl;
    for (int i=0;i<capacity_;i++) {
        dump_file<<i<<' ';
        dump_file << data_[i] << endl;
    }
    dump_file.close();
}







































