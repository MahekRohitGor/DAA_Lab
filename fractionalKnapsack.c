#include<stdio.h>
#include<stdlib.h>

struct Item{
	int value, weight;
};

int compare(const void *a, const void *b){
	struct Item *itemA = (struct Item *)a;
	struct Item *itemB = (struct Item *)b;
	double ratioA = (double)itemA->value / itemA->weight;
	double ratioB = (double)itemB->value / itemB->weight;
	
	if(ratioA < ratioB) return 1;
	if(ratioA > ratioB) return -1;
	
	return 0;
}

double FractionalKnapSack(int capacity, struct Item items[], int n){
	qsort(items, n, sizeof(struct Item), compare);
	
	int weight = 0;
	double value = 0.0;
	
	for(int i=0; i<n; i++){
		if(weight + items[i].weight <= capacity){
			weight += items[i].weight;
			value += items[i].value;
		}
		else{
			int remainingCapacity = capacity - weight;
			double fraction = (double)remainingCapacity / items[i].weight;
			weight += remainingCapacity;
			value += fraction * items[i].value;
			break;
		}
	}
	
	return value;
}

int main(){

	int n, capacity;
	
	printf("Enter number of items: ");
	scanf("%d", &n);
	
	struct Item items[n];
	for(int i=0; i<n; i++){
		printf("Enter value and weight for the item %d: ", i+1);
		scanf("%d %d", &items[i].value, &items[i].weight);
	}
	
	printf("Enter Capacity of Knapsack: ");
	scanf("%d", &capacity);
	
	double maxProfit = FractionalKnapSack(capacity, items, n);
	printf("Maximum Profit that can be earned is: %.2f\n", maxProfit);
	return 0;
}
