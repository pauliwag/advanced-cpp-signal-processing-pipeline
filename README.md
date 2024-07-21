# Signal Processing Pipeline
This Signal Processing Pipeline (SPP) applies a series of transformations to data through sequential modular Processing Units (PUs). Each PU is responsible for specific data transformations, providing an adaptable and extensible architecture suitable for various data processing tasks.

## Key Features
- **Modular Design:** The pipeline's architecture allows for easy addition and modification of PUs, supporting a wide range of data processing operations. The *factory pattern* is utilized to decouple the instantiation of PUs from their use, enhancing cohesion and scalability.
- **Exception Safety:** Implements comprehensive error handling to ensure pipeline robustness and reliability during execution, with strong exception safety for the initial PU and basic safety for subsequent units, ensuring operational continuity or safe termination in the face of processing errors.
- **Flexible Data Processing:** Each PU is designed to perform specific transformations, supporting a dynamic, polymorphic processing environment where input and output types can vary.
- **Testing:** Includes various test cases that simulate different data processing scenarios to ensure the pipeline operates as expected under various conditions.

## Key Components
- **`IProcessingUnit`:** An interface that all PUs implement, defining the essential methods for processing input and generating output, ensuring consistency across different types of PUs.
- **`ProcessingUnitConcept`:** A C++ concept that ensures all custom PUs adhere to the expected functional signatures and behaviors. This compile-time validation mechanism proactively guarantees that any newly integrated PUs are implemented correctly, enhancing system reliability and maintainability.
- **`ProcessingUnitFactory`:** A factory class that facilitates the creation of PU instances, ensuring they conform to the `ProcessingUnit` concept via template metaprogramming, promoting a scalable and maintainable codebase by verifying that all PUs meet design specifications pre-instantiation.
- **`SPP`:** Orchestrates the sequence of PUs, handling data flow and exception management across the pipeline.

## Setup and Running
### Prerequisites
You will need a C++ compiler that supports C++20 or later due to modern C++ features used in the codebase.

### Compilation
The codebase comprises header files and a single CPP file, `main`, designed for straightforward execution; e.g., `main` can be easily executed using Code Runner in VS Code with the default configuration since there is only one CPP file, although you may need to add the `-std=c++20` flag to the `cpp` command in `code-runner.executorMap` in `settings.json` for proper compilation, depending on your setup. Alternatively, you can compile the project using the command `g++ -std=c++20 main.cpp -o spp`.

### Execution
Execute the compiled application with `./spp`.

## Author
Paul Roode