#include<iostream>
#include<fstream>
using namespace std;

class pos{
public:
    int id;
    int image;
};

int main(int argc,char* argv[])
{
    pos test,max_match,min_match,temp;
    test.id=1;test.image=1;
    int test_id,test_image,g_or_i;
    float min_score=1,max_score=0,temp_score;
    ifstream myFile;
    myFile.open(argv[1]);
    ofstream CRR;
    CRR.open("CRR.dat");
    
    myFile >> test_id;
    myFile >> test_image;
    test.id=test_id;test.image=test_image;
    myFile >> min_match.id >> min_match.image >> g_or_i >> min_score;
    max_match.id=min_match.id;
    max_match.image=min_match.image;
    max_score=min_score;
    
    while(!myFile.eof())
    {
        myFile >> test_id;
        myFile >> test_image;
        if(test.id==test_id && test.image==test_image)
        {
            myFile >> temp.id;
            myFile >> temp.image;
            myFile >> g_or_i;
            myFile >> temp_score;
            //cout<< temp_score << " ";
            if(temp_score<min_score)
            {
                min_score=temp_score;
                min_match.id=temp.id;
                min_match.image=temp.image;
            }
            if(temp_score>max_score)
            {
                max_score=temp_score;
                max_match.id=temp.id;
                max_match.image=temp.image;
            }
        }
        else
        {
            CRR << test.id << " " << test.image << " " << min_match.id << " " << min_match.image << " "  << min_score << " "  << max_match.id << " " << max_match.image << " "  << max_score << " " << min_score/max_score << " " << (test.id==min_match.id) <<endl;

            test.id=test_id;test.image=test_image;
            myFile >> min_match.id >> min_match.image >> g_or_i >> min_score;
            max_match.id=min_match.id;
            max_match.image=min_match.image;
            max_score=min_score;
        }
    }

    CRR << test.id << " " << test.image << " " << min_match.id << " " << min_match.image << " "  << min_score << " "  << max_match.id << " " << max_match.image << " "  << max_score << " " << min_score/max_score << " " << (test.id==min_match.id) <<endl;
    
    myFile.close();
    CRR.close();
    return 0;
}
