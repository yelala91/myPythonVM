

#include "bool_object.hpp"
#include "ellipsis_object.hpp"
#include "none_object.hpp"

mpvm::BoolObject* mpvm::BoolObject::_true_instance = nullptr;
mpvm::BoolObject* mpvm::BoolObject::_false_instance = nullptr;

mpvm::Ellipsis* mpvm::Ellipsis::_instance = nullptr;
mpvm::NoneObject* mpvm::NoneObject::_instance = nullptr;

mpvm::BoolObject* mpvm::TRUE_OBJECT = mpvm::BoolObject::get_true_instance();
mpvm::BoolObject* mpvm::FALSE_OBJECT = mpvm::BoolObject::get_false_instance();

mpvm::Ellipsis* mpvm::ELLIPSIS_OBJECT = mpvm::Ellipsis::get_instance(); 



mpvm::NoneObject* mpvm::NONE_OBJECT = mpvm::NoneObject::get_instance();