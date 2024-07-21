#include "SPP.h"
#include "ProcessingUnitFactory.h"
#include "AverageBuffer.h"
#include "TrailingIncrements.h"
#include "ToInt.h"
#include <iostream>

/**
 * Main function demonstrating the setup and execution of a Signal Processing Pipeline (SPP).
 * This program tests the SPP with a series of valid and invalid inputs to ensure it processes data as expected and handles errors appropriately.
 */
int main()
{
    // Setup processing units via factory
    std::vector<std::shared_ptr<IProcessingUnit>> units = {
        createProcessingUnit<AverageBuffer>(),
        createProcessingUnit<TrailingIncrements>(),
        createProcessingUnit<ToInt>(),
    };

    // Create the signal processing pipeline
    SPP pipeline(units);

    // Test inputs based on a given execution table
    std::vector<std::vector<int>> testInputs = {
        {1, 2, 3, 4, 5},
        {0, 0, 0, 0, 0},
        {3, 3, 4, 4, 5},
        {2, 2, 8, 8, 5},
    };

    for (const auto &input : testInputs)
    {
        try
        {
            // Execute the pipeline step with the current input
            auto result = pipeline.execute_step(input);
            std::cout << "Pipeline executed with input: ";
            for (auto i : input)
                std::cout << i << ' ';
            std::cout << "=> Execution result: " << std::any_cast<int>(result) << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        std::cout << "-----------------------------------" << std::endl;
    }

    // Demonstrate error handling with incorrect data type
    std::vector<float> invalidInputData = {1.0f, 2.0f, 3.0f};
    try
    {
        pipeline.execute_step(invalidInputData); // This should throw due to type mismatch
    }
    catch (const std::exception &e)
    {
        std::cerr << "Handled error scenario: " << e.what() << std::endl;
    }

    return 0;
}
