#ifndef PERSON_BUILDER_HPP
#define PERSON_BUILDER_HPP

#include "person.hpp"

class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilderBase
{
protected:
    Person& person_;

    explicit PersonBuilderBase(Person& p)
        : person_{p}
    {
    }

public:
    operator Person()
    {
        return std::move(person_);
    }

    PersonAddressBuilder lives() const;
    PersonJobBuilder works() const;
};

class PersonAddressBuilder : public PersonBuilderBase
{
    using self = PersonAddressBuilder;

public:
    explicit PersonAddressBuilder(Person& p)
        : PersonBuilderBase{p}
    {
    }

    self& at(std::string street_address)
    {
        person_.address_ = std::move(street_address);
        return *this;
    }

    self& in(std::string city)
    {
        person_.city_ = std::move(city);
        return *this;
    }

    self& with_postal_code(std::string postal_code)
    {
        person_.postal_code_ = std::move(postal_code);
        return *this;
    }
};

class PersonJobBuilder : public PersonBuilderBase
{
    using self = PersonJobBuilder;

public:
    explicit PersonJobBuilder(Person& p)
        : PersonBuilderBase{p}
    {
    }

    self& in_company(std::string company_name)
    {
        person_.company_name_ = std::move(company_name);
        return *this;
    }

    self& with_tax_id(std::string tax_id)
    {
        person_.tax_id_ = std::move(tax_id);
        return *this;
    }
};

class PersonBuilder : public PersonBuilderBase
{
    using self = PersonBuilder;

    Person p_;

public:
    PersonBuilder(std::string first_name, std::string last_name)
        : PersonBuilderBase{p_}
    {
        p_.first_name_ = std::move(first_name);
        p_.last_name_ = std::move(last_name);
    }
};

#endif