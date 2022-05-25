
unsigned long peak(unsigned long nel,
                   int (*less)(unsigned long i, unsigned long j)) {
    if (nel == 1) return 0;
    int last = 1;
    for (int i = 1; i < nel; i++) {
        if (less(i - 1, i) == 0 && last == 1) return i - 1;
        else if (i == nel - 1 && less(i - 1, i) == 1) return i;
        last = less(i - 1, i);
    }
}


