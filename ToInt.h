#ifndef TOINT_H
#define TOINT_H

#include "IProcessingUnit.h"
#include <cmath>
#include <any>

/**
 * A processing unit that converts a single float input to an integer by applying the floor function.
 * The conversion is designed to handle numerical input that represents floating-point values.
 */
class ToInt : public IProcessingUnit
{
    int outputData;

public:
    /**
     * Receives a single floating-point value encapsulated in std::any, applies the floor function,
     * and stores the result as an integer.
     *
     * @param inputData The input data expected to be a float wrapped in std::any.
     * @throws std::bad_any_cast if inputData does not contain a float.
     */
    void input(const std::any &inputData) override
    {
        auto data = std::any_cast<float>(inputData);
        outputData = static_cast<int>(std::floor(data));
    }

    /**
     * Returns the processed output data, which is the floored integer value of the input float.
     *
     * @return std::any containing the output integer.
     */
    std::any output() override
    {
        return outputData;
    }
};

#endif // TOINT_H
