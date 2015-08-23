DIRECTIVE="gcc-4.9 -fopenmp -std=c11"
OUTPUT=targets
list="hello integral parallel_integral count_threads pi parallel_work"
for code_name in $list
do
    echo "compiling " $code_name
    $DIRECTIVE  -o $OUTPUT/$code_name $code_name.c
done
