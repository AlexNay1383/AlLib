#pragma once

#include <iostream>
#include <string>

class String
{
public:
    typedef long long num_t;

private:
    //Data

    char* m_buffer;
    num_t m_size;
    num_t m_buffer_size;

    //Basic functions to make code cleaner

    static inline num_t strlen(const char* const);

    static inline void strcpy(char* const, const char* const);

    inline void Clear();


public:

    //Constructors and Deconstructors

    String();

    String(const String&);

    String(const char* const);

    String(const std::string&);

    ~String();

    //Methods
    inline num_t size() const;

    inline num_t length() const;

    inline num_t buffer_size() const;

    inline char& at(const num_t);

    inline const char& at(const num_t) const;

    inline char& front();

    inline const char& front() const;

    inline char& back();

    inline const char& back() const;

    inline const char* c_str() const;

    //Operators

    char& operator[] (const num_t);

    const char& operator[] (const num_t) const;

    String& operator= (const String&);

    String& operator= (const char* const);

    String& operator= (const std::string&);

    bool operator== (const String&) const;

    bool operator!= (const String&) const;

    String operator+ (const String&) const;

    String& operator+= (const String&);

    friend std::ostream& operator<< (std::ostream&, const String&);

    friend std::istream& operator>> (std::istream&, String&);

};