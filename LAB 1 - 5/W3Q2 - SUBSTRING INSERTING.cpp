#include <iostream>
using namespace std;
int main()
{ string a,b,c;
   int i=0,n=0,m,j=0,k;
   cout<<"enter a string ";
   cin>>a;
   cout<<"enter substring ";
   cin>>b;
   cout<<"enter index of adding substring ";
   cin>>k;
   
    while(a[n]!=0)
   n++;
   while(b[m]!=0)
   m++;
   
   for(i=0;i<k;i++)  
     {c[j]=a[i];
     j++;
     }
   for(i=0;i<=m;i++)
   {c[j]=b[i];
   j++;
   }
   for(i=k;i<n;i++)
   {c[j]=a[i];
   j++;
   }
  c[j]='\0';
   cout<<"new string is ";
   for(i=0;i<j;i++)
   { 
     cout<<c[i];
   }
}
