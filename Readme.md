## 🚀 Quick Run

<div style="background-color:#111; padding:15px; border-radius:8px;">

<pre><code>
cd ~/CompilerDesign/FeedbackDrivenSelfOptimizingCompiler/build

cmake ..
make

./compiler ../tests/sample2.lang

gcc output.c ../src/backend/profiler_runtime.c -I../src/backend -o program
./program

cat profile.txt
</code></pre>

</div>
