#!/bin/sh
gnuplot<<-EOF
inpfile1 = 'test_G_Hist.dat'
inpfile2 = 'test_I_Hist.dat'
set terminal postscript
set terminal png transparent nocrop enhanced size 640,480 font "arial,13" 
set obj 1 rectangle behind from screen 0,0 to screen 1,1
set obj 1 fillstyle solid 1.0 fillcolor rgbcolor "white"
set style fill transparent
set output "score.png"
set title "Genuine vs Imposter Score Frequency Histogram" 
set xlabel "Score (%)"
set ylabel "Frequency (%)"
set grid layerdefault lt 0 linewidth 1.000,  lt 0 linewidth 1.000
set datafile missing '-'
set xrange [ 0.000000 : 1.010000 ]
set yrange [ 0.000: 0.050000 ]
plot inpfile1 t 'Genuine' w impulses,\
inpfile2 t 'Imposter' w impulses
EOF
