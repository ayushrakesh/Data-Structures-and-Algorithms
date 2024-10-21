class Solution
{
public:
  int myAtoi(string s)
  {
    int n = s.size();
    string temp = "";
    int sign = 1;
    long long res = 0;

    for (int i = 0; i < n; i++)
    {
      while (s[i] == ' ')
      {
        i++;
      }
      if (s[i] == '-')
      {
        sign = -1;
        i++;
      }
      else if (s[i] == '+')
      {
        i++;
      }
      if (s[i] < '0' && s[i] > '9')
        return 0;
      else
      {
        while (s[i] >= '0' && s[i] <= '9')
        {
          res = 10 * res + (s[i] - 48);

          if (res > INT_MAX && sign == 1)
            return INT_MAX;
          if (res > INT_MAX && sign == -1)
            return INT_MIN;

          i++;
        }
        return res * sign;
        break;
      }
    }
    return res;
  }
};