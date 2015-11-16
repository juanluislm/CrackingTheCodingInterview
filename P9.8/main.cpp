#include <iostream>

using namespace std;

int cents(int n, int money){
    int next_denom=0;
    switch(money){
        case 25:
            next_denom=10;
            break;
        case 10:
            next_denom=5;
            break;
        case 5:
            next_denom=1;
            break;
        case 1:
            return 1;
    }
    int ways=0;
    for(int i=0; i*money<=n; i++){
        ways+=cents(n-i * money, next_denom);
    }
    return ways;
}

int cents_representing_recursion(int n, int index, int coin, int **arr)
{
  if (n == 0)
    return 1;
  if (arr[n][index] != 0)
    return arr[n][index];
  int next_coin;
  switch (coin)
  {
  case 25:
    next_coin = 10;
    break;
  case 10:
    next_coin = 5;
    break;
  case 5:
    next_coin = 1;
    break;
  case 1:
    return 1;
    break;
  default:
    break;
  }
  int ways = 0;
  for (int i = 0; i * coin <= n; ++i)
    ways += cents_representing_recursion(n - i * coin, index + 1, next_coin, arr);
  arr[n][index] = ways;
  return arr[n][index];
}

int cents_representing(int n)
{
  if (n <= 0)
    return 0;
  int **arr = new int *[n + 1];
  for (int i = 0; i < n + 1; ++i)
    arr[i] = new int[4];
  int result = cents_representing_recursion(n, 0, 25, arr);
  for (int i = 0; i < n + 1; ++i)
    delete []arr[i];
  delete []arr;
  arr = NULL;
  return result;
}

int main()
{
    cout << cents(25,27) << endl;
    //cout<< cents_representing(26)<<endl;
    return 0;
}
