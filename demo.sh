outdir="out"
build="$outdir/demo-build"

mkdir -p $outdir

g++ $1 -g -o $build
valgrind -s --leak-check=full ./$build