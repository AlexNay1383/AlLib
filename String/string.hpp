#pragma once

#include <iostream>
#include <string>

class String
{
public:
    typedef unsigned long long num_t;

private:
    ///Data

    char* m_buffer;
    num_t m_size;
    num_t m_capacity;

    //Basic functions to make code cleaner

    static inline num_t strlen(const char* const);

    static inline void strcpy(char* const, const char* const);

    inline void Clear();


public:

    ///Constructors and Deconstructors

    String();

    String(const String&);

    String(const char* const);

    String(const std::string&);

    ~String();

    ///Methods
    
    //Size methods

    inline num_t size() const;
    inline num_t length() const;

    inline num_t capacity() const;

    //Char methods

    inline char& at(const num_t);
    inline const char& at(const num_t) const;

    inline char& front();
    inline const char& front() const;

    inline char& back();
    inline const char& back() const;

    //Methods with str pointers

    //Returns a pointer to a null-terminated string. DO NOT MODIFY, or bad things might happen
    inline const char* c_str() const;
    
    inline const char* begin() const;
    inline const char* end() const;

    ///Operators

    //Char

    char& operator[] (const num_t);
    const char& operator[] (const num_t) const;

    //Assignment

    String& operator= (const String&);

    String& operator= (const char* const);

    String& operator= (const std::string&);

    //Comparison

    bool operator== (const String&) const;
    bool operator!= (const String&) const;

    //Concatination

    String operator+ (const String&) const;
    String& operator+= (const String&);

    //Input Output

    friend std::ostream& operator<< (std::ostream&, const String&);

    friend std::istream& operator>> (std::istream&, String&);

};