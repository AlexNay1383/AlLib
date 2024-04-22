#include "string.hpp"

//Basic functions to make code cleaner

inline String::num_t String::strlen(const char* const str)
{
    num_t len = 0;
    for(; str[len] != '\0'; len++);
    return len;
}

inline void String::strcpy(char* const dest, const char* const src)
{
    num_t slen = strlen(src);

    for(int i = 0; i <= slen; i++)
        dest[i] = src[i];
}

inline void String::Clear()
{
    if(m_buffer != nullptr)
    {
        delete[] m_buffer;
        m_buffer = nullptr;
    }
    m_size = 0;
    m_buffer_size = 0;
}

//Constructors and Deconstructors

String::String()
: m_buffer(nullptr), m_size(0), m_buffer_size(0)
{

}

String::String(const String& str)
: m_buffer(nullptr), m_size(str.m_size), m_buffer_size(str.m_buffer_size)
{
    if(str.m_buffer == nullptr)
        return;
    
    m_buffer = new char[m_buffer_size];
    strcpy(m_buffer, str.m_buffer);
}

String::String(const char* const str)
: m_buffer(nullptr), m_size(0), m_buffer_size(0)
{
    if(str == nullptr)
        return;
    
    m_size = strlen(str);
    m_buffer_size = m_size + 1;
    m_buffer = new char[m_buffer_size];
    strcpy(m_buffer, str);
}

String::String(const std::string& str)
: m_buffer(nullptr), m_size(str.size()), m_buffer_size(str.size() + 1)
{
    if(m_size == 0)
        return;
    
    m_buffer = new char[m_buffer_size];
    strcpy(m_buffer, str.c_str());
}

String::~String()
{
    if(m_buffer != nullptr)
        delete[] m_buffer;
}

//Methods
inline String::num_t String::size() const
{
    return m_size;
}

inline String::num_t String::length() const
{
    return strlen(m_buffer);
}

inline String::num_t String::buffer_size() const
{
    return m_buffer_size;
}

inline char& String::at(const String::num_t index)
{
    return m_buffer[index < m_size ? index : m_size - 1]; 
}

inline const char& String::at(const String::num_t index) const
{
    return m_buffer[index < m_size ? index : m_size - 1]; 
}

inline char& String::front()
{
    return *m_buffer;
}

inline const char& String::front() const
{
    return *m_buffer;
}

inline char& String::back()
{
    return m_buffer[m_size - 1];
}

inline const char& String::back() const
{
    return m_buffer[m_size - 1];
}

inline const char* String::c_str() const
{
    return m_buffer;
}

//Operators

char& String::operator[] (const String::num_t index)
{
    return m_buffer[index < m_size ? index : m_size - 1];
}

const char& String::operator[] (const String::num_t index) const
{
    return m_buffer[index < m_size ? index : m_size - 1];
}

String& String::operator= (const String& other)
{
    if(this == &other)
        return *this;
    
    if(other.m_buffer == nullptr)
    {
        m_buffer = nullptr;
        m_buffer_size = 0;
        m_size = 0;
        return *this;
    }
    
    if(m_buffer_size < other.m_size)
    {
        Clear();
        m_buffer_size = other.m_buffer_size;
        m_size = m_buffer_size - 1;
        m_buffer = new char[m_buffer_size];
        strcpy(m_buffer, other.m_buffer);
    }
    else
    {
        m_size = other.m_size;
        strcpy(m_buffer, other.m_buffer);
    }

    return *this;
}

String& String::operator= (const char* const other)
{
    if(other == nullptr)
    {
        m_buffer = nullptr;
        m_buffer_size = 0;
        m_size = 0;
        return *this;
    }

    num_t olen = strlen(other);
    if(m_buffer_size < olen)
    {
        Clear();
        m_buffer_size = olen;
        m_size = m_buffer_size - 1;
        m_buffer = new char[m_buffer_size];
        strcpy(m_buffer, other);
    }
    else
    {
        m_size = olen;
        strcpy(m_buffer, other);
    }
    

    return *this;
}

String& String::operator= (const std::string& other)
{
    if(m_buffer_size < other.size() + 1)
    {
        Clear();
        m_size = other.size();
        m_buffer_size = m_size + 1;
        m_buffer = new char[m_buffer_size];
        strcpy(m_buffer, other.c_str());
    }
    else
    {
        m_size = other.size();
        strcpy(m_buffer, other.c_str());
    }

    return *this;
}

bool String::operator== (const String& other) const
{
    if(m_buffer == nullptr && other.m_buffer == nullptr)
        return true;
    
    if(m_size != other.m_size)
        return false;
    
    for(int i = 0; i < m_size; i++)
    {
        if(m_buffer[i] != other.m_buffer[i])
            return false;
    }

    return true;
}

bool String::operator!= (const String& other) const
{
    if(m_buffer == nullptr && other.m_buffer == nullptr)
        return false;
    
    if(m_size != other.m_size)
        return true;
    
    for(int i = 0; i <= m_size; i++)
    {
        if(m_buffer[i] != other.m_buffer[i])
            return true;
    }

    return false;
}

String String::operator+ (const String& other) const
{
    String result;
    result.m_buffer_size = m_buffer_size + other.m_buffer_size - 1;
    result.m_size = m_size + other.m_size;
    result.m_buffer = new char[result.m_buffer_size];
    
    strcpy(result.m_buffer, m_buffer);
    strcpy(result.m_buffer + m_size, other.m_buffer);
    
    return result;
}

String& String::operator+= (const String& other)
{
    *this = *this + other;
    return *this;
}

std::ostream& operator<< (std::ostream& stream, const String& str)
{
    stream << str.m_buffer;
    return stream;
}

std::istream& operator>> (std::istream& stream, String& str)
{
    std::string temp;
    stream >> temp;
    str = temp;
    return stream;
}