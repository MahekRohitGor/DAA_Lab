// Your friends are starting a security company that needs to obtain licenses for 𝑛 different 
//pieces of cryptographic software. Due to regulations, they can only obtain these licenses 
//at the rate of at most one per month. Each license is currently selling for a price of $100. 
//However, they are all becoming more expensive according to exponential growth 
//curves: in particular, the cost of license 𝑗 increases by a factor of 𝑟𝑗 > 1 each month, 
//where 𝑟𝑗 is a given parameter. This means that if license 𝑗 is purchased 𝑡 months from
//now, it will cost 100 𝑟 𝑡 𝑗. We will assume that all the price growth rates are distinct; 
//that is, 𝑟𝑖 ≠ 𝑟𝑗 for licenses 𝑖 ≠ 𝑗 (even though they start at the sameprice of $100).
//The question is: Given that the company can only buy at most one license a month, in 
//which order should it buy the licenses so that the total amount of money it spends is as 
//small as possible?
//Give an algorithm that takes the 𝑛 rates of price growth 𝑟1, 𝑟2, . . . , 𝑟𝑛, and computes an 
//order in which to buy the licenses so that the total amount ofmoney spent is minimized. 
//The running time of your algorithm should be polynomial in 𝑛.

#include <stdio.h>
#include <stdlib.h>

// A struct to represent a license
typedef struct {
    int index;
    double rate;
} License;

// Compute the minimum cost and print the order in which the licenses should be bought
void compute_minimum_cost(License* licenses, int n) {
    double total_cost = 0.0;
    for (int i = 0; i < n; i++) {
        int max_index = i;
        double max_rate = licenses[i].rate;
        for (int j = i + 1; j < n; j++) {
            if (licenses[j].rate > max_rate) {
                max_index = j;
                max_rate = licenses[j].rate;
            }
        }
        License temp = licenses[i];
        licenses[i] = licenses[max_index];
        licenses[max_index] = temp;
        int index = licenses[i].index;
        double rate = licenses[i].rate;
        double cost = 100.0 * rate;
        printf("Buy license %d with growth rate %f for $%f\n", index, rate, cost);
        total_cost += cost;
    }
    printf("Total cost: $%f\n", total_cost);
}

int main() {
    int n = 5;
    double rates[] = { 1.1, 1.3, 1.4, 1.5, 1.2 };

    // Create an array of licenses and initialize it with the growth rates and indices
    License licenses[n];
    for (int i = 0; i < n; i++) {
        licenses[i].index = i;
        licenses[i].rate = rates[i];
    }

    // Sort the licenses in descending order of their growth rate using selection sort
    for (int i = 0; i < n - 1; i++) {
        int max_index = i;
        double max_rate = licenses[i].rate;
        for (int j = i + 1; j < n; j++) {
            if (licenses[j].rate > max_rate) {
                max_index = j;
                max_rate = licenses[j].rate;
            }
        }
        License temp = licenses[i];
        licenses[i] = licenses[max_index];
        licenses[max_index] = temp;
    }

    // Compute the minimum cost and print the order in which the licenses should be bought
    compute_minimum_cost(licenses, n);

    return 0;
}
