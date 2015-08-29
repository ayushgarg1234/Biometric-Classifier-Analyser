# Biometric-Classifier-Analyser
This is a Linux-based Application intended for analysis of Biometric System Classifier data. It uses C++ programming language using histogram data structure and awk for its implementation.

It has following features:

* It outputs 2 graphs : 
  No of Genuines and Imposters on each classifier Score, and FAR (False Acceptance Ratio) vs FRR (False Rejection Ratio)
* Detailed statistics file with details such as averages, standard deviations and errors of genuine and imposters, EER,    CRR,Decidability Index.
* It also provides FA, FR, FAR vs FRR, as well as Histogram data files for future analysis.


##How to Use

Install Gnuplot. Execute main.sh program with "filename" (without quotes) as an argument.

```shell
sh main.sh filename
```
