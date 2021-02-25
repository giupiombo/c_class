/* Author: Giulia Piombo
 * Date: February 24th, 2021
 * Specifications: Create a schedule from tasks sorting them in priority order
 */

#include <stdio.h>
#include "schedule.h"

int main(void) {

    // enter number of tasks
    int num_data;

    printf("How many tasks do you want to enter? ");
    scanf("%d", &num_data);

    // array
    struct node nodes[num_data];

    // input data
    for(int i = 0; i < num_data; i++) {
        printf("\nEnter details for task %d:\n", i+1);
        printf("Process: ");
        scanf("%d",&nodes[i].process);
        printf("Priority: ");
        scanf("%d",&nodes[i].priority);
        printf("Burst Time: ");
        scanf("%d",&nodes[i].burst_time);
    }

    // sorting priority
    int temp, position;

    for(int i = 0; i < num_data; i++) {

        position = i;

        // checking which task has a higher priority
        for (int j = i + 1; j < num_data; j++) {
            if (nodes[j].priority < nodes[position].priority){
                position = j;
            }
        }

        // changing values
        temp = nodes[i].priority;
        nodes[i].priority = nodes[position].priority;
        nodes[position].priority = temp;

        temp = nodes[i].process;
        nodes[i].process = nodes[position].process;
        nodes[position].process = temp;

        temp = nodes[i].burst_time;
        nodes[i].burst_time = nodes[position].burst_time;
        nodes[position].burst_time = temp;
    }

    // waiting time for the first task
    nodes[0].waiting = 0;

    // total waiting time
    int total_waiting = 0;

    // calculating waiting time for the other tasks
    for(int i = 1; i < num_data; i++) {

        nodes[i].waiting = 0;

        for(int j = 0; j < i; j++) {
            nodes[i].waiting += nodes[j].burst_time;
        }

        // calculating total waiting time
        total_waiting += nodes[i].waiting;
    }

    // average of waiting time
    int avg_waiting;
    avg_waiting = total_waiting/num_data;

    // calculating turnaround time
    int total_turnaround = 0;

    for (int i = 0; i < num_data; i++) {

        nodes[i].turnaround = nodes[i].burst_time + nodes[i].waiting;

        // calculating total turnaround time
        total_turnaround += nodes[i].turnaround;
    }

    // average of turnaround time
    int avg_turnaround;
    avg_turnaround = total_turnaround/num_data;

    // print data for the schedule
    printf("\n**********************SCHEDULE**********************\n");
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i = 0; i < num_data; i++) {
        printf("  P[%d]\t\t%d\t\t\t%d\t\t\t\t %d\n",nodes[i].process, nodes[i].burst_time, nodes[i].waiting, nodes[i].turnaround);
    }

    // print data for average waiting and turnaound time
    printf("\nAverage waiting time = %d", avg_waiting);
    printf("\nAverage turnaound time = %d", avg_turnaround);

    return 0;
}