#include <stdio.h>

struct Process {
    int id;
    int burst_time;
    int completed;
};

void sjn_scheduling(struct Process processes[], int n) {
    int completed_count = 0, current_time = 0;

    while (completed_count < n) {
        int min_index = -1;
        for (int i = 0; i < n; i++) {
            if (!processes[i].completed && (min_index == -1 || processes[i].burst_time < processes[min_index].burst_time)) {
                min_index = i;
            }
        }
        
        if (min_index != -1) {
            current_time += processes[min_index].burst_time;
            processes[min_index].completed = 1;
            printf("Process %d executed at time %d\n", processes[min_index].id, current_time);
            completed_count++;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    struct Process processes[n];
    
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].completed = 0;
    }
    
    sjn_scheduling(processes, n);
    
    return 0;
}

