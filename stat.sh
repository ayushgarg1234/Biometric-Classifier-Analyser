awk 'BEGIN {print "**************************************************************************************************************************************" 
print "Genuine" 
print "==========================="}' > stat.sts
awk -f stat.awk test_G_Hist.dat > temp.txt
cat temp.txt >> stat.sts
awk 'BEGIN {print "**************************************************************************************************************************************" 
print "Imposter" 
print "==========================="}' >> stat.sts
awk -f stat.awk test_I_Hist.dat > temp1.txt
cat temp1.txt >> stat.sts
cat temp1.txt >> temp.txt
awk -f crr.awk eer.txt temp.txt CRR.dat >> stat.sts
rm temp.txt temp1.txt eer.txt

