def heapify(arr, indices, n, i):
    largest = i
    l = 2 * i + 1
    r = 2 * i + 2
    if l < n and arr[i] < arr[l]:
        largest = l
    if r < n and arr[largest] < arr[r]:
        largest = r
    if largest != i:
        (arr[i], arr[largest]) = (arr[largest], arr[i])
        (indices[i], indices[largest]) = (indices[largest], indices[i])
        heapify(arr, indices, n, largest)


def heapSort(arr, indices):
    n = len(arr)
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, indices, n, i)
    for i in range(n - 1, 0, -1):
        (arr[i], arr[0]) = (arr[0], arr[i])
        (indices[i], indices[0]) = (indices[0], indices[i])
        heapify(arr, indices, i, 0)

t = int(input())
for _ in range(t):
    _ = input()
    times = list(map(int, input().strip().split()))
    indices = list()
    places = list()
    place = 1
    count = 1
    for i in range(len(times)):
        indices.append(i)

    heapSort(times, indices)

    for i in range(len(times)-1):
        if abs(times[i]-times[i+1]) <= 1:
            count += 1
            continue
        else:
            for _ in range(count):
                places.append(place)
            place += count
            count = 1
    for _ in range(count):
        places.append(place)

    heapSort(indices, places)
    for val in places:
        print(val, end='')
        print(' ', end='')
    print()
