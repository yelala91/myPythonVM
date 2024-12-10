// array_list.hpp

/*
    The List like it in Python.

    created on 2024/12/4 by yezq.
*/

#ifndef _ARRAY_LIST_HPP
#define _ARRAY_LIST_HPP

namespace mpvm{

    template <typename T>
    class ArrayList{

    private:
        int _length;
        T* _array;
        int _size;

        void expand();

    public:
        ArrayList(int n = 8);

        void add(const T& t);
        void insert(int index, const T& t);
        T    get(int index) const;
        void set(int index, const T& t);
        int  size() const;
        int  length() const;
        T    pop();

    };

}

#endif