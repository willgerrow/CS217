#include <iostream>

using namespace std;


/*
 * Queue: implemented using array containint elements of type E 
 */
template <typename E> 
class Queue
{
private:
	E* A;	            // pointer to an array for storing stack elements
    int size;
    int front, rear;    // indices of front & rear elements of queue
    
public:
    Queue(int s);
    ~Queue();

    bool isFull();
    bool isEmpty();
    int queueCount();

    bool enqueue(E item);
    E dequeue();
    E peekFront();
    E peekRear();

};

// Constructor: create an empty stack with the specified size
template <typename E>
Queue<E>::Queue(int s)
{
    size = s;
    A = new E[size];
	front = rear = -1; // initialize both front & rear to -1; start w/ empty queue
}

template <typename E>
Queue<E>::~Queue()
{
    delete[] A;
}

// Return true if the queue is already full 
template <typename E>
bool Queue<E>::isFull()
{
    // your code goes here
    return((rear + 1) % size == front); // all slots in A are occupied by queue
}

// Return true if the queue is empty
template <typename E>
bool Queue<E>::isEmpty()
{
    // your code goes here
    return (front == -1);
}

// Return the number of items that are currently in the queue 
template <typename E>
int Queue<E>::queueCount()
{
    // your code goes here
    if (isEmpty())
        return 0;
    else
    {
        if (rear >= front) // we didn't wrap around in the array
            return rear - front + 1;
        else    
            return rear + 1 + (size - front);
    }
}

// Return true if the enqueue operation completes successfully
template <typename E>
bool Queue<E>::enqueue(E item)
{
    // your code goes here
    if (isFull())  // queue occupies all slots of array A
    {
        cout << "Queue is full; enqueue failed!" << endl;
        return false;
    }
    else
    {
        rear = (rear + 1) % size;
        A[rear] = item;
        if (front == -1) // queue empty before insertion
            front = rear;
        return true;
    }
}

// Remove item from the front and return it
template <typename E>
E Queue<E>::dequeue()
{
    // your code goes here
    if (isEmpty())
        throw std::runtime_error("Queue is empty; dequeue failed!");
    else
    {
        bool flag = false; // false: more than one element in queue before deletion
        if (front == rear) // one element in queue
            flag = true;

        E item = A[front]; // E is datatype we will specify later when we construct queue
        front = (front + 1) % size;

        if (flag)           // before deletion, queue contains only one element
            front = rear = -1; // after deletion, queue is empty

        return item;
    }

}

// Return the item at the front 
template <typename E>
E Queue<E>::peekFront()
{
    // your code goes here
}

// Return the item at the rear 
template <typename E>
E Queue<E>::peekRear()
{
    // your code goes here

}

void queueOperationsDemo()
{
    Queue<int> q(5);
    
    try
    {
        q.peekFront();
    }
    catch (const std::runtime_error& e) 
    {
        cout << e.what() << endl;
    }

    // insert 4 items: 10, 20, 30, 40
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    
    // remove 3 items: 10, 20, 30
    cout << "Removed: ";
    for (int i=1; i <= 3; i++)
    {
        int t = q.dequeue();
        cout << t << " ";
    }
    cout << endl;

    // insert 4 items: 50, 60, 70, 80
    q.enqueue(50);          // after 50 is inserted, wrap around!
    q.enqueue(60);          
    q.enqueue(70);
    q.enqueue(80);
    
    // access the items at front and rear ends of the queue
    cout << "Front item: " << q.peekFront() << endl;
    cout << "Rear item: " << q.peekRear() << endl;

    // remove all items from the queue and display them
    while(!q.isEmpty())
    {
        int t = q.dequeue();
        cout << t << " ";
    }
    cout << endl;
}

/**
 * 
 * Class to simulate traffic at a T-intersection
 * Assumptions: 
 * - The top segment of T is a two-way road with one lane in each direction
 * - The stem of the T is a one-way, single-lane road leading toward the intersection
 */
class TrafficSimulator
{
private:
    int duration;           // duration of the simulation
    
    //  With the specified probability, a car arrives at the intersection from the bottom part of T
    void hasCarArrivingBottomT(Queue<char>& q, float probability)
    {
        float r = ((float) rand()) / RAND_MAX;
        
        if (r <= probability)                                        // a car arrives from the bottom part of T
        {
            cout << "A car arrives " << endl;

            char car;
            
            r = ((float) rand()) / RAND_MAX;
            if (r <= 0.5)
                car = 'l';                                           // with probability 50%, the car will turn left 
            else
                car = 'r';                                            // with probability 50%, the car will turn right

            q.enqueue(car);                                           // enqueue the car
        }
    }

    /*
     * Return true if there is a car currently driving through the intersection 
     * along the top part of T, with the specified probability
     */
    bool hasCarDrivingTopT(float probability)
    {
        return (((float)rand()) / RAND_MAX <= probability);    
    }

public:

    // Constructor: specify the duration of simulation: number of time units (e.g., seconds)
    TrafficSimulator(int num)
    {
        duration = num;
    }

    // Simulate the cars waiting on the bottom part of T
    void simulateTraffic()
    {
        const float probCarArrives = 0.4;                                           // probability that there is a car arriving at the intersection from the bottom stem of T
        const float probLeft2Right = 0.65;                                           // probability that there is a car driving through the intersection from left to right on the top part of T 
        const float probRight2Left= 0.6;                                             // probability that there is a car driving through the intersection from right to left on the top part of T 
        
        Queue<char> carQueue(duration);                                              // use a queue to simulate the cars waiting on the bottom of T to make turns
        
        srand(time(0));                                                              // seed the random number generator
        for(int t = 1; t <= duration; t++)
        {
            char car;

            hasCarArrivingBottomT(carQueue, probCarArrives);                        // with a given probability (i.e., probCarArrives), a car arrives from the stem of T and is enqueued     
            cout << "Number of cars waiting: " << carQueue.queueCount() << endl;

            if (!carQueue.isEmpty())                                                // there are still some cars waiting to turn onto the top of T
            {
                switch (carQueue.peekFront())                                       // check the front car in the queue
                {
                    case 'r':                                                       // it wants to make a right turn
                        if (!hasCarDrivingTopT(probLeft2Right))                     // no car is coming from left on top of T
                        {
                            car = carQueue.dequeue();                               // turn right and leave the intersection
                            cout << "A car is turning right..." << endl;
                        }
                        break;
                    case 'l':                                                       // it wants to make a left turn
                        if (!hasCarDrivingTopT(probLeft2Right) && 
                            !hasCarDrivingTopT(probRight2Left))                     // no car in both directions on the top of T
                        {
                            car = carQueue.dequeue();                               // turn left and leave the intersection
                            cout << "A car is turning left..." << endl;
                        }
                        break;
                }
            }
        }

        cout << "Simulation ends." << endl;
        cout << "Number of cars still waiting: " << carQueue.queueCount() << endl;
    }
};

void trafficSimulationDemo()
{
    TrafficSimulator simulator(500);
    simulator.simulateTraffic();
}

int main()
{
	queueOperationsDemo();              // demonstrate basic operations of queues

    trafficSimulationDemo(); 

	return 0;
}

