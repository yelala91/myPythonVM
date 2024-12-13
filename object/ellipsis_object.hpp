// ellipsis.hpp

/*
    define the boolen object.

    created on 2024/12/11 by yezq.
*/

#ifndef _ELLIPSIS_OBJECT_HPP
#define _ELLIPSIS_OBJECT_HPP

#include "object.hpp"
// #include <string>

namespace mpvm{

    class Ellipsis : public Object {
    
    private:
        static Ellipsis* _instance;

        std::ostream& _display(std::ostream&) const override;

    public:
        static Ellipsis* get_instance() {
            if (_instance) {
                return _instance;
            } else {
                _instance = new Ellipsis();
                return _instance;
            }
        }
        
    };

    static Ellipsis* ELLIPSIS_OBJECT = Ellipsis::get_instance();

    
}

#endif 