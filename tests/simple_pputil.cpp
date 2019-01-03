#include <iostream>

#include "pputil.hpp"
#include "simple_pputil.hpp"

namespace ut = pputil;

StreamOp::StreamOp(){};
StreamOp::StreamOp(std::string s) : mystring(std::move(s)){};

StreamOp::~StreamOp(){};

void StreamOp::setMyString(std::string mystring)
{
    this->mystring = std::move(mystring);
}

std::string StreamOp::getMyString() const { return this->mystring; }

int main(ATTR_UNUSED int argc, ATTR_UNUSED char *argv[])
{
    // concatenate some simple strings
    std::string cons = ut::stringify("Foo", "Bar", "Baz");
    // prints FooBarBaz
    std::cout << cons << std::endl;

    // concatenate with objects implementing stream operator
    StreamOp so("OperatorToString");
    std::cout << cons + " AND " + ut::op_to_string(so) << std::endl;

    // create toml usable strings
    std::cout << ut::toml_stringify("GENERAL", "FOO", "BAR", "BAZ") << std::endl;
    return 0;
}
