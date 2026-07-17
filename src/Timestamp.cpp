#include "Timestamp.h"

Timestamp::Timestamp(const std::string& time)
{
    value = time;
}

std::string Timestamp::toString() const
{
    return value;
}

bool Timestamp::operator<(const Timestamp& other) const
{
    return value < other.value;
}
