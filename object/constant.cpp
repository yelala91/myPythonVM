

#include "bool_object.hpp"
#include "ellipsis_object.hpp"
#include "none_object.hpp"
#include "tuple_object.hpp"
#include "integer.hpp"
#include "none_object.hpp"
#include "code_object.hpp"
#include "function_object.hpp"

/* Klass instance*/

mpvm::BoolKlass* mpvm::BOOL_KLASS           = mpvm::BoolKlass::get_instance();

mpvm::CodeKlass* mpvm::CODE_KLASS           = mpvm::CodeKlass::get_instance();

mpvm::EllipsisKlass* mpvm::ELLIPSIS_KLASS   = mpvm::EllipsisKlass::get_instance();

mpvm::IntegerKlass* mpvm::INTEGER_KLASS     = mpvm::IntegerKlass::get_instance();

mpvm::NoneKlass* mpvm::NONE_KLASS           = mpvm::NoneKlass::get_instance();

mpvm::StringKlass* mpvm::STRING_KLASS       = mpvm::StringKlass::get_instance();

mpvm::TupleKlass* mpvm::TUPLE_KLASS         = mpvm::TupleKlass::get_instance();

mpvm::FunctionKlass* mpvm::FUNCTION_KLASS   = mpvm::FunctionKlass::get_instance();

/* Object instance*/

mpvm::BoolObject* mpvm::TRUE_OBJECT = mpvm::BoolObject::get_true_instance();
mpvm::BoolObject* mpvm::FALSE_OBJECT = mpvm::BoolObject::get_false_instance();

mpvm::Ellipsis* mpvm::ELLIPSIS_OBJECT = mpvm::Ellipsis::get_instance(); 

mpvm::NoneObject* mpvm::NONE_OBJECT = mpvm::NoneObject::get_instance();


