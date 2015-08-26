#!/bin/sh
G_total=$1
I_total=$2
#echo "$G_total $I_total"
#cat score.txt|awk -f graph_change.awk \$G_total \$I_total > score1.txt
#cat score.txt|awk -v g_total="$1" i_total="$2" '{print $1,"\t", $2/g_total,"\t", $3/i_total}' > score1.txt
cat test_G_Hist.dat|awk "{print \$1 , "\ " \$2/$G_total*100}" > score.txt
mv score.txt test_G_Hist.dat
cat test_I_Hist.dat|awk "{print \$1 , "\ " \$2/$I_total*100}" > score.txt
mv score.txt test_I_Hist.dat
cat FAR_FRR.txt|awk "{print \$1 *100 , "\ " \$2 *100}" > score.txt
mv score.txt FAR_FRR.txt
