# set terminal png transparent nocrop enhanced size 450,320 font "arial,8" 
# set output 'histograms.2.png'
set title "Genuine vs Imposter" 
set xlabel "Score (%)"
set ylabel "Frequency (%)"
set grid layerdefault lt 0 linewidth 1.500,  lt 1 linewidth 0.500
set xtic auto 
set ytic auto
set datafile missing '-'
set xrange [ 0.000 : 1000 ]
set yrange [ 0.000: 2.500 ]
## Last datafile plotted: "immigration.dat"
plot "test_G_Hist.dat" t 'Genuine' w impulses,\
"test_I_Hist.dat" t 'Imposter' w impulses
