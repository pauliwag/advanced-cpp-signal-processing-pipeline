#ifndef PROCESSINGUNITFACTORY_H
#define PROCESSINGUNITFACTORY_H

#include "IProcessingUnit.h"
#include "ProcessingUnitConcept.h"
#include <memory>
#include <utility>

/**
 * Factory function for creating instances of processing units that adhere to the ProcessingUnit concept.
 *
 * @param args Arguments to be forwarded to the constructor of the processing unit type.
 * @return A shared pointer to the instantiated processing unit.
 */
template <typename PUType, typename... Args>
    requires ProcessingUnit<PUType>
std::shared_ptr<IProcessingUnit> createProcessingUnit(Args &&...args)
{
    return std::make_shared<PUType>(std::forward<Args>(args)...);
}

#endif // PROCESSINGUNITFACTORY_H
