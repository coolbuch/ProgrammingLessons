@echo gnuplot
@echo set terminal png | gnuplot -persist
@echo set output "graph.png" | gnuplot -persist
@echo plot "outX.txt" using 1:2 with lines linecolor 1 lw 2 | gnuplot -persist

