#!/bin/sh
G_total=$1
I_total=$2
#echo "$G_total $I_total"
#cat score.txt|awk -f graph_change.awk \$G_total \$I_total > score1.txt
#cat score.txt|awk -v g_total="$1" i_total="$2" '{print $1,"\t", $2/g_total,"\t", $3/i_total}' > score1.txt
cat score.txt|awk "{print \$1 , "\t" \$2/$G_total*100 ,"\t" \$3/$I_total*100}" > score1.txt
mv score1.txt score.txt
