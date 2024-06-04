# Push Swap - Mastering Sorting Algorithms

Welcome to the Push Swap project, a fundamental algorithm challenge that dives into the world of sorting. In this highly straightforward assignment, your mission is clear: sort a set of integer values using two stacks and a set of manipulation instructions. Your goal is to develop a C program named `push_swap` that calculates and outputs the smallest program, composed of Push Swap language instructions, capable of sorting the given integers.

## Getting Started

### Prerequisites

- Familiarity with C programming.
- A code editor of your choice.

### Usage

1. Clone the repository:

    ```bash
    git clone https://github.com/tiziaco/push_swap.git
    ```

2. Navigate to the project directory:

    ```bash
    cd push_swap
    ```

3. Compile and run your `push_swap` program with the provided integer values.

    ```bash
    make
    ./push_swap 4 2 7 1 3
    ```

### Test

    ARG=($(seq -1000 1000 | shuf -n 100)); ./push_swap $ARG | ./checker_linux $ARG


---
