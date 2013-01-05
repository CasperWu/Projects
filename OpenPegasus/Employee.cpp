/*NOCHKSRC*/
//==============================================================================
//
// PLEASE DO NOT EDIT; THIS FILE WAS AUTOMATICALLY GENERATED BY GENCLASS 2.0.24
//
//==============================================================================

#include <cimple/Meta_Class.h>
#include <cimple/Meta_Property.h>
#include <cimple/Meta_Reference.h>
#include "Employee.h"

CIMPLE_NAMESPACE_BEGIN

using namespace cimple;

extern const Meta_Repository __meta_repository_9923165039371FA697660D85C9253530;

/*[1568]*/
extern const Meta_Property
_Employee_Id;

/*[1591]*/
const Meta_Property
_Employee_Id =
{
    CIMPLE_ATOMIC_INITIALIZER, /* refs */
    CIMPLE_FLAG_PROPERTY|CIMPLE_FLAG_KEY|CIMPLE_FLAG_READ,
    "Id",
    0, /* meta_qualifiers */
    0, /* num_meta_qaulifiers */
    UINT32,
    0, /* subscript */
    CIMPLE_OFF(Employee,Id),
    0, /* value */
};

/*[1568]*/
extern const Meta_Property
_Employee_First;

/*[1591]*/
const Meta_Property
_Employee_First =
{
    CIMPLE_ATOMIC_INITIALIZER, /* refs */
    CIMPLE_FLAG_PROPERTY|CIMPLE_FLAG_READ,
    "First",
    0, /* meta_qualifiers */
    0, /* num_meta_qaulifiers */
    STRING,
    0, /* subscript */
    CIMPLE_OFF(Employee,First),
    0, /* value */
};

/*[1568]*/
extern const Meta_Property
_Employee_Last;

/*[1591]*/
const Meta_Property
_Employee_Last =
{
    CIMPLE_ATOMIC_INITIALIZER, /* refs */
    CIMPLE_FLAG_PROPERTY|CIMPLE_FLAG_READ,
    "Last",
    0, /* meta_qualifiers */
    0, /* num_meta_qaulifiers */
    STRING,
    0, /* subscript */
    CIMPLE_OFF(Employee,Last),
    0, /* value */
};

/*[1568]*/
extern const Meta_Property
_Employee_Gender;

/*[1591]*/
const Meta_Property
_Employee_Gender =
{
    CIMPLE_ATOMIC_INITIALIZER, /* refs */
    CIMPLE_FLAG_PROPERTY|CIMPLE_FLAG_READ,
    "Gender",
    0, /* meta_qualifiers */
    0, /* num_meta_qaulifiers */
    UINT32,
    0, /* subscript */
    CIMPLE_OFF(Employee,Gender),
    0, /* value */
};

/*[1568]*/
extern const Meta_Property
_Employee_Active;

/*[540]*/
static const Meta_Value_Scalar<boolean>
_Employee_Active_MV =
{
    true
};

/*[1591]*/
const Meta_Property
_Employee_Active =
{
    CIMPLE_ATOMIC_INITIALIZER, /* refs */
    CIMPLE_FLAG_PROPERTY|CIMPLE_FLAG_READ,
    "Active",
    0, /* meta_qualifiers */
    0, /* num_meta_qaulifiers */
    BOOLEAN,
    0, /* subscript */
    CIMPLE_OFF(Employee,Active),
    (const Meta_Value*)(void*)&_Employee_Active_MV,
};

/*[1568]*/
extern const Meta_Property
_Employee_OutOfOffice;

/*[540]*/
static const Meta_Value_Scalar<boolean>
_Employee_OutOfOffice_MV =
{
    false
};

/*[1591]*/
const Meta_Property
_Employee_OutOfOffice =
{
    CIMPLE_ATOMIC_INITIALIZER, /* refs */
    CIMPLE_FLAG_PROPERTY|CIMPLE_FLAG_READ,
    "OutOfOffice",
    0, /* meta_qualifiers */
    0, /* num_meta_qaulifiers */
    BOOLEAN,
    0, /* subscript */
    CIMPLE_OFF(Employee,OutOfOffice),
    (const Meta_Value*)(void*)&_Employee_OutOfOffice_MV,
};

/*[2291]*/
static Meta_Feature* _Employee_MFA[] =
{
    (Meta_Feature*)(void*)&_Employee_Id,
    (Meta_Feature*)(void*)&_Employee_First,
    (Meta_Feature*)(void*)&_Employee_Last,
    (Meta_Feature*)(void*)&_Employee_Gender,
    (Meta_Feature*)(void*)&_Employee_Active,
    (Meta_Feature*)(void*)&_Employee_OutOfOffice,
};

/*[2338]*/
static const Meta_Feature_Local _locals[] =
{
    {1},
    {1},
    {1},
    {1},
    {1},
    {1},
};

/*[2358]*/
const Meta_Class Employee::static_meta_class =
{
    CIMPLE_ATOMIC_INITIALIZER, /* refs */
    CIMPLE_FLAG_CLASS,
    "Employee",
    0, /* meta_qualifiers */
    0, /* num_meta_qaulifiers */
    _Employee_MFA,
    CIMPLE_ARRAY_SIZE(_Employee_MFA),
    sizeof(Employee),
    _locals,
    0, /* super_class */ 
    1, /* num_keys */
    &__meta_repository_9923165039371FA697660D85C9253530,
};

CIMPLE_NAMESPACE_END

