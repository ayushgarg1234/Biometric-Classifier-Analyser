set terminal png transparent nocrop enhanced size 450,320 font "arial,8" 
set obj 1 rectangle behind from screen 0,0 to screen 1,1
set obj 1 fillstyle solid 1.0 fillcolor rgbcolor "white"
set style fill transparent
set output 'score.png'
set title "Genuine vs Imposter Score Frequency Histogram" 
set xlabel "Score (%)"
set ylabel "Frequency (%)"
set grid layerdefault lt 0 linewidth 1.000
set xtic auto 
set ytic auto
set datafile missing '-'
set xrange [ 0.000000 : 1.000000 ]
set yrange [ 0.000: 20 ]
plot "score.txt" u 1:2 t 'Genuine' w impulses,\
"score.txt" u 1:3 t 'Imposter' w impulses
