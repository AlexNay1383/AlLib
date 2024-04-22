//DO NOT USE OR INCLUDE THIS FILE

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

    static inline num_t strlen(const char* const str)
    {
        num_t len = 0;
        for(; str[len] != '\0'; len++);
        return len;
    }

    static inline void strcpy(char* const dest, const char* const src)
    {
        num_t slen = strlen(src);

        for(int i = 0; i <= slen; i++)
            dest[i] = src[i];
    }

    inline void Clear()
    {
        std::cout << "Funct Cls\n";
        if(m_buffer != nullptr)
        {
            delete[] m_buffer;
            m_buffer = nullptr;
        }
        m_size = 0;
        m_buffer_size = 0;
    }


public:

    //Constructors and Deconstructors

    String()
    : m_buffer(nullptr), m_size(0), m_buffer_size(0)
    {
        std::cout << "Cnstr Emp\n";
    }

    String(const String& str)
    : m_buffer(nullptr), m_size(str.m_size), m_buffer_size(str.m_buffer_size)
    {
        std::cout << "Cnstr Str\n";
        if(str.m_buffer == nullptr)
            return;
        
        m_buffer = new char[m_buffer_size];
        strcpy(m_buffer, str.m_buffer);
    }

    String(const char* const str)
    : m_buffer(nullptr), m_size(0), m_buffer_size(0)
    {
        std::cout << "Cnstr Chr\n";
        if(str == nullptr)
            return;
        
        m_size = strlen(str);
        m_buffer_size = m_size + 1;
        m_buffer = new char[m_buffer_size];
        strcpy(m_buffer, str);
    }

    String(const std::string& str)
    : m_buffer(nullptr), m_size(str.size()), m_buffer_size(str.size() + 1)
    {
        std::cout << "Cnstr Std\n";
        if(m_size == 0)
            return;
        
        m_buffer = new char[m_buffer_size];
        strcpy(m_buffer, str.c_str());
    }

    ~String()
    {
        std::cout << "Destr\n";
        if(m_buffer != nullptr)
            delete[] m_buffer;
    }

    //Methods
    inline num_t size() const
    {
        return m_size;
    }

    inline num_t length() const
    {
        return strlen(m_buffer);
    }

    inline num_t buffer_size() const
    {
        return m_buffer_size;
    }

    inline char& at(const num_t index)
    {
        return m_buffer[index < m_size ? index : m_size - 1]; 
    }

    inline const char& at(const num_t index) const
    {
        return m_buffer[index < m_size ? index : m_size - 1]; 
    }

    inline char& front()
    {
        return *m_buffer;
    }

    inline const char& front() const
    {
        return *m_buffer;
    }

    inline char& back()
    {
        return m_buffer[m_size - 1];
    }

    inline const char& back() const
    {
        return m_buffer[m_size - 1];
    }

    inline char* c_str()
    {
        return m_buffer;
    }

    inline const char* c_str() const
    {
        return m_buffer;
    }

    //Operators

    char& operator[] (const num_t index)
    {
        return m_buffer[index < m_size ? index : m_size - 1];
    }

    const char& operator[] (const num_t index) const
    {
        return m_buffer[index < m_size ? index : m_size - 1];
    }

    String& operator= (const String& other)
    {
        std::cout << "Oprtr Str\n";
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

    String& operator= (const char* const other)
    {
        std::cout << "Oprtr Chr\n";
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

    String& operator= (const std::string& other)
    {
        std::cout << "Oprtr Std\n";
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

    bool operator== (const String& other) const
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

    bool operator!= (const String& other) const
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

    String operator+ (const String& other) const
    {
        std::cout << "Oprtr Pls\n";
        String result;
        result.m_buffer_size = m_buffer_size + other.m_buffer_size - 1;
        result.m_size = m_size + other.m_size;
        result.m_buffer = new char[result.m_buffer_size];
        
        strcpy(result.m_buffer, m_buffer);
        strcpy(result.m_buffer + m_size, other.m_buffer);
        
        return result;
    }

    String& operator+= (const String& other)
    {
        *this = *this + other;
        return *this;
    }

    friend std::ostream& operator<< (std::ostream& stream, const String& str)
    {
        stream << str.m_buffer;
        return stream;
    }

    friend std::istream& operator>> (std::istream& stream, String& str)
    {
        std::string temp;
        stream >> temp;
        str = temp;
        return stream;
    }

};


int main()
{
    String a, b = "Hello";
    const String c = b;
    a = "Char";
    a = b;
    a += b;

    std::cout << a;

    return 0;
}