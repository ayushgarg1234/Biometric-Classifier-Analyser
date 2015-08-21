#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

using namespace std;

class EER_Data {
public:
	bool G_I;
	float score;
};

class histogram {
public:
	int G_cum = 0;
	int I_cum = 0;
	int diff;
};

int main()
{
	int n = 1000;
	EER_Data *a;
	a = new EER_Data[n];
	ifstream myfile;
	float max = 0, min = 1;
	myfile.open("L4_1000.txt");
	for (int i = 0; i < n; i++)
	{
		int temp1, temp2, temp3, temp4;
		myfile >> temp1;
		myfile >> temp2;
		myfile >> temp3;
		myfile >> temp4;
		myfile >> a[i].G_I;
		myfile >> a[i].score;
		if (a[i].score < min)
			min = a[i].score;
		if (a[i].score > max)
			max = a[i].score;
		//cout << a[i].G_I << " " << a[i].score << "\n";
	}
	myfile.close();

	int no_of_buckets = (max - min) * 1000000;

	histogram *array;
	array = new histogram[no_of_buckets+1];

	for (int i = 0; i < n; i++)
	{
		//cout << a[i].G_I << " " << a[i].score << "\n";
		int index = (a[i].score - min) * 1000000;
		if (a[i].G_I)
			array[index].G_cum++;
		else
			array[index].I_cum++;
		//cout << index << " " << array[index].G_cum << "\n";
	}

	ofstream score;
	score.open("score.txt");

	for (int i = 0; i <= 1000000; i++)
	{
		if ((float(i) / 1000000 < min) || (float(i) / 1000000 > max))
			score << float(i) / 1000000 << " " << "0" << " " << "0" << "\n";
		else
			score << float(i) / 1000000 << " " << array[i - int(min*1000000)].G_cum << " " << array[i - int(min * 1000000)].I_cum << "\n";
		
	}
	
	score.close();
	//test << max << " " << min << " " << n << "\n";
/*	for (int i = 0; i < no_of_buckets; i++)
	{
		test << array[i].G_cum << " " << array[i].I_cum << "\n";
	}

	*/
	//cout << array[no_of_buckets].I_cum;
	for (int i = 1; i <= no_of_buckets ; i++)
	{
		array[i].I_cum = array[i - 1].I_cum + array[i].I_cum;
		array[no_of_buckets - i - 1].G_cum = array[no_of_buckets - i].G_cum + array[no_of_buckets - i - 1].G_cum;
	}

	ofstream FAvsFR;
	FAvsFR.open("FA_FR.txt");

	for (int i = 0; i <= no_of_buckets; i++)
	{
		FAvsFR << array[i].G_cum << " " << array[i].I_cum << "\n";
	}

	FAvsFR.close();

	for (int i = 0; i <= no_of_buckets; i++)
	{
		//test << array[i].G_cum << " " << array[i].I_cum << " ";
		array[i].diff = abs(array[i].G_cum - array[i].I_cum);
		//test << array[i].diff << "\n";
	}

	int min_diff = array[0].diff;
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
	float theshold = (min + (float(min_index) + float(min_count)/2)/1000000);
	//cout << theshold << " " << array[285664].diff << "\n";

	cin >> n;
}