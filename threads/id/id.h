#pragma once
#ifndef ID_H_
#define ID_H_

#include <chrono>
#include <iostream>

using namespace std;


class UniqueIdGenerator {};
class NumericalIdGenerator: public UniqueIdGenerator {
public:
    virtual int64_t generate() = 0;
};

class StringIdGenerator: public UniqueIdGenerator {
public:
    virtual string generate() = 0;
};

/**
 * Snowflake Format
 * - 64 Bit ID
 * - 41 Bits for timestamp
 * - 10 Bits for Host ID
 * - 13 Bits for Sequence   
 */
class SnowflakeIdGenerator: public UniqueIdGenerator {

};


#endif