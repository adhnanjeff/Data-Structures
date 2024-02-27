def knapsack_greedy(values, weights, capacity):
    n = len(values)
    values_per_weight = [(values[i] / weights[i], i) for i in range(n)]  
    values_per_weight.sort(reverse=True)
    total_values = 0
    total_weight = 0
    selected_items = []
    
    for ratio, index in values_per_weight:  
        if total_weight + weights[index] <= capacity:
            total_weight += weights[index]
            total_values += values[index]
            selected_items.append(index)
    
    return total_values, selected_items 

values = [60, 100, 120]
weights = [10, 20, 30]
capacity = 50
max_values, selected_items = knapsack_greedy(values, weights, capacity)

print("Maximum value that can be achieved:", max_values)  
print(f"Selected items: {selected_items}")
