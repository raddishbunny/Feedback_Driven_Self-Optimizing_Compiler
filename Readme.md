<b>FeedbackDrivenSelfOptimizingCompiler</b>
<br>
A custom compiler that uses runtime profiling to identify frequently executed code paths and applies optimizations such as constant folding and loop optimizations to improve performance.
<br>
===>(1.)Project Setup
<br>
  ->Required build tools installed:
    sudo apt update
    sudo apt install build-essential cmake
<br>
===>(2.)Build Instructions
  cd ~/CompilerDesign/FeedbackDrivenSelfOptimizingCompiler
  mkdir -p build
  cd build
  cmake ..
  make
<br>
===>(3.)Running the Compiler
  ->Run the compiler on sample test programs:
    ./compiler ../tests/sample1.lang
    ./compiler ../tests/sample2.lang
  This will:
    Parse the source code
    Generate Intermediate Representation (IR)
    Apply optimizations
    Produce output.c
<br>
===>(4.)Compile and Execute Generated Code
  gcc output.c ../src/backend/profiler_runtime.c -I../src/backend -o program
  ./program
<br>
===>(5.)View Profiling Data
  cat profile.txt
  This file contains execution frequency of labels, used for feedback-driven optimizations.
<br>
===>Rebuilding the Project if build issue
  cd ~/CompilerDesign/FeedbackDrivenSelfOptimizingCompiler
  rm -rf build
  mkdir build
  cd build
  cmake ..
  make
