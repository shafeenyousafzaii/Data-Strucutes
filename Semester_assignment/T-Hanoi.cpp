void moveDisks(Stack& src, Stack& dest)
{
    int disk1 = peak();
    int disk2 = dest.peak();

    if (disk1 == -1)
    {
        int p = dest.pop();
        push(p);
    }
    else if (disk2 == -1)
    {
        int p = pop();
        dest.push(p);
    }
    else if (disk1 > disk2)
    {
        int p = dest.pop();
        push(p);
    }
    else
    {
        int p = pop();
        dest.push(p);
    }
}

void harnoi(int n, Stack& s1, Stack& s2, Stack& s3)
{
    Stack *dest;
    Stack *aux;

    if(n % 2 == 0)
    {
        dest = &s2;
        aux = &s3;
    }
    else
    {
        dest = &s3;
        aux = &s2;
    }

    int totalMoves = pow(2, n) - 1;

    for(int i = n; i >= 1; i--)
    {
        s1.push(i);
    }

    for(int i = 1; i <= totalMoves; i++)
    {
        if(i % 3 == 1)
            moveDisks(s1, *dest);
        else if(i % 3 == 2)
            moveDisks(s1, *aux);
        else if(i % 3 == 0)
            moveDisks(*aux, *dest);
    }
}