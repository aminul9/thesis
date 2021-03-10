


#include<iostream>
#include <fstream>
#include <iomanip>
using namespace std;


void endl1(int n)
{
    for(int i=0;i<=n;i++)
        cout<<endl;
}

int main()
{

    int state=5;

   FILE *fp = fopen("input.txt","r");
    int r=5,c=5;
   // freopen("matin.txt","r",stdin);
    double mat[10][10];
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
           {
                fscanf(fp, "%lf", &mat[i][j]);
           }

     for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            cout<<fixed<<setprecision(2)<<mat[i][j]<<" ";
            cout<<endl;
        }
        fclose(fp);


    double fixedMat[20][20];

    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            fixedMat[i][j]=mat[i][j];

    endl1(5);


for(int turning=1;turning<=5;turning++)
 {



    cout<<"*****************************************************";endl1(0);






        int res=-1;
        int big=-1;
        double totalMax=.0;
        for(int i=1;i<=r;i++)
        {
            double resMax=0.0;

            for(int j=1;j<=c;j++)
            {
                double temp=0.0;
                for(int k=1;k<=c;k++)
                {
                    temp+=mat[i][k]*mat[k][j];
                  // cout<<i<<k<<'*'<<k<<j<<" ";
                }

                if(resMax<temp)
                {
                    resMax=temp;
                    res=j;

                    if(resMax>totalMax)
                    {
                        totalMax=resMax;
                        big=j;
                    }
                }
               // endl1(1);


            }

            printf("start node %d to node %d pob=%lf",i,res,resMax);
           // printf("\n------------%d------------",big);
            endl1(2);
        }
        //  cout<<"The loop number "<<turning<<" \t The start state "<<starting_state <<"  \t ENd state "<<res<<'\t'<<" maxprob=" <<resMax;endl1(3);





                    //-----------------------------------------------OnlyMultiplication is done here
                int starting_state=1;

                      int i,j,k;
                        double mul[10][10];
                        for(i=1;i<=r;i++)
                        {
                            for(j=1;j<=c;j++)
                            {
                                mul[i][j]=0;
                                for(k=1;k<=c;k++)
                                {
                                    mul[i][j]+=mat[i][k]*fixedMat[k][j];
                                }
                            }
                        }
                        //copy to main
                        for(i=1;i<=r;i++){
                            for(j=1;j<=c;j++){
                                       mat[i][j]=mul[i][j];
                                       cout<<mat[i][j]<<"\t";
                                       }
                                 cout<<endl;
                        }
                //Multiplication is done here


 }

//-------------------------------------------------




    return 0;
}

