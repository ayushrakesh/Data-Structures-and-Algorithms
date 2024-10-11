def server_allocation(server_city_matrix, capacity, user_request):
    result_dict = {}
    
    while server_city_matrix:
#Find the minimum value and its indices
        min_value = float('inf')
        min_row, min_col = -1, -1
        for i, row in enumerate(server_city_matrix):
            for j, value in enumerate(row):
                if value < min_value:
                    min_value = value
                    min_row, min_col = i, j

#Get the corresponding capacity and user request
        server_capacity = capacity[min_row]
        city_request = user_request[min_col]

#Calculate the allocation
        allocation = min(server_capacity, city_request)

#Store the result
        result_dict[min_value] = allocation

#Update capacity and user request
        capacity[min_row] -= allocation
        user_request[min_col] -= allocation

#Remove row or column if capacity or request becomes 0
        if capacity[min_row] == 0:
            server_city_matrix.pop(min_row)
            capacity.pop(min_row)
        elif user_request[min_col] == 0:
            for row in server_city_matrix:
                row.pop(min_col)
            user_request.pop(min_col)
        else:
#If neither becomes 0, we still need to remove the used cell
            server_city_matrix[min_row][min_col] = float('inf')  # Set to infinity to ignore in future iterations

#If any row becomes empty, remove it
        server_city_matrix = [row for row in server_city_matrix if row]
    
    return result_dict

#Example usage
server_city_matrix = [[10, 2, 20, 11], [12, 7, 9, 20], [4, 14, 16, 18]]
capacity = [25, 25, 30]
user_request = [10, 25, 25, 20]

result = server_allocation(server_city_matrix, capacity, user_request)
print(result)