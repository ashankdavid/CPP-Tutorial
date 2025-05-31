#include <iostream>
#include <vector>
#include <algorithm>

struct CargoItem {
    int weight;
    int profit;
};

bool compareItems(const CargoItem &a, const CargoItem &b) {
    return (a.profit * b.weight) > (b.profit * a.weight);
}

int maximizeProfit(std::vector<CargoItem> &cargoItems, int capacity) {
    std::sort(cargoItems.begin(), cargoItems.end(), compareItems);

    int totalProfit = 0;
    int currentWeight = 0;

    for (const CargoItem &item : cargoItems) {
        if (currentWeight + item.weight <= capacity) {
            totalProfit += item.profit;
            currentWeight += item.weight;
        } else {
            int remainingCapacity = capacity - currentWeight;
            totalProfit += static_cast<int>(item.profit * (static_cast<double>(remainingCapacity) / item.weight));
            break;
        }
    }

    return totalProfit;
}

int main() {
    std::vector<CargoItem> cargoItems = {{15, 120}, {25, 200}, {30, 150}, {10, 60}};
    int capacity = 50;

    int maxProfit = maximizeProfit(cargoItems, capacity);

    std::cout << "Maximum Profit: " << maxProfit << std::endl;

    return 0;
}
