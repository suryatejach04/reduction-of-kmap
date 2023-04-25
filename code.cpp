#include <iostream>
#include<math.h>
using namespace std;
#define max_size 10000
void tobinary(int a,int c);
int table[max_size][max_size]= {0,0};
int res[max_size];
int index=0,index2=0;

int main()
{
    int no_of_variables,num_minterm,minterm ;
    cout<<"                                           ***REDUCTION OF K MAP***"<<endl;
    cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
    cout << "Enter number of variables:\n";
    cin >> no_of_variables ;
    cout << "Enter number of minterms:\n";
    cin >> num_minterm ;
    int c=num_minterm;
    int count1=0,count2=0,count3=0,count4=0,count5=0,y=0,x=0,max_num=pow(2,no_of_variables);
    cout << "Enter minterms in the range of" << "( 0 ) and ( " << max_num-1 << " )\n" ;
    for(int i=0; i<num_minterm; i++)
    {
again:
        cin >> minterm ;
        if(minterm>=max_num)
        {
            cout << "Enter number in the range" << "( 0 ) and ( " << max_num-1 << " )\n" ;
            goto again ;
        }
        tobinary(minterm,no_of_variables);
    }
    for(int i=0; i<num_minterm; i++)
    {
        if(x==0)
        {
            count1=num_minterm;
            x=1;
        }
        for(int j=i; j<num_minterm; j++)
        {
            for(int n=0; n<no_of_variables; n++)
            {
                if(table[i][n]!=table[j][n]&&i!=j)
                {
                    count5++;
                    y=n;
                }
            }
            if(count5==1)
            {
                table[i][no_of_variables]=1;
                table[j][no_of_variables]=1;
                count4+=2;
                for(int k=0; k<no_of_variables; k++)
                {
                    if(k==y)
                        table[c][k]=2;
                    else
                        table[c][k]=table[i][k];
                }
                c++;
                count2++;
            }
            count5=0;
        }
        count3++;
        if(count3==count1)
        {
            res[index2]=num_minterm;
            index2++;
            num_minterm=num_minterm+count2;
            x=0;
            count2=0;
        }
    }
    count5=0;
    for(int i=0; i<c; i++)
    {
        for(int j=i; j<c; j++)
        {
            for (int n=0; n<no_of_variables; n++)
            {
                if(table[i][n]==table[j][n]&&i!=j)
                    count5++;
            }
            if(count5==no_of_variables)
            {
                table[j][no_of_variables]=1;
            }
            count5=0;
        }

    }
    cout << "------------------\n";
    cout<<"The simplest form is: ";
    for(int i=0; i<c; i++)
    {

        int n=0;
        for(int j=0; j<no_of_variables; j++)
        {
            if(table[i][j]==2||table[i][no_of_variables]==1)
                cout << "",n++;
            else if (table[i][j]==1)
                cout << "X" << j <<" ";
            else
                cout << "X" <<j << "^ " ;
        }
        if(n!=no_of_variables && i!=c-1)
            cout <<"+" ;
    }
    return 0;
}
void tobinary(int a,int c)
{
    int k=c-1;
    int b=0;
    while(a!=0)
    {
        b=a%2;
        a=a/2;
        table[index][k]=b ;
        k--;
    }
    index++;
}
