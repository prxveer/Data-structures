#include<iostream>
using namespace std;

class employee {
      public:
             int employee_number;
             char employee_name[20];
             float basic;
             float DA;
             float IT;
             float net_sal;
             float gross_sal;
      void employeedata()
      {    cout<<"enter employee number \t";
      cin>>employee_number;
      cout<<"enter employee name\t";
      cin>>employee_name;
      cout<<"enter basic salary\t";
      cin>>basic;
      }
       float gross()
       { DA=(12*basic)/100;
         gross_sal = basic + DA;
         return gross_sal;
       }
       float netsal()
        {IT = (18*gross_sal)/100;
         net_sal=gross_sal-IT;
         return net_sal;   
        }
};
      
int main(){
    int n,i;
    float nsal,gsal;
    employee a;
     a.employeedata();
      gsal=a.gross();
      cout<<"the gross salary is\t"<<gsal<<endl;
      nsal=a.netsal();
      cout<<"the net salary is\t"<<nsal;
    return 0;
    
}
    
    
