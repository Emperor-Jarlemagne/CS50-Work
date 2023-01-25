int collatz(int n)
{
    //Base Case
    if (n == 1)
        return 0;
    //Even Numbers
    else if ((n % 2) == 0)
        return 1 + collatz(n / 2);
    //Odd Numbers
    else
        return 1 + collatz(3 * n + 1);
}
