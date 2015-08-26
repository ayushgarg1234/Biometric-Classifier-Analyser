#include <iostream>
#include <fstream>
#include <cmath>
#include<cstdlib>
#include<sstream>
#include<cstring>
//#include <vector>

using namespace std;

/*
class EER_Data {
public:
	bool G_I;
	float score;
};*/

class histogram {
public:
	float G_cum;
	float I_cum;
	float diff;
	histogram();
};

histogram::histogram()
{
	G_cum = 0;
	I_cum = 0;
}

int main()
{
	//int n = 1000;
	ifstream myfile;
	//float max = 0, min = 1;
	myfile.open("EER_input.txt");
    //ifstream fin("EER_input.txt", ios::in);
    int no_of_buckets = 1000000;
    
    histogram *array;
	array = new histogram[no_of_buckets + 1];

    while(!myfile.eof())
    {
        int G_I;
        float score;
    	/*myfile >> temp1;
	    myfile >> temp2;
    	myfile >> temp3;
        myfile >> temp4;*/
    	myfile >> G_I;
    	myfile >> score;
        int index = score * 1000000;
	    if (G_I)
		    array[index].G_cum++;
	    else
		    array[index].I_cum++;	
        //cout << index << " " << array[index].G_cum << "\n";
	}

	ofstream test_G_Hist;
	test_G_Hist.open("test_G_Hist.dat");

	ofstream test_I_Hist;
	test_I_Hist.open("test_I_Hist.dat");


	myfile.close();
	for (int i = 0; i <= no_of_buckets; i++)
	{
		/*		if ((float(i) / 1000000 < min) || (float(i) / 1000000 > max))
					score << float(i) / 1000000 << " " << "0" << " " << "0" << "\n";
				else*/
		if (array[i].G_cum != 0)
			test_G_Hist << (float(i) / 1000000) << " " << array[i].G_cum << "\n";
		if (array[i].I_cum != 0)
			test_I_Hist << (float(i) / 1000000) << " " << array[i].I_cum << "\n";

	}

	test_G_Hist.close();
	test_I_Hist.close();
	//test << max << " " << min << " " << n << "\n";
    /*	for (int i = 0; i < no_of_buckets; i++)
	{
		test << array[i].G_cum << " " << array[i].I_cum << "\n";
	}

    */
	//cout << array[0].G_cum << " " << array[no_of_buckets].I_cum;
 

	for (int i = 1; i <= no_of_buckets; i++)
	{
		array[i].I_cum = array[i - 1].I_cum + array[i].I_cum;
		array[no_of_buckets - i].G_cum = array[no_of_buckets - i + 1].G_cum + array[no_of_buckets - i].G_cum;
	}
	//cout << array[0].G_cum << " " << array[no_of_buckets].I_cum<<"\n";
 	stringstream temp1, temp2;
	temp1 << (array[0].G_cum);
	temp2 << (array[no_of_buckets].I_cum);
   
   	int total_G = array[0].G_cum, total_I = array[no_of_buckets].I_cum;

	for (int i = 0; i <= no_of_buckets; i++)
	{
		array[i].G_cum = array[i].G_cum / total_G;
		array[i].I_cum = array[i].I_cum / total_I;
	}

	ofstream FARvsFRR;
	FARvsFRR.open("FAR_FRR.txt");

	for (int i = 0; i <= no_of_buckets; i++)
	{
		FARvsFRR << array[i].G_cum << " " << array[i].I_cum << "\n";
	}

	FARvsFRR.close();

	char command[60] = "sh graph_change.sh ";
	strcat(command, temp1.str().c_str());
	strcat(command, " ");
	strcat(command, temp2.str().c_str());
	system(command);
	strcpy(command, "sh graph_generate.sh");
	system(command);    

    strcpy(command, "sh graph_generate1.sh");
	system(command);
	
    for (int i = 0; i <= no_of_buckets; i++)
	{
		//test << array[i].G_cum << " " << array[i].I_cum << " ";
		array[i].diff = abs(array[i].G_cum - array[i].I_cum);
		//test << array[i].diff << "\n";
	}

	float min_diff = array[0].diff;
	int min_index = 0, min_count = 0;


	for (int i = 1; i <= no_of_buckets; i++)
	{
		if (array[i].diff < min_diff)
		{
			min_diff = array[i].diff;
			min_index = i;
			min_count = 1;
		}
		else if (array[i].diff == min_diff)
		{
			min_count++;
		}
		else
			break;
	}

	//cout << min_diff << " " << min_count << " " << min_index << "\n";
	float threshold = ((float(min_index) + float(min_count) / 2) / 1000000);
	cout << threshold << "\n";

	//cin >> n;
	return 0;
}
