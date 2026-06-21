#include <vector>
#include "task6.h"

int totalfishcost (int N, int K, std::vector<int>& fishcost) {
    int totalcost = 0;
    int window_start = 0;
    int window_end = 0;

    int mincost = 0;

    for (int i = 0; i < N; i++) {
        window_end = i;
        window_start = std::max(0, i - K + 1);

        mincost = fishcost[window_start];
        for (int j = window_start; j <= window_end; j++) {
            if (fishcost[j] <= mincost) {
                mincost = fishcost[j];
            }
        }

        totalcost += mincost;
    }

    return totalcost;
}