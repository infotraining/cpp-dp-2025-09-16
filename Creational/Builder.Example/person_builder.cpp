#include "person_builder.hpp"

PersonAddressBuilder PersonBuilderBase::lives() const
{
    return PersonAddressBuilder{person_};
}

PersonJobBuilder PersonBuilderBase::works() const
{
    return PersonJobBuilder{person_};
}