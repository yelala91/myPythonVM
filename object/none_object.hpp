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
        std::ostream& _display(std::ostream&) const override;
    public:
        NoneObject() {}
    };

    static NoneObject* NONE_OBJECT = new NoneObject();
}

#endif