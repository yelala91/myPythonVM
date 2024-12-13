// object.hpp

/*
    Object is the father class of all class in this vm.

    created on 2024/12/4 by yezq.
*/

#ifndef _OBJECT_HPP
#define _OBJECT_HPP

#include <ostream>

namespace mpvm{

    class Object{
    
    private:
        virtual std::ostream& _display(std::ostream&) const = 0;

    public:
        friend std::ostream& operator<<(std::ostream&, const Object&);
    };

    std::ostream& operator<<(std::ostream&, const Object&);

}

#endif