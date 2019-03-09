//
//  MyString.cpp
//  Lab11
//
//  Created by Charlie Menke on 2/18/19.
//  Copyright © 2019 Charlie Menke. All rights reserved.
//

#include "MyString.hpp"
#include <iostream>

MyString::MyString() {
    string = new char[1];
    string[0] = '\0';
}

MyString& MyString::operator+=(const MyString& s) {
    int len = strlen(string) + strlen(s.string);
    char* newstring = new char[len + 1];
    int index = 0;
    int index2 = 0;
    while(string[index] != '\0') {
        newstring[index] = string[index];
        index++;
    }
    while(s.string[index2] != '\0') {
        newstring[index] = s.string[index2];
        index2++;
        index++;
    }
    delete [] string;
    string = new char[len + 1];
    index = 0;
    while(newstring[index] != '\0') {
        string[index] = newstring[index];
        index++;
    }
    delete [] newstring;
    string[index] = '\0';
    return *this;
}

char MyString::operator[](size_t i) const {
    if(i > this->length() || i < 0) {
        return '\0';
    }
    char toReturn = '\0';
    for(int index = 0; index < i + 1; index++) {
        toReturn = string[index];
    }
    return toReturn;
}

char& MyString::operator[](size_t i) {
    if(i > this->length() || i < 0) {
        return string[this->length()];
    }
    return string[i];
}

MyString::MyString(const MyString& s) {
    std::cout << "Copy constructor called." << std::endl;
    string = new char[strlen(s.string)+1];
    for(int i=0; i < s.length(); i++)
    {
        string[i] = s.string[i];
    }
    string[s.length()] = '\0';
}

MyString::MyString(const char* stringToCopy) {
    std::cout << "char* stringToCopy called\n";
    string = new char[strlen(stringToCopy) + 1];
    
    /* Copying the destination data to source data
     */
    int  index = 0;
    while (stringToCopy[index] != '\0')
    {
        string[index] = stringToCopy[index];
        index++;
    }
    
    /* Making the rest of the characters null ('\0')
     */
    string[index] = '\0';
}

MyString::~MyString() {
    delete [] string;
    string = nullptr;
}

MyString& MyString::operator=(const MyString& objToCopy) {
    std::cout << "Assignment = op called." << std::endl;
    
    if (this != &objToCopy) {           // 1. Don't self-assign
        delete [] string;                  // 2. Delete old dataObj
        string = new char[objToCopy.length() + 1];              // 3. Allocate new dataObj
        int index = 0;
        while(objToCopy.string[index] != '\0') {
            string[index] = objToCopy.string[index];
            index++;
        }
        string[index] = '\0';
    }
    
    return *this;
}

size_t MyString::length() const {
    return strlen(string);
}

const char* MyString::cString() const {
    return this->string;
}


