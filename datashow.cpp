#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int main()
{

    freopen("ami.txt","r",stdin);


    int arry[1000];

    int i=0;

    while(cin>>arry[i]){

    i++;}


    for(int j=0;j<=12;j++)
    {
        int store[60];
        for(int m=0;m<50;m++)
            store[m]=0;
        for(int k=0;k<i-1;k++)
        {
            if(arry[k]==j)
            {
               // cout<<"***"<<k<<" "<<j<<" "<<arry[k+1]<<"***";
               store[ arry[k+1] ] ++;
            }
        }

        cout<<j<<endl;
        int total=0;
        for(int k=0;k<12;k++)
        {
            if(store[k]==0)continue;

            cout<<"( "<<k<<" -> "<<store[k]<<") ";
             total+=store[k];
        }

       cout<<"**"<<total<<endl<<endl<<endl;
    }



    return 0;
}
