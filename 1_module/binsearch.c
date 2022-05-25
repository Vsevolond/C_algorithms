
unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i)) {
    unsigned long l = 0, r = nel - 1;
    unsigned long m = (l + r) / 2;
    while (l <= r && compare(m) != 0) {
        if (compare(m) < 0) {
            l = m + 1;
            m = (l + r) / 2;
        } else {
            r = m - 1;
            m = (l + r) / 2;
        }
    }
    if (compare(m) == 0) return m;
    else return nel;
}

