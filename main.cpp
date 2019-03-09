#include <iostream>
#include "MyString.hpp"

MyString operator+(const MyString &s1, const MyString &s2) {
    MyString ns;
    ns += s1;
    ns += s2;
    return ns;
}

std::ostream& operator<<(std::ostream& os, const MyString& s) {
    std::cout << s.cString();
    return os;
}


int main(int argc, const char * argv[])
{
    std::cout << "On the Stack!\n";
    MyString s;
    std::cout << "Empty: '" << s << "'\n";
    s = "hello";
    std::cout << "After operator=: '" << s << "'\n";
    {
        MyString t(s);
        std::cout << "After copy: '" << t << "'\n";
        s = t;
    }
    MyString m(" world");
    std::cout << "After constructor: '" << m << "'\n";
    m = s;
    std::cout << "After operator=: '" << m << "'\n";
    m = m;
    std::cout << "After operator=: '" << m << "'\n";
    
    s += ",";
    s += m;
    std::cout << "After operator +=: " << s << "\n";
    s += ",goodbye";
    std::cout << "After operator +=: " << s << "\n";
    
    MyString abc("abc");
    std::cout<<abc.cString();
    abc += abc;
    std::cout << "After operator += to self: " << abc << "\n";
    
    MyString sum = MyString("2+2") + "=5?";
    std::cout << "After operator +: " << sum << "\n";
    
    sum[4] = '4';
    sum[5] = '!';
    std::cout << "After operator []:" << sum << "\n";
    
    const MyString u("A const string.");
    std::cout << "Using const []: ";
    for (size_t i = 0; i < u.length(); ++i) {
        std::cout << u[i];
    }
    
    
    std::cout << "\n\n\nNow on the heap!\n";
    
    MyString* s2 = new MyString();
    std::cout << "Empty2: '" << *s2 << "'\n";
    *s2 = "hello2";
    std::cout << "After operator2=: '" << *s2 << "'\n";
    {
        MyString* t2 = new MyString(*s2);
        std::cout << "After copy2: '" << *t2 << "'\n";
        s2 = t2;
    }
    
    MyString* m2 = new MyString(" world");
    std::cout << "After constructor: '" << *m2 << "'\n";
    m2 = s2;
    std::cout << "After operator=: '" << *m2 << "'\n";
    m2 = m2;
    std::cout << "After operator=: '" << *m2 << "'\n";
    
    *s2 += ",";
    *s2 += *m2;
    std::cout << "After operator +=: " << *s2 << "\n";
    *s2 += ",goodbye";
    std::cout << "After operator +=: " << *s2 << "\n";
    
    MyString* abc2 = new MyString("abc");
    std::cout << abc2->cString();
    *abc2 += *abc2;
    std::cout << "After operator += to self: " << *abc2 << "\n";
    
    return 0;
}
