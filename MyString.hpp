//
//  MyString.hpp
//  Lab11
//
//  Created by Charlie Menke on 2/18/19.
//  Copyright © 2019 Charlie Menke. All rights reserved.
//

#ifndef MyString_hpp
#define MyString_hpp

#include <stdio.h>

class MyString {
public:
    MyString(); // default contr
    MyString(const MyString& s); // copy contr
    MyString(const char *);
    ~MyString(); // decontr
    MyString &operator=(const MyString& s); // member vars copy
    MyString &operator+=(const MyString& s);
    char operator[](size_t i) const;
    char &operator[](size_t i);
    size_t length() const; // len func
    const char *cString() const;
private:
    char *string;
};

#endif /* MyString_hpp */
