//MINHEAP
#include <iostream>
#include <array>
using namespace std;

struct Plane{
    string flightNumber;
    int waitTime;
};

class MinHeap{
    private:
        int heapSize, capacity;

    public: 
        Plane* planeList; //point to the array

        //constructor
        MinHeap(int cap){
            this->heapSize = 0;
            this->capacity = cap;
            planeList = new Plane[cap];
        }

        ~MinHeap(){
            delete[] planeList;
        }

        //Get the location of parents and children of specified
        int parent(int i){
            return (i - 1)/2;
        }

        int leftChild(int i){
            return (2 * i) + 1; 
        }

        int rightChild(int i){
            return (2 * i) + 2;       
        }

        //Min_Heapify when plane has landed
        void heapify(int i){
            int root = i;
            int left = leftChild(i);
            int right = rightChild(i);

            if (left < heapSize && planeList[left].waitTime < planeList[i].waitTime){
                root = left;
            }
            if (right < heapSize && planeList[right].waitTime < planeList[root].waitTime){
                root = right;
            }
            if (root != i) {
                swap(planeList[i], planeList[root]);
                heapify(root);
            }
        }

        //delete MinKey (root)
        void planeLand(){
            if(heapSize == 0){
                cout << "There are no planes waiting.\n";
            }
            else if (heapSize == 1){
                cout << "Flight number: " << planeList[0].flightNumber << " landed.\n";
                heapSize--;
            }
            else{ 
                cout << "Flight number: " << planeList[0].flightNumber << " landed.\n";
                swap(planeList[heapSize - 1], planeList[0]);
                heapSize--;
                heapify(0);
            }
        }

        //insert key
        void planeDetected(int time, string name){
            if(heapSize == capacity){
                cout << "Can no longer add new plane\n";
            }
            else{
                //insert at tail of heap
                int i = heapSize; 
                planeList[i].waitTime = time; 
                planeList[i].flightNumber = name;

                while(i != 0 && (planeList[parent(i)].waitTime > planeList[i].waitTime)){
                    swap(planeList[parent(i)], planeList[i]);
                    i = parent(i); //keep following the inserted wait time
                }
                heapSize++; //keep track of availability (conditional if)
            }
        }

        void printArray(){
            if(heapSize == 0){
                cout << "There are no planes waiting.\n";
            }
            for(int i = 0; i < heapSize; i++){
                cout << "[" << planeList[i].flightNumber << ", " << planeList[i].waitTime << "] ";
            }
        }
};

int menu(){
    int option;
    cout << "\n\nWelcome to the Plane Landing System\n";
    cout << "Select your option\n";
    cout << "1. Make a landing request\n";
    cout << "2. Land a Plane\n";
    cout << "3. List all the landing requests\n";
    cout << "4. Exit\n";
    cin >> option;

    return option;
}

// Driver code
int main()
{
    //Let's say there are 16 landing zones
    MinHeap planeList(16);

    int menuSelect;

    int waitTime;
    string flightNumber;

    do{
        menuSelect = menu();
        switch(menuSelect) {
            case 1:{
                cout << "Enter the flight number: ";
                cin >> flightNumber;
                cout << "Enter the wait time: ";
                cin >> waitTime;
                planeList.planeDetected(waitTime, flightNumber);
                break;
            }
            case 2:{
                planeList.planeLand();
                break;
            }
            case 3:{
                planeList.printArray();
                break;
            }
            case 4:{
                return 0;
                break;
            }
            default:{
                cout << "Invalid response. Resubmit selection.\n\n";
                menu();
                break;
            } 
        }
    }while(menuSelect != 4);

    return 0;
}