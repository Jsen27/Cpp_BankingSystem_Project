#include "String.h"

String::String():len(0) { str = NULL; }
String::String(const char* s)
{
    len = strlen(s) + 1;
    str = new char[len];
    strcpy(str, s);
}
String::String(const String& ref)
{
    len = ref.len;
    str = new char[len];
    strcpy(str, ref.str);
}
String& String::operator=(const String& ref)
{
    if (str != NULL)
        delete[]str;
    len = ref.len;
    str = new char[len];
    strcpy(str, ref.str);
    return *this;
}
String String::operator+(const String& ref)
{
    char* tempstr = new char[len + ref.len - 1];
    strcpy(tempstr, str);
    strcat(tempstr, ref.str);

    String temp(tempstr);
    delete[]tempstr;
    return temp;
}
String& String::operator+=(const String& ref)
{
    len += ref.len - 1;
    char* temp = new char[len];
    strcpy(temp, str);
    strcat(temp, ref.str);

    if (str != NULL)
        delete[]str;
    str = temp;
    return *this;
}
bool String::operator==(const String& ref)
{
    if (strcmp(str, ref.str) == 0)
        return true;
    else
        return false;
}
String::~String()
{
    if (str != NULL)
        delete[]str;
}
ostream& operator<<(ostream& os, const String& ref)
{
    os << ref.str;
    return os;
}
istream& operator>>(istream& is, String& ref)
{
    char temp[100];
    is >> temp;
    ref = String(temp);
    return is;
}