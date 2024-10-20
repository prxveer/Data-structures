#include <iostream>
using namespace std;
int main()
{ string a,b,c;
   int i=0,n=0;
   cout<<"enter a string ";
   cin>>a;
   cout<<"enter another string ";
   cin>>b;
   for(i=0;a[i]!='\0';i++)
   { c[n]=a[i];
   n++;
   }
   for(i=0;b[i]!='\0';i++)
   { c[n]=b[i];
   n++;
   }
   c[n]='\0';
   cout<<"new string is ";
   for(i=0;i<n;i++)
   { cout<<c[i];
   }
 
}
