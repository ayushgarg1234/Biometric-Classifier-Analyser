#!/bin/awk -f
BEGIN{sum1=0;sum2=0;n=0}
{
    sum1+=sprintf("%0.8f", $1*$2);
    n++;
    sum2+=sprintf("%0.8f", ($1^2)*$2);  
}
END{avg=sum1/100;avg1=sum2/100;std=sqrt(avg1-avg^2);
    print n," data points" 
	print avg, " average"
    print std, " standard deviation"
    se=sprintf("%0.8f",std/n);
    print se , " standard error"}
