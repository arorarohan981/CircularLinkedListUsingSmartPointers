//
//  main.cpp
//  CircularLinkedListUsingSmartPointers
//
//  Created by Rohan Arora on 03/11/21.
//

#include <iostream>
#include "CircularLinkedListUsingSmartPointers.h"

int main(int argc, const char * argv[]) {
    mylib::List<int> myList;
    myList.append(1);
    myList.append(2);
    myList.append(3);
    myList.append(4);
    myList.append(5);
    myList.print();
//    myList.clear();
    myList.removeAt(2);
    myList.print();
    return 0;
}
