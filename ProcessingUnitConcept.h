#ifndef PROCESSINGUNITCONCEPT_H
#define PROCESSINGUNITCONCEPT_H

#include <concepts>
#include <any>

/**
 * Concept defining the requirements for a class to be considered a processing unit.
 * A valid processing unit must implement input and output methods conforming to specific signatures.
 */
template <typename T>
concept ProcessingUnit = requires(T t, const std::any &input) {
    {
        t.input(input)
    } -> std::same_as<void>;
    {
        t.output()
    } -> std::convertible_to<std::any>;
};

#endif // PROCESSINGUNITCONCEPT_H
