// tuple_object.hpp

/*
    The class Tuple for mpvm.

    created on 2024/12/4 by yezq.
*/

#ifndef _TUPLE_OBJECT_HPP
#define _TUPLE_OBJECT_HPP

#include "object.hpp"
#include <vector>

namespace mpvm{
    class Tuple : public Object {

    private:
        std::vector<Object*> _list;
        std::ostream& _display(std::ostream&) const override;

    public:
        Tuple() {}
        void add(Object* obj) {
            _list.emplace_back(obj);
        }
        Object* get(int index) const {
            return _list[index];
        }

        
        int size() const {
            return _list.size();
        }

        Object* operator[](int) const;
    };
}

#endif