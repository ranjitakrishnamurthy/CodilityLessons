
#include <iostream>
using namespace std;

#include <bitset>

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    char testForZero = '0';
    char testForOne ='1';
    const int bitSetRange = 64;
    
    int zeroBinGapCounter =0, count0=0;
    bool setStartGap = 0;
    
    std::string binary = std::bitset<bitSetRange>(N).to_string();
    
    //cout<<"The binary size:"<<binary.size();
    //cout<<"The binary number:"<<binary;
    
    for(int cnt =0;cnt<binary.size();cnt++)
    {
       
       if(binary[cnt] == testForOne && setStartGap == 0)//start of Gap
       {
           setStartGap = 1;//true;
           count0 = 0;
           //cout<<"\n"<<"setStartGap value in condition 1"<<"\t"<<setStartGap;
       }
       
      // cout<<"\n"<<"cnt"<<cnt;
       //cout<<"\n"<<"binary digit"<<binary[cnt];
       if(binary[cnt] == testForZero && setStartGap == 1)
       {
           count0++;
           //cout<<"count0:"<<"\t"<<count0;
       }
       else if(binary[cnt] == '1' && setStartGap == 1)//end of Gap
       {
           if(zeroBinGapCounter < count0)
           {
                zeroBinGapCounter = count0;
                count0 =0;
           }
          
       }
    }
    //Results
    if(zeroBinGapCounter ==0) 
    {
        return 0;
    }
    else
    {
        
        //cout<<"zeroBinGapCounter:"<<zeroBinGapCounter;
        return zeroBinGapCounter;
    }
}
int main()
{
    int binaryGapNum =0;
    int Number =0;
    
    cout<<"Enter the Number: ";
    cin>>Number;
    binaryGapNum = solution(Number);
    cout<<"The longest binary gap is :"<<binaryGapNum;

    return 0;
}