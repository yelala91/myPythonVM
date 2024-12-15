// string.hpp

/*
    A string class for mpvm.

    created on 2024/12/4 by yezq.
*/


#ifndef _STRING_HPP
#define _STRING_HPP

#include "object.hpp"
#include <string>

namespace mpvm{

    class StringKlass : public Klass {
    private:
        StringKlass() : Klass("str") { }
        static StringKlass* _instance;
        

    public:
        static StringKlass* get_instance();
        void _display(std::ostream&, Object*) const override;
        virtual Object* _equal      (Object* x, Object* y) const override;
        virtual Object* _not_equal  (Object* x, Object* y) const override;
    };

    extern StringKlass* STRING_KLASS;

    class String : public Object {
    private:
        // char* _value;
        std::string _value;
        int   _length;
        bool  _ascii;

    public:
        String(const char* x, bool ascii);
        String(const char* x, const int length, bool ascii);

        /* move */
        String(String&& other) noexcept : _value(std::move(other._value)) {
            // other._value = nullptr; 
            _length = other.length();
            _ascii = other._ascii;
            set_klass(STRING_KLASS);
        }

        String& operator=(String&& other) noexcept {
            // if (this != &other) {
            //     delete[] _value; 
            //     _value = other._value; 
            //     other._value = nullptr;
            // }
            _value = std::move(other._value);
            _length = other.length();
            _ascii = other._ascii;
            set_klass(STRING_KLASS);
            return *this;
        }

        inline std::string value() const     {return _value;}
        inline int length() const            {return _length;}

        friend class StringKlass;

    };




}


#endif