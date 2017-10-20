namespace engine
{
    int intPow(int b, int e) {
        if (p == 0) return 1;
        if (p == 1) return x;
        return x * myPow(x, p-1);
    }

    int sum(int n)
    {
        return n*(n + 1)/2;
    }
}