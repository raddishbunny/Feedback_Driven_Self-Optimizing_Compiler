<b>FeedbackDrivenSelfOptimizingCompiler</b>
<br>
A custom compiler that uses runtime profiling to identify frequently executed code paths and applies optimizations such as constant folding and loop optimizations to improve performance.
<br>
===>(1.)Project Setup
<br>
  ->Required build tools installed:<br>
    sudo apt update<br>
    sudo apt install build-essential cmake<br>
<br>
===>(2.)Build Instructions<br>
  cd ~/CompilerDesign/FeedbackDrivenSelfOptimizingCompiler<br>
  mkdir -p build<br>
  cd build<br>
  cmake ..<br>
  make<br>
<br>
===>(3.)Running the Compiler<br>
  ->Run the compiler on sample test programs:<br>
    ./compiler ../tests/sample1.lang<br>
    ./compiler ../tests/sample2.lang<br>
  This will:<br>
    Parse the source code<br>
    Generate Intermediate Representation (IR)<br>
    Apply optimizations<br>
    Produce output.c<br>
<br>
===>(4.)Compile and Execute Generated Code<br>
  gcc output.c ../src/backend/profiler_runtime.c -I../src/backend -o program<br>
  ./program<br>
<br>
===>(5.)View Profiling Data<br>
  cat profile.txt<br>
  This file contains execution frequency of labels, used for feedback-driven optimizations.<br>
<br>
===>Rebuilding the Project if build issue<br>
  cd ~/CompilerDesign/FeedbackDrivenSelfOptimizingCompiler<br>
  rm -rf build<br>
  mkdir build<br>
  cd build<br>
  cmake ..<br>
  make<br>
