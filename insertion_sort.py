#Python program for implementation of Insertion Sort 
filename = 'data1000.txt'  
# Function to do insertion sort 
def insertionSort(arr): 
  
    # Traverse through 1 to len(arr) 
    for i in range(1, len(arr)): 
  
        key = arr[i] 
  
        # Move elements of arr[0..i-1], that are 
        # greater than key, to one position ahead 
        # of their current position 
        j = i-1
        while j >= 0 and key < arr[j] : 
                arr[j + 1] = arr[j] 
                j -= 1
        arr[j + 1] = key 
  
  
# Driver code to test above 
import time
start_time = time.time()

f = open(filename,'r')
data = f.read()
arr = [int(i) for i in data.split()]

insertionSort(arr) 

print("Execution time = %s seconds" % (time.time() - start_time))
