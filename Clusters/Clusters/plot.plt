set terminal png 
set output "graph.png" 1024 768
plot "ks.txt" using 1:2 with lines linecolor 1