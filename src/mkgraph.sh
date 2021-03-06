set terminal png size 800,480 enhanced font 'Arial, 16'
set output 'tree-hash.png'

set style line 1 linecolor rgb 'red' linetype 1 linewidth 2
set style line 2 linecolor rgb 'blue' linetype 1 linewidth 2

set border linewidth 1
set key top left
set grid
set mytics
set format y "%.6f"
set xlabel "Number of elements" font "Arial, 16"
set format x "%.0f" 
set ylabel "Execution time (sec)" font "Arial, 16"
set xtics 100000 font "Arial, 12"
set ytics font "Arial, 12"
set rmargin 4
set tmargin 2
set mxtics

plot "tree.dat" using 1:2 title " hash.dat" with line ls 1,\
	"hash.dat" using 1:2 title "Hash" with line ls 2
