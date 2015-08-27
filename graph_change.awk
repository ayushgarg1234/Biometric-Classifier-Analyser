#!/bin/awk -f
BEGIN {}
{print $1,"\t",$2/10,"\t",$3/990}
END{}
