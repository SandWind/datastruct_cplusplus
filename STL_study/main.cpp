//
//  main.cpp
//  STL_study
//
//  Created by Ding Peng on 2021/3/4.
//

#include <iostream>
#include "linklist.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    listlist<int> list;
    for (int i=0; i<=10; i++) {
        list.invert(i);
    }
    list.invert(999912);
    list.search(999912);
    list.deleteNode(5);
    return 0;
}
