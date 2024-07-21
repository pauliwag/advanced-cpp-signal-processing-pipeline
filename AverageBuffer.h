#ifndef AVERAGEBUFFER_H
#define AVERAGEBUFFER_H

#include "IProcessingUnit.h"
#include <vector>
#include <numeric>
#include <any>
#include <stdexcept>

/**
 * A processing unit that computes the average of an integer vector and replicates
 * the average three times into a float vector as output.
 */
class AverageBuffer : public IProcessingUnit
{
    std::vector<float> outputData;

public:
    /**
     * Takes an std::any containing a vector of integers, computes the average, and stores
     * a vector of floats (the average value repeated three times) as output.
     *
     * @param inputData The input data expected to be a vector of integers.
     * @throws std::invalid_argument if inputData is not a vector of integers.
     */
    void input(const std::any &inputData) override
    {
        if (inputData.type() != typeid(std::vector<int>))
        {
            throw std::invalid_argument("AverageBuffer expects std::vector<int>");
        }
        auto data = std::any_cast<std::vector<int>>(inputData);
        float avg = std::accumulate(data.begin(), data.end(), 0.0f) / data.size();
        outputData = std::vector<float>(3, avg);
    }

    /**
     * Returns the computed output data.
     *
     * @return std::any containing a vector of floats (the computed average repeated three times).
     */
    std::any output() override
    {
        return outputData;
    }
};

#endif // AVERAGEBUFFER_H
