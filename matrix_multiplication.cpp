#include<iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{

    int state=5;

   FILE *fp = fopen("matin.txt","r");
    int r=8,c=8;
   // freopen("matin.txt","r",stdin);
    double mat[10][10];
    for(int i=0;i<=8;i++)
        for(int j=0;j<=8;j++)
           {
                fscanf(fp, "%lf", &mat[i][j]);
           }

     for(int i=0;i<=8;i++)
        {
            for(int j=0;j<=8;j++)
            cout<<fixed<<setprecision(2)<<mat[i][j]<<" ";
            cout<<endl;
        }
        fclose(fp);



    int m=1;
    while(m)
    {

        int nexstate=0;
        double maxprobability=0;
        for(int which_state_can_go=0;which_state_can_go<=8;which_state_can_go++)
        {
            double temp_result=0.0;
            for(int nextstate_can_go=0;nextstate_can_go<=8;nextstate_can_go++)
            {
                temp_result+=(mat[state][nextstate_can_go]*mat[nextstate_can_go][which_state_can_go]);
            }
            if(temp_result >=maxprobability)
            {
                maxprobability=temp_result;
                nexstate=which_state_can_go;
            }

            cout<<"state="<<state<<" nextstat="<<which_state_can_go<<"  "<<temp_result<<endl;
        }
        cout<<" ***state "<< state<<"can reach "<<nexstate<<"****"<<endl;
        state=nexstate;


        printf("We are going to parfrom next %d ",m);
        scanf("%d",&m);

        double mul[10][10];

            for(int i=0;i<r;i++)
                {
                    for(int j=0;j<c;j++)
                    {
                        mul[i][j]=0;
                        for(int k=0;k<c;k++)
                        {
                            mul[i][j]+=mat[i][k]*mat[k][j];
                        }
                    }
                }

                //------------copy to  a


               for(int i=0;i<r;i++)
                {
                    for(int j=0;j<c;j++)
                    {
                            mat[i][j] = mul[i][j];
                                                    cout<<mat[i][j]<<"  ";


                    }
                    cout<<endl;
                }

                m++;

                cout<<" ----*----"<<endl<<endl<<endl<<endl;


    }




    return 0;
}
