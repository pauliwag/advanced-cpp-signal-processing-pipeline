#ifndef TRAILINGINCREMENTS_H
#define TRAILINGINCREMENTS_H

#include "IProcessingUnit.h"
#include <vector>
#include <limits>
#include <any>

/**
 * A processing unit that tracks and outputs the maximum value encountered over all inputs provided
 * since its instantiation. Designed for a sequence of float arrays, this unit continually updates
 * its state to reflect the highest value seen.
 */
class TrailingIncrements : public IProcessingUnit
{
    float maxValue = std::numeric_limits<float>::lowest();

public:
    /**
     * Processes a vector of floats, updating the maximum value seen so far.
     * This method maintains state across multiple invocations, reflecting the maximum input value.
     *
     * @param inputData The input data expected to be a vector of floats.
     * @throws std::bad_any_cast if inputData does not contain a vector of floats.
     */
    void input(const std::any &inputData) override
    {
        auto data = std::any_cast<std::vector<float>>(inputData);
        for (auto &val : data)
        {
            maxValue = std::max(maxValue, val);
        }
    }

    /**
     * Outputs the highest value encountered in all previous inputs.
     * This method allows the unit to act as a stateful observer of input values.
     *
     * @return std::any containing the maximum float value seen.
     */
    std::any output() override
    {
        return maxValue;
    }
};

#endif // TRAILINGINCREMENTS_H
