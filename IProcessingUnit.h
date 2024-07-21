#ifndef IPROCESSINGUNIT_H
#define IPROCESSINGUNIT_H

#include <any>

/**
 * Interface defining a generic processing unit for a signal processing pipeline.
 * Implementations must provide methods for receiving input and producing output.
 */
class IProcessingUnit
{
public:
    /**
     * Processes the given input data.
     *
     * @param inputData The input data to process.
     */
    virtual void input(const std::any &inputData) = 0;

    /**
     * Returns the result of the processing.
     *
     * @return The processed output data.
     */
    virtual std::any output() = 0;

    virtual ~IProcessingUnit() {}
};

#endif // IPROCESSINGUNIT_H
