pair<int, int> cntDigits(string s)
{

  int cnt = 0;
  bool start = false;
  int ans = 0;
  pair<int, int> p;
  bool updated = false;
  int from = -1;

  for (int i = 0; i < s.size(); i++)
  {
    int ass = (int)s[i];

    if (ass >= 48 && ass <= 57)
    {
      cnt++;

      if (!updated)
      {
        from = i;
        updated = true;
      }
      start = true;
    }

    else
    {
      if (start)
      {
        break;
      }
    }
  }
  return make_pair(from, cnt);
}