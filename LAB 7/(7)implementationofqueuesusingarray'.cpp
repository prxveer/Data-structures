#include<iostream>
using namespace std;
class Queue{
		int* arr;
		int size;
		int qfront;
		int rear;
	public:
	Queue(){
		size=1001;
		arr=new int[size];
	qfront=0; 
		rear=0;
	}
	void enque(int ele){
		if(rear==size){
			cout<<"Can't Enque because Queue is full"<<endl;
		}
		else{
			arr[rear]=ele;
			rear++;
		}
	
	}
	int deque(){
		if(qfront==rear){
			return -1;
		}
		else{
			int ans =arr[qfront];
			arr[qfront]=-1;
			qfront++;
			if(qfront==rear){
				qfront=0;
				rear=0;
			}
			return ans;
		}
	}
	bool isEmpty(){
		if(qfront==rear){
			return true;
		}
		else{
			return false;
		}
	}
	void  front(){
		if( qfront!=rear){
			cout<<arr[ qfront]<<endl;
		}
		else{
			cout<<"Queue is empty"<<endl;
		}
	}
	void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Queue elements: ";
            for (int i = qfront; i < rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main(){ 

	Queue q;
	q.enque(5);
	q.enque(4);
	q.enque(3);
	q.enque(2);
	q.enque(1);
	q.display();
	q.front();
	q.deque();
	q.front();
	q.deque();
	q.front();
	
}
