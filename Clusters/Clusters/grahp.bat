@echo gnuplot
@echo set terminal png size 1024, 768| gnuplot -persist
@echo set output "graph.png" | gnuplot -persist
@echo plot "outX.txt" using 1:2 with lines linecolor 1 lw 2 | gnuplot -persist


