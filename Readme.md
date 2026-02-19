{  FeedbackDrivenSelfOptimizingCompiler }
 
{
  cd ~/CompilerDesign/FeedbackDrivenSelfOptimizingCompiler
  #in build
    sudo apt update
    sudo apt install build-essential cmake
    cmake ..
    make
  #run test
    ./compiler ../tests/sample1.lang
    ./compiler ../tests/sample2.lang
}

{
  #Re-build
    rm -rf build
    mkdir build && cd build
    cmake ..
    make
}

{
  #Moment of Judgement
    gcc output.c ../src/backend/profiler_runtime.c -I../src/backend -o program
    ./program
    cat profile.txt
}
