
def partition(array, low, high):
	pivot = array[high]
	i = low - 1
	for j in range(low, high):
		if array[j] <= pivot:
			i = i + 1
			(array[i], array[j]) = (array[j], array[i])
	(array[i + 1], array[high]) = (array[high], array[i + 1])
	return i + 1

def quicksort(array, low, high):
	if low < high:
		pi = partition(array, low, high)
		quicksort(array, low, pi - 1)
		quicksort(array, pi + 1, high)

if __name__ == '__main__':
	array=[]
	n=int(input("Enter no. of students:"))
	for i in range(n):
		array.append(int(input()))
	N = len(array)
	quicksort(array, 0, N - 1)
	print('Top 5 Percentages: ')
	j=N
	array1=[]
	for i in range(N):
		array1.append(array[j-1])
		j=j-1
	for i in range(5):
		print(array1[i])


