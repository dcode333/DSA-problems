
     int sumStoreIndex = 0;
     for (int i = 0; i < len; i++)
     {

        if (arr[i] < 0)
        {
            sumStore[sumStoreIndex] = summer;
            sumStoreIndex++;
            summer = 0;
        }
        else
        {
            summer += arr[i];
            cout << summer << endl;
        }

        if (i == len - 1 && i > 0)
            sumStore[sumStoreIndex] = summer;
    }

    for (int i = 0; i < len; i++)
        MaxSum = max(MaxSum, sumStore[i]);