//Implement interval scheduling algorithm. Given 𝒏 events with their starting and ending times, 
//find a schedule that includes as many events as possible. It is not possible to select an event 
//partially.

#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int start;
	int end;
}Interval;

int Interval_Scheduling(Interval intervals[], int n, Interval result[]){
	int i,j;
	for(i=0; i<n-1; i++){
		for(j=0; j<n-i-1; j++){
			if(intervals[j].end > intervals[j+1].end){
				Interval temp = intervals[j];
				intervals[j] = intervals[j+1];
				intervals[j+1] = temp;
			}
		}
	}
	int count = 0;
	int last_count_time = -1;
	for(i=0; i<n; i++){
		if(intervals[i].start >= last_count_time){
			result[count] = intervals[i];
			count++;
			last_count_time = intervals[i].end;
		}
	}
	
	return count;

}

int main(){
	Interval intervals[] = {{1,3}, {2,5}, {3,9}, {6,8}};
	int n = sizeof(intervals)/sizeof(intervals[0]);
	Interval results[n];
	int count = Interval_Scheduling(intervals, n, results);
	
	printf("Maximum Non Overlapping Intervals: \n");
	for(int i=0; i<count; i++){
		printf("[%d, %d]", results[i].start, results[i].end);
	}
	return 0;
}
