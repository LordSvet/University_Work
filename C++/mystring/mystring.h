/*
 * mystring.h
 *
 */

#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
#include <cstdlib>  // to have size_t

namespace stringexercise {
    class mystring {
    public:
        // constructors
    	mystring();
        mystring(const char str[ ]);
        mystring( const std::string str );
        mystring(const mystring& source);
        virtual ~mystring( );

        // modifying member functions
        mystring& operator+=(const mystring& addend);
        mystring& operator+=(const char addend[ ]);
        mystring& operator+=(const char addend);

        mystring& operator=(const mystring& source);
        const char& operator[ ](size_t position) const;	 // char at a distinct position
        char& operator[ ](size_t position);				 // char at a distinct position


        // constant member functions which do not change the state of the object
        std::size_t length( ) const { return occupied; } // return number of characters
        const char* c_str() const { return sequence; }	 // return text as a C-string
        void swap(mystring&);							 // exchange of two strings
        bool is_empty(){ return (occupied == 0); }		 // check if empty

        // friends
        friend std::ostream& operator <<(std::ostream& outs, const mystring& source);

        friend bool operator==(const mystring& s1, const mystring& s2);
        friend bool operator!=(const mystring& s1, const mystring& s2);
        friend bool operator>=(const mystring& s1, const mystring& s2);
        friend bool operator<=(const mystring& s1, const mystring& s2);
        friend bool operator> (const mystring& s1, const mystring& s2);
        friend bool operator< (const mystring& s1, const mystring& s2);
    private:
        size_t occupied; // current number of characters
        size_t capacity; //	maximum number of characters
        char *sequence;	 // pointer to the beginning of the string array
    };

    // Prototype declarations of NON-MEMBER functions
    // to be used in context with class mystring
    mystring operator+(const mystring& s1, const mystring& s2);
    mystring operator+(const mystring& s1, const char* s2 );
    mystring operator+(const char* s1, const mystring& s2);

    bool operator==(const mystring& s1, const mystring& s2);
    bool operator!=(const mystring& s1, const mystring& s2);
    bool operator>=(const mystring& s1, const mystring& s2);
    bool operator<=(const mystring& s1, const mystring& s2);
    bool operator> (const mystring& s1, const mystring& s2);
    bool operator< (const mystring& s1, const mystring& s2);

    std::ostream& operator<<(std::ostream& outs, const mystring& source);
    std::istream& operator>>(std::istream& ins, mystring& target);

} /* end namespace stringexercise */

#endif




