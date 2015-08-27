#!/bin/sh
gnuplot<<-EOF
inpfile = 'FAR_FRR.txt'
set terminal postscript
set terminal png transparent nocrop enhanced size 640,480 font "arial,13" 
set obj 1 rectangle behind from screen 0,0 to screen 1,1
set obj 1 fillstyle solid 1.0 fillcolor rgbcolor "white"
set style fill transparent
set output "FAR_FRR.png"
set title "FAR vs FRR" 
set xlabel "FRR (%)"
set ylabel "FAR (%)"
set grid layerdefault lt 0 linewidth 1.000,  lt 0 linewidth 1.000
set datafile missing '-'
set xrange [ 0.000000 : 100.000000 ]
set yrange [ 0.000000: 5.000000 ]
plot inpfile notitle w lines 
EOF
