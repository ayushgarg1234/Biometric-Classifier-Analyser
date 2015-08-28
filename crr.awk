#!/bin/awk -f
BEGIN{correct=0;incorrect=0;total=0}
{
if($6==1)
correct++;
else
incorrect++;
total++;
}
END{print "Decidability Index        (DI) =  "
print "Correct Recognition Rate (CRR) =  ", (correct/total)*100
print "Equal Error Rate         (EER) =  "
system("")
print "**************************************************************************************************************************************"
print "Failed Subject in Identification (CRR Failure)"
print "==========================="
print "+++++++++++++++++++++++++++++++++++++++++++++++++++++"
print "Total Failed Subject =  ",incorrect," (out of ",total,")"}