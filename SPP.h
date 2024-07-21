#ifndef SPP_H
#define SPP_H

#include "IProcessingUnit.h"
#include <vector>
#include <memory>
#include <any>
#include <iostream>
#include <exception>

/**
 * Signal Processing Pipeline (SPP) orchestrates a sequence of Processing Units (PUs) to transform input data step-by-step.
 */
class SPP
{
    std::vector<std::shared_ptr<IProcessingUnit>> processingUnits;

public:
    /**
     * Constructs an SPP with a given sequence of processing units.
     *
     * @param units A vector of shared pointers to the processing units to be used in the pipeline.
     */
    SPP(const std::vector<std::shared_ptr<IProcessingUnit>> &units) : processingUnits(units) {}

    /**
     * Executes a processing step through the pipeline, passing the output of each unit as
     * the input to the next.
     *
     * Exception Safety:
     * - Strong exception safety is guaranteed for the first processing unit. If an exception occurs,
     *   no side effects will occur, and the pipeline remains in a valid state.
     * - Basic exception safety is guaranteed for subsequent processing units. The pipeline remains in a valid state,
     *   but partial processing may occur.
     *
     * @param input The input data for the first processing unit.
     * @return The output from the last processing unit.
     */
    std::any execute_step(const std::any &input)
    {
        std::any currentInput = input;
        std::any lastOutput;

        try
        {
            // Strong exception safety for the first PU input
            processingUnits.front()->input(currentInput);
        }
        catch (const std::exception &e)
        {
            std::cerr << "Exception in first processing unit: " << e.what() << "\n";
            throw; // Rethrow, maintaining strong exception safety with added context
        }
        catch (...)
        {
            std::cerr << "Unknown exception in first processing unit.\n";
            throw; // Rethrow for unknown exceptions
        }

        for (size_t i = 1; i < processingUnits.size(); ++i)
        {
            try
            {
                auto output = processingUnits[i - 1]->output();
                processingUnits[i]->input(output);
            }
            catch (const std::exception &e)
            {
                // Log the exception to maintain basic exception safety and continue with the next processing unit.
                // This ensures that a failure in one unit does not halt the entire pipeline.
                std::cerr << "Exception in processing unit " << i << ": " << e.what() << ". Continuing with next unit.\n";
            }
            catch (...)
            {
                // Catching non-standard exceptions
                std::cerr << "Unknown exception in processing unit " << i << ". Continuing with next unit.\n";
            }
        }

        if (!processingUnits.empty())
        {
            lastOutput = processingUnits.back()->output();
        }

        return lastOutput;
    }
};

#endif // SPP_H
