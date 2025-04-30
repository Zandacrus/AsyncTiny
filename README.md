# async_tiny

A lightweight, platform-agnostic C++ library for asynchronous programming using coroutine-like state machines. Works on desktop PCs as well as embedded systems (Arduino, ESP32, etc.).

---

## Table of Contents

1. [Overview](#overview)
2. [Features](#features)
3. [Getting Started](#getting-started)
   - [Prerequisites](#prerequisites)
   - [Installation](#installation)
4. [Usage](#usage)
   - [Including the Library](#including-the-library)
   - [Defining Coroutines](#defining-coroutines)
   - [Template Coroutines](#template-coroutines)
   - [Stages and Suspension](#stages-and-suspension)
   - [Returning Values](#returning-values)
   - [Coroutine Execution Flow](#coroutine-execution-flow)
   - [Local Variables](#local-variables)
   - [Scheduling Tasks](#scheduling-tasks)
   - [Running the Event Loop](#running-the-event-loop)
5. [Examples](#examples)
6. [Contributing](#contributing)

---

## Overview

`async_tiny` provides an easy-to-use, macro-based interface for writing asynchronous flows in C++ without relying on compiler-specific coroutine support. It uses a state-machine approach under the hood, but exposes a clean, coroutine-like interface:

- **Coroutines**: Defined via `CO_DEF`/`CO_DECL`, they represent state machines you can suspend and resume.
- **CO_AWAIT, CO_NAP, CO_UNTIL, CO_SLEEP**: Macros used to suspend coroutines
- **Futures**: Represent standalone asynchronous results.
- **Tasks**: Wrap coroutines to run in the event loop. In a coroutine, awaiting a task behaves exactly like awaiting a future.
- **CO_RETURN, CO_END**: return values and terminate
- **EventLoop**: schedule and run tasks concurrently

This design works on any C++ compiler (desktop or embedded).

---

## Features

- Simple macro-based async flow
- No dynamic allocation unless you choose to
- Doesn't require C++ STL. Suitable for platforms without STL support.
- Supports awaiting coroutines, tasks, and futures
- Coroutines, tasks, and futures are resettable and reusable
- Fine-grained suspension: event-loop tick, condition, or timed sleep
- Configurable task concurrency limit
- Portable: PC, Arduino, ESP32, and more

---

## Getting Started

### Prerequisites

- A C++ compiler with C++11 or later support
- Basic understanding of event-loop and state machines (not required but helpful)

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/Zandacrus/AsyncTiny.git
   cd AsyncTiny
   ```

2. Build the project: 

   #### Option 1: Regular CMake Build (for C++ Projects)

   This builds `AsyncTiny` as a static library for use in other C++ projects.

   **For Unix-like Systems (e.g., Linux, macOS) or Ninja:**

   ```bash
   mkdir build && cd build
   cmake -S .. -B . -DCMAKE_BUILD_TYPE=Debug
   cmake --build .
   cmake --install . --prefix install
   ```

   This generates the library in `build/` and installs it to `install/`.

   **For Windows (Visual Studio):**

   ```bash
   mkdir build && cd build
   cmake -S .. -B . -G "Visual Studio 17 2022"
   cmake --build . --config Debug
   cmake --install . --prefix install --config Debug
   ```

   This builds the `Debug` configuration and installs it to `install/`. Replace `Debug` with `Release` for a release build. Change Visual Studio version as required.

3. Include the library:
   
   - To include this library append the path to `install/` directory to `CMAKE_PREFIX_PATH` while building your project.
   - Then, add the following to your project's  CMakeLists.txt:
   ```cmake
   find_package(AsyncTiny REQUIRED)
   target_link_libraries(YourProject PRIVATE AsyncTiny)
   ```

   #### Option 2: Arduino Library Zip

   This generates a zip file for use in the Arduino IDE.

   ```bash
   mkdir build && cd build
   cmake -S .. -B . -DBUILD_ARDUINO_ZIP=ON
   cmake --build . --target arduino_zip
   ```

   This creates `AsyncTiny.zip` in the `build/` directory. Import the zip into the Arduino IDE via `Sketch > Include Library > Add .ZIP Library`.

---

## Usage

### Including the Library
- ```cpp
  #include <async_tiny.hpp>
  ```

### Defining Coroutines

- **Declaration only**
  ```cpp
  CO_DECL(ReturnType, Name, ArgType, Variables)
  ```
  Use `CO_DECL` if you prefer separate declaration.
- **Definition only**
  ```cpp
  CO_DEF(ReturnType, Name, ArgType) {
    CO_BEGIN(max_stage)
    // ... your code ...
    CO_RETURN(value)
    CO_END()
  } // coroutine-body
  ```
  Use this to define coroutine-body if it is already declared using `CO_DECL`. `ReturnType` and `ArgType` must be same as declaration. Put `inline` keyword before `CO_DEF` if you intend to inline the definition.
- **Declaration & Definition**
  ```cpp
  CO_DEF(ReturnType, Name, ArgType, Variables) {
    CO_BEGIN(max_stage)
    // ... your code ...
    CO_RETURN(value)
    CO_END()
  } // coroutine-body
  ```
  Declares and defines a coroutine. The definition is `inline`.
- **Forward declaration**
  ```cpp
  class Name;
  ```

Parameters:
- `ReturnType`: Type returned by the coroutine (`void` or leave empty if none). Shouldn't be a reference type.
- `Name`: Identifier of the coroutine.
- `ArgType`: Single argument type (`void` or leave empty if none). For multiple arguments create a struct. Shouldn't be a reference type.
- `Variables`: Declare (or, initialize) local variables here (leave empty if none).
- If any macro argument consists of commas, wrap that argument in `AS_IS(...)` macro. For example, 
  ```cpp
  CO_DEF(AS_IS(TemplatedReturnType<A,B>), Name, AS_IS(TemplatedArgType<C,D>), AS_IS(
    // local variable declaration (or, initialization) here
  )) {...}
  ```

Inside the body:
- `CO_BEGIN(N)`: Initialize state machine with `N` stages.
- `CO_END()`: Finalize the coroutine state.
- If `ArgType` is non-`void` (or not empty), then the argument passed to the coroutine can be accessed using `args` variable inside the coroutine-body.
- If `Variables` is not empty, then the local variables declared in `Variables` can be accessed using `vars` variable inside the coroutine-body.

### Template Coroutines

- **Declaration only**
  ```cpp
  template <template-parameters> CO_DECL(ReturnType, Name, ArgType, Variables)
  ```
  `ReturnType`, `ArgType`, `Variables` can depend upon `template-parameters`. Wrap macro arguments in `AS_IS` macro if required.
- **Definition only**
  ```cpp
  template <template-parameters> CO_DEF(ReturnType, Name<template-parameters>, ArgType) {
    CO_BEGIN(max_stage)
    // ... your code may use template-parameters ...
    CO_RETURN(value)
    CO_END()
  } // coroutine-body
  ```
  `ReturnType` and `ArgType` must be same as declaration. Note that `Name<template-parameters>` is passed, not just `Name`. Coroutine-body may also use `template-parameters`.
- **Declaration & Definition**
  <br> Unfortunately, this is not possible for template coroutines.
- **Forward Declaration**
  ```cpp
  template <template-parameters> class Name;
  ```
  Provide default values (if any) for `template-parameters` in forward declaration, not in declaration or definition.
- **Explicit Instantiation**
  ```cpp
  template class Name<template-arguments>;
  ```
- **Partial Template Specialization (Declaration)**
  ```cpp
  template <partial-template-parameters> CO_DECL(ReturnType, Name<full-template-parameters>, ArgType, Variables)
  ```
  `ReturnType`, `ArgType`, `Variables` can depend upon `partial-template-parameters`. Note that `Name<full-template-parameters>` is passed, not just `Name`.
- **Partial Template Specialization (Definition)**
  ```cpp
  template <partial-template-parameters> CO_DEF(ReturnType, Name<full-template-parameters>, ArgType) {
    CO_BEGIN(max_stage)
    // ... your code may use partial-template-parameters ...
    CO_RETURN(value)
    CO_END()
  } // coroutine-body
  ```
  `ReturnType` and `ArgType` must be same as declaration. Note that `Name<full-template-parameters>` is passed, not just `Name`. Coroutine-body may also use `partial-template-parameters`.
- **Explicit(Full) Template Specialization (Declaration)**
  ```cpp
  template <> CO_DECL(ReturnType, Name<full-template-parameters>, ArgType, Variables)
  ```
- **Explicit(Full) Template Specialization (Definition)**
  ```cpp
  CO_DEF(ReturnType, Name<full-template-parameters>, ArgType) {
    CO_BEGIN(max_stage)
    // ... your code ...
    CO_RETURN(value)
    CO_END()
  } // coroutine-body
  ```
  `ReturnType` and `ArgType` must be same as declaration. Note that `template <>` is omitted.

### Stages and Suspension

**Stage**: Integer label for each suspension point. `CO_BEGIN(N)` must use `N` = max stage number.

**CO_statements**: 
- These are macros used to control the flow of coroutines. `CO_DECL` and `CO_DEF` macros are not statements, they are used to declare and define a coroutine.
- CO_statements doesn't need to be terminated with a semi-colon.
- `CO_AWAIT`, `CO_NAP`, `CO_SLEEP`, `CO_UNTIL` are the CO_statements that can suspend a coroutine. Later, the coroutine resumes right 
  after the CO_statement. These CO_statements are marked with a stage number (the first argument). These are also referred to as *suspension points*.
- The stage numbers in suspension points within a coroutine must start with 1 and be consecutive.
- CO_statements like `CO_BEGIN`, `CO_RETURN` and `CO_END` doesn't require a stage number.
- Detailed usage:
    - ```CO_AWAIT(stage_no, awaitable[, retVar][, args…])```
      <br> Suspends until `awaitable` completes. On resume, stores its return value into `retVar`. Only pass `retVar` if `awaitable` is a coroutine with non-void return type. Do not pass `retVar` for tasks or futures. If `awaitable` is a raw coroutine, `args…` (if any) are forwarded as its arguments; arguments to tasks are passed while [scheduling](#scheduling-tasks), so while awaiting do not pass any arguments. Futures have no arguments.
    - ```CO_NAP(stage_no)```
      <br> Suspends for one event-loop cycle.
    - ```CO_SLEEP(stage_no, duration)```
      <br> Suspends for the specified time. Use the following functions for `duration`:
      ```cpp
      async_tiny::time::nsec(value); // returns async_tiny::time::Time(value, async_tiny::time::TimeUnit::NANO_SECOND)
      async_tiny::time::usec(value); // returns async_tiny::time::Time(value, async_tiny::time::TimeUnit::MICRO_SECOND)
      async_tiny::time::msec(value); // returns async_tiny::time::Time(value, async_tiny::time::TimeUnit::MILLI_SECOND)
      async_tiny::time::sec(value);  // returns async_tiny::time::Time(value, async_tiny::time::TimeUnit::SECOND)
      ```
      <br> Use the following template function to get current time:
      ```cpp
      async_tiny::time::now<async_tiny::time::TimeUnit::UnitName>(); // returns current time (uint32_t)
      ```
    - ```CO_UNTIL(stage_no, condition)```
      <br> Suspends and polls each cycle until `condition` evaluates to `true`.

### Returning Values

- `CO_RETURN(value)` immediately terminates the coroutine, returning `value` to the awaiting context.
- `CO_RETURN()` immediately terminates the coroutine, returns nothing. (for coroutines with `void` return type)
- Calling `CO_RETURN` for coroutines with `void` return type is optional.
- A non-`void` coroutine must call `CO_RETURN` on all code paths to avoid undefined return values.

### Coroutine Execution Flow

- **Starting Execution**: 
  - Each time the coroutine is executed (i.e., first time execution, or, resumption after each suspension), execution begins at the top of the coroutine body, right after the opening curly brace (`{`).
  - Then control reaches `CO_BEGIN`. The `CO_BEGIN` macro makes the control jump to the CO_Statement from which it suspended last time.
- **First Execution**: 
  <br> On the first execution (i.e., no prior suspension), control reaches `CO_BEGIN` and then proceeds to the code immediately following `CO_BEGIN`.
- **Suspension Points**: 
  <br> When resuming after a suspension (e.g., from `CO_AWAIT`, `CO_SLEEP`), control jumps to the line right after the suspension point.
- **Loops**: 
  <br> Standard C++ loops (e.g., `while`, `for`) function normally. If a suspension point is inside a loop, the loop condition is re-evaluated after each resumption, and the loop body executes if the condition is true.
- **Termination**: 
  - `CO_RETURN` immmediately terminates the coroutine and returns value (if the return type is non-`void`).
  - `CO_END` marks the end of the coroutine, terminates the coroutine, but, returns nothing.
  - Any code after `CO_END` is never executed.

**Example**:
```cpp
CO_DEF(ReturnType, Name, ArgType, Variables) {
    // Executed every time the coroutine is executed
    
    CO_BEGIN(max_stage)
    
    // Executed only on the first invocation
    
    CO_Statement(1, ...)
    
    // Resumes here after suspension from CO_Statement(1, ...)
    // Not executed when coroutine resumes after suspension from CO_Statement(2, ...)
    
    while(condition1) {
        // Executed once on resuming after suspension from CO_Statement(1, ...),  
        // and, then on each resumption after suspension from CO_Statement(2, ...) until condition1 is true and condition2 is false
        
        CO_Statement(2, ...)
        
        // Resumes here after suspension from CO_Statement(2, ...)
        // Executed on each resumption after suspension from CO_Statement(2, ...)
        
        if (condition2) {
            CO_RETURN(value) // Returns value and terminates coroutine immediately
        }
        // Executed on each resumption after suspension from CO_Statement(2, ...) until condition2 is false
    }
    
    CO_RETURN(value) // Returns value and terminates coroutine immediately
    
    CO_END() // Executed only when control didn't reach any CO_RETURN statement
    
    // Never executed
}
```
**Note**: Understanding this execution flow is crucial for writing correct coroutines and debugging issues related to variable state and control jumps.

### Local Variables

- Variables (including coroutines, tasks, or futures) intended to retain their state or value on resumption after suspension must be 
  declared in the `Variables` argument of `CO_DECL` or `CO_DEF`. These are accessible within the coroutine body via the `vars` variable. 
  They maintain their state throughout the coroutine’s lifecycle. Variables passed as arguments to `CO_AWAIT` must retain their states.
- It's ok to define variables in the coroutine-body, if it doesn't need to persist across suspensions. Declare such variables before 
  `CO_BEGIN` statement. 
- Variables declared after `CO_BEGIN` in the coroutine body, even if not intended to persist, will cause compiler errors (e.g., "jump 
  to label skips initialization of variable"). This occurs because suspension points may cause the coroutine to resume at a point that 
  skips the variable’s declaration. This can be avoided by enclosing the relevant *sequential code segment* along with the variable 
  declaration within `{}`, or, simply moving the variable declaration before `CO_BEGIN`.
- Example:
  ```cpp
  CO_DEF(void, MyCoro, int, 
      int counter = 0, coroArg, coroResult; MyCoro coro; MyOtherCoro otherCoro;
      async_tiny::awaitables::tasks::Task_C<MyOtherCoro> otherTask;
  ) {
      const int someConstant = 77; // OK: Doesn't need to persist across suspensions, but its value remains same in each execution
      CO_BEGIN(2)
      
      vars.coroArg = someFunc(vars.counter, args);
      CO_AWAIT(1, vars.coro, vars.coroResult, vars.coroArg) // OK: vars.coro, vars.coroResult, vars.coroArg persist across suspensions
      
      vars.counter++; // Persists across suspensions
      {
          // No suspension point should be present within this brace enclosed segment
          int arg1 = someFunc(vars.counter, args); // OK: Declaration enclosed within {}; Doesn't need to persist across suspensions
          async_tiny::EventLoop::schedule_task(vars.otherTask, vars.otherCoro, arg1, someConstant);
      }
      
      CO_AWAIT(2, vars.otherTask); // OK: vars.otherTask persists across suspensions
      
      CO_END()
  }
  ```

### Scheduling Tasks

1. Set maximum concurrent tasks:
   ```cpp
   async_tiny::EventLoop::set_task_limit(taskLimit);
   ```
   This function allocates some memory proportional to `taskLimit`.

2. Wrap a coroutine in a task and schedule it:
   ```cpp
   MyCoro coro; // raw coroutine object
   async_tiny::awaitables::tasks::Task_C<MyCoro> task;
   bool ok = async_tiny::EventLoop::schedule_task(task, coro, initArg);
   ```
   `schedule_task` returns `false` if the task limit is reached.

### Running the Event Loop

Pump the loop until all tasks complete:

```cpp
while (!async_tiny::EventLoop::run_loop_once());
```
`run_loop_once` returns `true` when all tasks are executed.

<br> After completion, retrieve task results:
```cpp
auto result = task.get_result();
```

---

## Examples

This section provides examples showing how to use `async_tiny` in different environments.

### PC Example (CMake)

The following example demonstrates how to use `async_tiny` in a PC C++ application. It shows:
- Defining different types of coroutines
- Using sleep operations
- Awaiting coroutines and tasks
- Managing an event loop

```cpp
#include <iostream>
#include <async_tiny.hpp>

// A simple coroutine that just sleeps and then returns a value
CO_DEF(int, SimpleSleeper, unsigned int, ) {
    CO_BEGIN(1)
    std::cout << "SimpleSleeper: Sleeping for " << args << " ms..." << std::endl;
    CO_SLEEP(1, async_tiny::time::msec(args))
    std::cout << "SimpleSleeper: Woke up!" << std::endl;
    CO_RETURN(42)
    CO_END()
}

// A coroutine that counts from 0 to a given number with pauses between counts
CO_DEF(void, Counter, unsigned long long, 
    int current = 0; // Persistent variable to track count across suspensions
) {
    CO_BEGIN(2)
    std::cout << "Counter: Starting to count from 0 to " << args << std::endl;
    
    while (vars.current <= args) {
        if (vars.current%10000 == 0) std::cout << "Counter: Current count is " << vars.current << std::endl;
        vars.current++;
        
        if (vars.current <= args) {
            // yield for one event loop cycle
            if (vars.current%10000 == 1) {
                std::cout << "Counter: Sleeping for " << vars.current/1000 << "ms..." << std::endl;
                CO_SLEEP(1, async_tiny::time::msec(vars.current/1000))
            }
            else CO_NAP(2)
        }
    }
    
    std::cout << "Counter: Finished counting!" << std::endl;
    CO_END()
}

// A coroutine that waits until a condition is met
CO_DEF(bool, WaitUntil, unsigned long, 
    unsigned long startTime;
    unsigned long elapsedTime = 0;
) {
    CO_BEGIN(1)
    vars.startTime = async_tiny::time::now<async_tiny::time::TimeUnit::MILLI_SECOND>();
    
    // Wait until specified time has elapsed
    CO_UNTIL(1, (vars.elapsedTime = async_tiny::time::now<async_tiny::time::TimeUnit::MILLI_SECOND>() - vars.startTime) >= args)
    
    std::cout << "WaitUntil: Condition met after " << vars.elapsedTime << " ms" << std::endl;
    CO_RETURN(true)
    CO_END()
}

// A complex coroutine that demonstrates awaiting other coroutines and tasks
CO_DEF(int, ComplexCoro, void, 
    SimpleSleeper sleeper;
    Counter counter;
    WaitUntil waiter;
    async_tiny::awaitables::tasks::Task_C<Counter> counterTask;
    int sleeperResult;
    bool waiterResult;
) {
    CO_BEGIN(3)
    
    std::cout << "ComplexCoro: Starting complex operation" << std::endl;
    
    // Schedule Counter coroutine in a task
    std::cout << "ComplexCoro: Scheduling Counter task" << std::endl;
    async_tiny::EventLoop::schedule_task(vars.counterTask, vars.counter, 180000);
    
    // Await a raw coroutine with a return value
    std::cout << "ComplexCoro: Awaiting SimpleSleeper" << std::endl;
    CO_AWAIT(1, vars.sleeper, vars.sleeperResult, 500)
    std::cout << "ComplexCoro: SimpleSleeper returned " << vars.sleeperResult << std::endl;
    
    // Await another coroutine
    std::cout << "ComplexCoro: Awaiting WaitUntil" << std::endl;
    CO_AWAIT(2, vars.waiter, vars.waiterResult, 1000)
    std::cout << "ComplexCoro: WaitUntil returned " << (vars.waiterResult ? "true" : "false") << std::endl;
    
    // Awaiting Counter task
    std::cout << "ComplexCoro: Awaiting Counter task" << std::endl;
    CO_AWAIT(3, vars.counterTask)
    std::cout << "ComplexCoro: Counter task completed" << std::endl;
    
    std::cout << "ComplexCoro: All operations completed!" << std::endl;
    CO_RETURN(100)
    CO_END()
}

int main() {
    // Set the maximum number of concurrent tasks
    async_tiny::EventLoop::set_task_limit(5);
    
    // Create our main coroutine and wrap it in a task
    ComplexCoro mainCoro;
    async_tiny::awaitables::tasks::Task_C<ComplexCoro> mainTask;
    
    // Schedule the main task
    std::cout << "Main: Scheduling ComplexCoro task" << std::endl;
    async_tiny::EventLoop::schedule_task(mainTask, mainCoro);
    
    // Run the event loop until all tasks complete
    std::cout << "Main: Running event loop" << std::endl;
    while (!async_tiny::EventLoop::run_loop_once());
    
    // Get the result of the main task
    int result = mainTask.get_result();
    std::cout << "Main: ComplexCoro task returned " << result << std::endl;
    
    return 0;
}
```

#### Running the PC Example

To build and run this example:

1. Create a new directory for your project
2. Create a `main.cpp` file with the code above
3. Create a `CMakeLists.txt` file with the following content:

```cmake
cmake_minimum_required(VERSION 3.18)
project(AsyncTinyExample)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find AsyncTiny package
find_package(AsyncTiny REQUIRED)

# Add executable
add_executable(async_example main.cpp)

# Link against AsyncTiny
target_link_libraries(async_example PRIVATE AsyncTiny)
```

4. Build and run:
```bash
mkdir build && cd build
cmake -DCMAKE_PREFIX_PATH=/path/to/asynctiny/install ..
cmake --build .
./async_example
```

### Arduino Example

This example demonstrates using `async_tiny` on an Arduino to control LEDs, monitor a button press, and move a servo motor. It shows how to:
- Create multiple interacting coroutines
- Monitor input (button press) asynchronously
- Control outputs (LEDs, servo) without blocking
- Schedule and manage tasks in an embedded environment

```cpp
#include <Arduino.h>
#include <Servo.h>
#include <async_tiny.hpp>

// Pin definitions
const int LED_PIN_1 = 3;    // First LED
const int LED_PIN_2 = 5;    // Second LED 
const int LED_PIN_3 = 6;    // Third LED
const int SERVO_PIN = 9;    // Servo control pin
const int BUTTON_PIN = 2;   // Button input pin

// Global objects
Servo myServo;

// LED Blinker coroutine - blinks an LED with specified on/off times
CO_DEF(void, LedBlinker, int32_t, 
    int ledPin;         // The pin number for the LED
    int onTime;         // LED on time in ms
    int offTime;        // LED off time in ms
    bool runForever;    // Whether to run indefinitely
    int cycles = 0;     // Number of blink cycles completed
) {
    const int maxCycles = 5;  // Maximum blink cycles before stopping
    CO_BEGIN(2)
    
    // Extract parameters from the args integer
    vars.ledPin = args & 0xFF;
    vars.onTime = ((args >> 8) & 0xFF) * 10;
    vars.offTime = ((args >> 16) & 0xFF) * 10;
    vars.runForever = (args >> 24) & 0x1;
    
    // Initialize pin
    pinMode(vars.ledPin, OUTPUT);
    
    while (vars.runForever || vars.cycles < maxCycles) {
        // Turn LED on
        digitalWrite(vars.ledPin, HIGH);
        CO_SLEEP(1, async_tiny::time::msec(vars.onTime))
        
        // Turn LED off
        digitalWrite(vars.ledPin, LOW);
        CO_SLEEP(2, async_tiny::time::msec(vars.offTime))
        
        vars.cycles++;
    }
    
    CO_END()
}

// ...more coroutines (Button monitor, Servo controller, etc.)...

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  Serial.println(F("Async_tiny Arduino demo"));
  Serial.println(F("Press the button to start the full demo"));
  
  // Initialize EventLoop with a task limit
  async_tiny::EventLoop::set_task_limit(5);
  
  // Schedule the main controller task
  async_tiny::EventLoop::schedule_task(mainTask, mainController);
  
  Serial.println(F("Setup complete"));
}

void loop() {
  if (async_tiny::EventLoop::run_loop_once()) {
    // auto-restart the demo after 5 seconds
    delay(5000);
    async_tiny::EventLoop::schedule_task(mainTask, mainController);
  }
}
```

#### Arduino Circuit Setup

To run this example, set up the following circuit:

1. **LEDs:**
   - Connect three LEDs with their cathodes to ground through 220-ohm resistors
   - Connect LED anodes to the following pins:
     - LED 1: Pin 3
     - LED 2: Pin 5
     - LED 3: Pin 6

2. **Servo Motor:**
   - Connect the servo ground (black/brown wire) to Arduino GND
   - Connect the servo power (red wire) to Arduino 5V
   - Connect the servo signal (orange/yellow wire) to Arduino Pin 9

3. **Push Button:**
   - Connect one end of the button to Arduino GND through a 10K-ohm pull-down resistor
   - Connect the same end of the button to Arduino Pin 2
   - Connect the other end of the button to Arduino 5V

#### Running the Arduino Example

1. Install AsyncTiny library in Arduino IDE:
   - Go to `Sketch > Include Library > Add .ZIP Library`
   - Select the AsyncTiny.zip file generated from the build process

2. Open a new sketch and paste the example code
3. Connect your Arduino as described in the circuit setup
4. Upload the sketch to your Arduino

When running, the demo will:
1. Start with two LEDs blinking at different rates
2. Wait for a button press
3. When the button is pressed, run a light pattern sequence across the three LEDs while simultaneously moving the servo motor
4. Repeat the sequence, then restart after 5 seconds

---

## Contributing

Will update soon...

---
