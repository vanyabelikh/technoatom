//--------------------------------------
//!@file stack_class.h
//!@brief Implements a stack class
//!@author vanyabelikh, 2017
//--------------------------------------

#include <cassert>
#include <math.h>
#include <fstream>

using namespace std;

//--------------------------------------
//@def A macro to check if stack isn't damaged by other functions
//--------------------------------------

#define ASSERT_OK()\
if (!ok())\
{\
dump();\
assert(!"object is ok");\
}\

//--------------------------------------
//@class Stack
//@brief A Stack class
/*!
 * A Stack class created by vanyabelikh for Technoatom courses
 */
//--------------------------------------
class Stack{
public:
    typedef float value_type;///< of the value stored in the stack
    
    //--------------------------------------
    //!Shows the top value of the stack
    //!@return top value (NaN if stack is empty)
    //--------------------------------------
    value_type top();
    
    //--------------------------------------
    //!Shows if stack is empty
    //!@return bool-type result of an operation (true of false)
    //--------------------------------------
    bool empty();
    
    //--------------------------------------
    //!Shows cut the top value of the stack
    //!@return bool-type result of an operation (true of false)
    //--------------------------------------
    bool pop();
    
    //--------------------------------------
    //!Pushes the value to the stack
    //!@param value to be pushed
    //!@return void-type (nothing)
    //--------------------------------------
    void push(value_type value_to_push);
    
    //--------------------------------------
    //!Returns the size of the stack
    //!@return the size of the stack
    //--------------------------------------
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







































