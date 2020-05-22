import timeit

def bubble_sort(our_list):
    # We go through the list as many times as there are elements
    for i in range(len(our_list)):
        # We want the last pair of adjacent elements to be (n-2, n-1)
        for j in range(len(our_list) - 1):
            if our_list[j] > our_list[j+1]:
                # Swap
                our_list[j], our_list[j+1] = our_list[j+1], our_list[j]


def bubble_sort_check_swapped(our_list):
    # We want to stop passing through the list
    # as soon as we pass through without swapping any elements
    has_swapped = True

    while(has_swapped):
        has_swapped = False
        for i in range(len(our_list) - 1):
            if our_list[i] > our_list[i+1]:
                # Swap
                our_list[i], our_list[i+1] = our_list[i+1], our_list[i]
                has_swapped = True


def bubble_sort_ignore_done(our_list):
    # With each consecutive iteration
    # we can look at one less element than before.
    # More precisely, in the k-th iteration,
    # only need to look at the first n - k + 1 elements.
    has_swapped = True

    num_of_iterations = 0

    while(has_swapped):
        has_swapped = False
        for i in range(len(our_list) - num_of_iterations - 1):
            if our_list[i] > our_list[i+1]:
                # Swap
                our_list[i], our_list[i+1] = our_list[i+1], our_list[i]
                has_swapped = True
        num_of_iterations += 1


# our_list = [19, 13, 6, 2, 18, 8]
print("bubble_sort:", timeit.timeit("bubble_sort([19, 13, 6, 2, 18, 8])", "from __main__ import bubble_sort", number=10000))
print("bubble_sort_check_swapped: ", timeit.timeit("bubble_sort_check_swapped([19, 13, 6, 2, 18, 8])", "from __main__ import bubble_sort_check_swapped", number=10000))
print("bubble_sort_ignore_done: ", timeit.timeit("bubble_sort_ignore_done([19, 13, 6, 2, 18, 8])", "from __main__ import bubble_sort_ignore_done", number=10000))