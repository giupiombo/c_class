// linked list
struct node {
    int process;
    int priority;
    int burst_time;
    int waiting;
    int turnaround;
    struct node* next;
};