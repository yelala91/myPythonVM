// none_object.hpp

/*
    define the none object.

    created on 2024/12/13 by yezq.
*/

#ifndef _NONE_OBJECT_HPP
#define _NONE_OBJECT_HPP

#include "object.hpp"

namespace mpvm{
    class NoneObject : public Object {

    private:
        static NoneObject* _instance;
        std::ostream& _display(std::ostream&) const override;
    public:
        NoneObject() {}
        static NoneObject* get_instance() {
            if (_instance) {
                return _instance;
            } else {
                _instance = new NoneObject();
                return _instance;
            }
        }
    };

    extern NoneObject* NONE_OBJECT;
}

#endif