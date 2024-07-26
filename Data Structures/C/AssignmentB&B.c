#include <stdio.h>
#include <limits.h>

#define N 3

int cost_matrix[N][N] = {{10, 20, 30},
                          {15, 25, 35},
                          {25, 30, 40}};

int assigned[N][2] = {-1}; 
int min_assigned[N][2] = {-1}; // Initialize to -1

int min_cost = INT_MAX; // Initialize to maximum possible value
int bound = 0;

int costcal() {
    int cost = 0;
    for (int i = 0; i < N; i++) {
        cost += cost_matrix[assigned[i][0]][assigned[i][1]];
    }
    return cost;
}

void branch_bound(int depth) {
    if (depth == N) {
        int cost = costcal();
        if (cost < min_cost) {
            min_cost = cost;
            for (int i = 0; i < N; i++) {
                min_assigned[i][0] = assigned[i][0];
                min_assigned[i][1] = assigned[i][1];
            }
        }
        return;
    }

    for (int i = 0; i < N; i++) {
        if (assigned[i][0] == -1) {
            for (int j = 0; j < N; j++) {
                if (assigned[j][1] == -1) {
                    assigned[depth][0] = i;
                    assigned[depth][1] = j;
                    bound += cost_matrix[i][j];
                    if (bound < min_cost) {
                        branch_bound(depth + 1);
                    }
                    bound -= cost_matrix[i][j];
                    assigned[depth][0] = -1;
                    assigned[depth][1] = -1;
                }
            }
        }
    }
}

int main() {
    // Initialize assigned array to -1
    for (int i = 0; i < N; i++) {
        assigned[i][0] = -1;
        assigned[i][1] = -1;
    }
    
    branch_bound(0);

    printf("Minimum cost: %d\n", min_cost);
    printf("Assignments:\n");
    for (int i = 0; i < N; i++) {
        printf("%d %d\n", min_assigned[i][0], min_assigned[i][1]);
    }
    
    return 0;
}
