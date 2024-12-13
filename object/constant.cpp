

#include "bool_object.hpp"
#include "ellipsis_object.hpp"

// static mpvm::BoolObject* mpvm::TRUE_OBJECT = mpvm::BoolObject::get_true_instance();
// static mpvm::BoolObject* mpvm::FALSE_OBJECT = mpvm::BoolObject::get_false_instance();

// static mpvm::Ellipsis* mpvm::ELLIPSIS_OBJECT = mpvm::Ellipsis::get_instance(); 

mpvm::BoolObject* mpvm::BoolObject::_true_instance = nullptr;
mpvm::BoolObject* mpvm::BoolObject::_false_instance = nullptr;

mpvm::Ellipsis* mpvm::Ellipsis::_instance = nullptr;