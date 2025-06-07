#pragma once
#include <string>

struct PostalRecord {
    int index;
    std::string region;
    std::string district;
    std::string city;
    std::string postOffice;
    PostalRecord* next;
};
