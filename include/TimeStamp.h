#ifndef TIMESTAMP_H
#define TIMESTAMP_H

#include <string>

class Timestamp
{
public:
    Timestamp() = default;
    Timestamp(const std::string& time);

    std::string toString() const;

    bool operator<(const Timestamp&) const;

private:

    std::string date;
    std::string value;
    std::string time;
};


#endif