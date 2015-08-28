#!/bin/awk -f
NR==FNR{EER=$1; thresh=$2; diff=$3; FR=$4; Gen=$5; FA=$6; Imp=$7; FAR=$8; FRR=$9; next}
NR==FNR+1{a[FNR]=$1; next}
BEGIN{correct=0;incorrect=0;total=0}
{
if($6==1)
correct++;
else
incorrect++;
total++;
}
END{
print "**************************************************************************************************************************************" 
print "Performance Parameters" 
print "==========================="
print "Decidability Index        (DI) =  ", "~" , (a[6]-a[2])/sqrt(a[3]^2+a[7]^2)
print "Correct Recognition Rate (CRR) =  ", (correct/total)*100
print "Equal Error Rate         (EER) =  (", EER, ")", " ",thresh," with Difference = ",diff
print "**************************************************************************************************************************************"
print "Failed Subject in Identification (CRR Failure)"
print "==========================="
print "+++++++++++++++++++++++++++++++++++++++++++++++++++++"
print "Total Failed Subject =  ",incorrect," (out of ",total,")"
print "+++++++++++++++++++++++++++++++++++++++++++++++++++++"
print "**************************************************************************************************************************************"
print "+++++++++++++++++++++++++++++++++++++++++++++++++++++"
print "Total No. of Falsely Reject Matching =  ", FR," out of total ",Gen," genuine matching"
print "+++++++++++++++++++++++++++++++++++++++++++++++++++++"
print "**************************************************************************************************************************************"
print "+++++++++++++++++++++++++++++++++++++++++++++++++++++"
print "Total No. of Falsely Accept Matching =  ", FA," out of total ",Imp," imposter matching"
print "+++++++++++++++++++++++++++++++++++++++++++++++++++++"
print "**************************************************************************************************************************************"
print "Actual Performance Parameters"
print "==========================="
print "False Acceptance Rate        (FAR) = 	",FAR
print "False Rejection  Rate        (FRR) =    ",FRR
print "**************************************************************************************************************************************"
}
