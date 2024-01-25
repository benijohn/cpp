from cython cimport view

def sum_array(int[:] view):
    cdef int total = 0
    for i in range(view.shape[0]):
        total += view[i]

    return total    