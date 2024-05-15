// 1
int n, i, v[101];
int main()
{
  cin >> n;
  for (i = 1; i <= n; i++)
    cin >> v[i];
  for (i = 2; i <= n; i++)
    while (v[1] != v[i])
      if (v[1] > v[i])
        v[1] = v[1] - v[i];
      else
        v[i] = v[i] - v[1];
  cout << v[1];
}
// 2
int n, i, a, b, c, ok = 0, dreptunghic, isoscel, oarecare, echilateral;
int main()
{
  cin >> n;
  for (i = 1; i <= n; i++)
  {
    cin >> a >> b >> c;
    if (a > 0 && b > 0 && c > 0 && a + b > c && b + c > a && a + c > b)
    {
      ok = 1;
      if (a == b && b == c)
        echilateral++;
      else if (a * a == b * b + c * c || b * b == a * a + c * c || c * c == a * a + b * b)
      {
        dreptunghic++;
        if (a == b || a == c || b == c)
          isoscel++;
      }
      else if (a == b || a == c || b == c)
        isoscel++;
      else
        oarecare++;
    }
  }
  if (ok == 0)
    cout << "NU EXISTA TRIUNGHIURI";
  else
  {
    if (isoscel)
      cout << isoscel << " triunghi isoscel" << endl;
    if (oarecare)
      cout << oarecare << " triunghi oarecare" << endl;
    if (echilateral)
      cout << echilateral << " triunghi echilateral" << endl;
    if (dreptunghic)
      cout << dreptunghic << " triunghi dreptunghic" << endl;
  }
}

// 3

float ma1, ma2;
int x;
int prim(int x)
{
  int numarDivizori = 0;
  for (int d = 1; d <= x; d++)
    if (x % d == 0)
    {
      numarDivizori++;
    }
  if (numarDivizori == 2)
    return 1;
  else
    return 0;
}
int main()
{
  int k = 0, u = 0;
  while (cin >> x)
  {
    if (x == 0)
      break;
    else if (prim(x) == 1)
    {
      ma1 = ma1 + x;
      k++;
    }
    else
    {
      ma2 = ma2 + x;
      u++;
    }
  }
  if (k == 0)
    cout << 0;
  else
    cout << ma1 / k;
  cout << endl;
  if (u == 0)
    cout << 0;
  else
    cout << ma2 / u;
}

// 4

int a, b, n, c, ok, nr, s, i;
int main()
{
  cin >> a >> b;
  cin >> n;
  for (i = 1; i <= n; i++)
  {
    cin >> c;
    s = 0;
    ok = 1;
    while (c > 0 && ok == 1)
    {
      s = s + c % 10;
      if (s >= b)
        ok = 0;
      c = c / 10;
    }
    if (s <= a)
      ok = 0;
    if (ok == 1)
      nr++;
  }
  if (nr == 0)
    cout << "NU EXISTA";
  else
    cout << nr;
}

// 5

int n;
float divizori(int x)
{
  float a = 0, b = 0, c;
  for (int d = 1; d <= x; d++)
    if (x % d == 0 && d % 2 == 0)
    {
      a = a + d;
      b = b + 1;
    }
  if (b == 0)
    return 0;
  c = a / b;
  return c;
}
int main()
{
  cin >> n;
  while (n != 0)
  {
    cout << divizori(n) << " ";
    cin >> n;
  }
}

// 6

int SumaNr, NrDeNr, n, x, suma;
int main()
{
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> x;
    suma = 0;
    for (int j = 1; j <= x / 2; j++)
    {
      if (x % j == 0)
        suma = suma + j;
    }
    if (suma == x)
    {
      NrDeNr++;
      SumaNr = SumaNr + x;
    }
  }
  if (NrDeNr)
    cout << SumaNr / NrDeNr;
  else
    cout << "NU EXISTA";
}

// 7

int n, x, a, b, MIN, MAX, k;
int main()
{
  cin >> n;
  while (n != 0)
  {
    cin >> x;
    k = 0;
    MIN = 10;
    MAX = 0;
    if (x == 0)
      k = 1;
    while (x != 0)
    {
      k++;
      if (x % 10 < MIN)
      {
        MIN = x % 10;
        a = 1;
      }
      else if (x % 10 == MIN)
        a++;
      if (x % 10 > MAX)
      {
        MAX = x % 10;
        b = 1;
      }
      else if (x % 10 == MAX)
        b++;
      x = x / 10;
    }
    if (k == a)
      cout << "CIFRE EGALE";
    else
      cout << "cifra maxima " << MAX << " numar de aparitii " << b << " cifra minima " << MIN << " numar de aparitii " << a;
    cout << endl;
    n--;
  }
}

// 8

int main()
{
  int n, x;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> x;
    int contor = 0;
    int p = x;
    while (x)
    {
      x = x / 2;
      contor++;
    }
    cout << p << " " << contor << " cifre binare" << endl;
  }
}

// 9

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int n;
void factor_prim_minim_putere(int numar, ofstream &g)
{
  int factor_prim_minim = 2;
  int putere;
  while (numar > 1))
    {
      if (numar % factor_prim_minim == 0)
      {
        putere = 0;
        while (numar % factor_prim_minim == 0)
        {
          putere++;
          numar /= factor_prim_minim;
        }
        g << factor_prim_minim << " " << putere << endl;
        break;
      }
      factor_prim_minim++;
    }
}
int main()
{
  ifstream f("atestat.in");
  ofstream g("factor.out");
  while (f >> n)
  {
    factor_prim_minim_putere(n, g);
  }
  f.close();
  g.close();
}

// 10

#include <iostream>
#include <fstream>
using namespace std;
int n, i, a, c, x;
float s, y;
ifstream f("Atestat.in");
ofstream g("Palindrom.out");
int main()
{
  f >> n;
  for (i = 1; i <= n; i++)
  {
    f >> a;
    c = a;
    x = 0;
    while (c != 0)
    {
      x = x * 10 + c % 10;
      c = c / 10;
    }
    if (x == a)
    {
      s = s + a;
      y = y + 1;
    }
  }
  if (y != 0)
    g << s / y;
  else
    g << "NU EXISTA";
  g.close();
}

// 11

int v[101];
int main()
{
  int n, i;
  cin >> n;
  for (i = 1; i <= n; i++)
    cin >> v[i];
  for (i = 1; i <= n / 2; i++)
    cout << v[i] << "" << v[n + 1 - i] << "";
  if (n % 2 == 1)
    cout << v[n / 2 + 1];
}

// 12

int n, v[101], minim, maxim, sum, k, x, i;
int main()
{
  cin >> n;
  for (i = 1; i <= n; i++)
    cin >> v[i];
  minim = v[1];
  maxim = v[1];
  for (i = 2; i <= n; i++)
    if (minim > v[i])
      minim = v[i];
    else if (maxim < v[i])
      maxim = v[i];
  sum = minim + maxim;
  for (i = 1; i <= n; i++)
    if (v[i] == sum)
      k++;
  if (k != 0)
    cout << k;
  else
    cout << "Nu exista";
}

// 13

#include <iostream>
#include <fstream>
using namespace std;
int estePrim(int num)
{
  if (num <= 1)
  {
    return false;
  }
  for (int i = 2; i * i <= num; i++)
  {
    if (num % i == 0)
    {
      return false;
    }
  }
  return true;
}
int main()
{
  int n;
  ifstream fin("vector.in");
  ofstream fout("vector.out");

  fin >> n;

  int arePrim = false;
  for (int i = 0; i < n; i++)
  {
    int element;
    fin >> element;
    if (estePrim(element))
    {
      arePrim = true;
      break;
    }
  }

  if (arePrim)
  {
    fout << "DA";
  }
  else
  {
    fout << "NU";
  }
}

// 14

int v[101], n, i, j;
int main()
{
  cin >> n;
  for (i = 1; i <= n; i++)
    cin >> v[i];
  for (i = 1; i <= n; i++)
    if (v[i] % 2 == 0)
    {
      for (j = i; j < n; j++)
        v[j] = v[j + 1];
      n--;
      i--;
    }
  for (i = 1; i <= n; i++)
    cout << v[i] << " ";
}

// 15

#include <iostream>
#include <fstream>
using namespace std;
ofstream g("vector.out");
int v[101], n, k, i, o, aux;
int main()
{
  cin >> n >> k;
  for (i = 1; i <= n; i++)
    cin >> v[i];
  while (o == 0)
  {
    o = 1;
    for (i = 1; i < k; i++)
      if (v[i] > v[i + 1])
      {
        aux = v[i];
        v[i] = v[i + 1];
        v[i + 1] = aux;
        o = 0;
      }
  }
  o = 0;
  while (o == 0)
  {
    o = 1;
    for (i = k + 1; i < n; i++)
      if (v[i] < v[i + 1])
      {
        aux = v[i];
        v[i] = v[i + 1];
        v[i + 1] = aux;
        o = 0;
      }
  }
  for (i = 1; i <= n; i++)
    g << v[i] << ' ';
  g.close();
}

// 16

int i, n, k, a[101], j;
int main()
{
  cin >> x >> n;
  for (i = 1; i <= n; i++)
    cin >> a[i];
  for (i = 1; i <= n; i++)
       if(a[i)%2==0)
         {
           n++;
           for (j = n; j > i; j--)
             a[j] = a[j - 1];
           i++;
           a[i] = x;
         }
  for (i = 1; i <= n; i++)
    cout << a[i];
}

// 17

int v[101], n, a, b, s;
int main()
{
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> v[i];
  }
  for (int i = 1; i <= n; i++)
  {
    if (v[i] % 2 == 0)
    {
      a = i;
      break;
    }
  }
  for (int i = n; i >= 1; i--)
  {
    if (v[i] % 2 == 0)
    {
      b = i;
      break;
    }
  }
  for (int i = a; i <= b; i++)
  {
    s += v[i];
  }
  cout << s;
}

// 18

#include <iostream>
using namespace std;
int n, i, v[11];
int main()
{
  cin >> n;
  while (n)
  {
    v[n % 10]++;
    n = n / 10;
  }
  for (i = 0; i <= 9; i++)
    if (v[i] > 1)
    {
      cout << "NU";
      return 0;
    }
  cout << "DA";
}

// 19

#include <iostream>
#include <fstream>
using namespace std;
ofstream fout("vector.out");
int main()
{
  int x[101], y[101], z[101], n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> x[i];
  for (int i = 1; i <= n; i++)
    cin >> y[i];
  for (int i = 1; i <= n; i++)
    z[i] = 2 * x[i] + y[i] * y[i];
  for (int i = 1; i <= n; i++)
    fout << z[i] << " ";
}

// 20

int main()
{
  int n, v[101], i, Max, poz, b, pas, aux;
  cin >> n;
  for (i = 1; i <= n; i++)
    cin >> v[i];
  Max = v[1];
  poz = 1;
  for (i = 2; i <= n; i++)
    if (v[i] > Max)
    {
      Max = v[i];
      poz = i;
    }

  b = 0;
  pas = 1;
  while (b == 0)
  {
    b = 1;
    for (i = 1; i <= poz - pas; i++)
      if (v[i] > v[i + 1])
      {
        aux = v[i];
        v[i] = v[i + 1];
        v[i + 1] = aux;
        b = 0;
      }
    pas++;
  }

  b = 0;
  pas = 1;
  while (b == 0)
  {
    b = 1;
    for (i = poz + 1; i <= n - pas; i++)
      if (v[i] < v[i + 1])
      {
        aux = v[i];
        v[i] = v[i + 1];
        v[i + 1] = aux;
        b = 0;
      }
    pas++;
  }
  for (i = 1; i <= n; i++)
    cout << v[i] << " ";
}

// 21

#include <iostream>
#include <fstream>
using namespace std;
ofstream g("matrice.out");
int n, m, i, j, v[101][101], aux, ok;
int main()
{
  cin >> n >> m;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      cin >> v[i][j];
  while (ok == 0)
  {
    ok = 1;
    for (j = 1; j < m; j++)
      if (v[1][j] > v[1][j + 1])
      {
        aux = v[1][j];
        v[1][j] = v[1][j + 1];
        v[1][j + 1] = aux;
        ok = 0;
      }
  }
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= m; j++)
      g << v[i][j] << " ";
    g << endl;
  }
  g.close();
}

// 22

int n, i, j, v[101][101], s1, s2;
int main()
{
  cin >> n;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
      cin >> v[i][j];
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n; j++)
    {
      if (i == j)
        s1 += v[i][j];
      if (j == n - i + 1)
        s2 += v[i][j];
    }
  }
  if (s1 == s2)
    cout <<”Diagonale egale”;
  else if (s1 < s2)
    cout <<”Diagonala secundara”;
  else
    cout <<”Diagonala principala”;
}

// 23

#include <iostream>
#include <fstream>
using namespace std;
ifstream f("matrice.in");
int n, m, i, j, v[101][101], adv;
int main()
{
  f >> n >> m;
  adv = 1;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      f >> v[i][j];
  for (i = 1; i <= n; i++)
    if (v[i][m / 2 + 1] % 2 == 0)
      adv = 0;
  if (adv)
    cout <<”DA”;
  else
    cout <<”NU”;
}

// 24

int n, i, v[101][101], j;
int main()
{
  cin >> n;
  for (j = 0; j < n; j++)
    for (i = 0; i < n; i++)
    {
      if (j % 2 == 0)
        v[i][j] = j * 2 * n + i * 2 + 1;
      else
        v[i][j] = (j + 1) * 2 * n – i * 2 – 1;
    }
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
      cout << v[i][j] <<” ”;
    cout << endl;
  }
}

// 25

int i, j, a[101][101], n, b, c, d;
int main()
{
  cin >> n >> m;
  d = 1;
  b = 0;
  c = 0;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
    {
      while (d % 2 == 0)
      {
        c = b;
        b = d;
        d = b + c;
      }
      a[i][j] = d;
      c = b;
      b = d;
      d = b + c;
    }
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= m; j++)
      cout << a[i][j] << " ";
    cout << endl;
  }
}

// 26

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
char s[101];
int i, inceput, LG;
int main()
{
  cin.get(s, 101);
  strcat(s, " ");
  for (i = 1; i < strlen(s) - 1; i++)
  {
    if (isalpha(s[i]) && s[i + 1] == ' ')
    {
      LG = i - inceput;
      if (LG % 2 == 0)
        s[inceput + LG / 2] = toupper(s[inceput + LG / 2]);
    }

    if (s[i] == ' ' && isalpha(s[i + 1]))
      inceput = i + 1;
  }
  cout << s;
}

// 27

#include <iostream>
#include <cstring>
using namespace std;
char sir[51];
int i, frecv[10], MAX, sol;
int main()
{
  cin.get(sir, 50);
  for (i = 0; i < strlen(sir); i++)
    if (sir[i] >= '0' && sir[i] <= '9')
      frecv[sir[i] - '0']++; // frecvența de apariție a fiecărei cifre
  for (i = 0; i <= 9; i++)
    if (frecv[i] > MAX)
    {
      MAX = frecv[i]; // frecvența maximă
      sol = i;        // cifra cu frecvență maximă
    }
  if (MAX == 0)
    cout << "Nu exista";
  else
    cout << sol;
}

// 28

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
char s[301], *p, c[300][301], aux[301];
int k, i, j;
ifstream fin("text.in");
int main()
{
  fin.get(s, 300);
  p = strtok(s, " ");
  while (p)
  {
    if (strlen(p) % 2 == 1)
      strcpy(c[++k], p);
    p = strtok(0, " ");
  }
  for (i = 1; i < k; i++)
    for (j = i + 1; j <= k; j++)
      if (strcmp(c[i], c[j]) > 0)
      {
        strcpy(aux, c[i]);
        strcpy(c[i], c[j]);
        strcpy(c[j], aux);
      }
  if (k)
    for (i = 1; i <= k; i++)
      cout << c[i] << " ";
  else
    cout << "Nu exista";
}

// 29

#include <iostream>
#include <cstring>
using namespace std;
char s[101], *p;
int i, c, ok;
int main()
{
  cin.get(s, 100);
  p = strtok(s, " ");
  while (p)
  {
    ok = 0;
    for (i = 0; i < strlen(p) - 1; i++)
      if (p[i] == p[i + 1])
        ok = 1;
    if (ok)
      c++;
    p = strtok(0, " ");
  }
  cout << c;
}

// 30

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
char s[101];
int i, inceput, LG;
int main()
{
  cin.get(s, 101);
  strcat(s, " ");
  LG = strlen(s);
  for (i = 1; i < strlen(s) - 1; i++)
  {
    if (isalpha(s[i]) && s[i + 1] == ' ')
      if (tolower(s[inceput]) == tolower(s[i]))
      {
        strcpy(s + inceput, s + i + 1);
        i = inceput;
      }
    if (s[i] == ' ' && isalpha(s[i + 1]))
      inceput = i + 1;
  }
  if (strlen(s) == LG)
    cout << "Nu exista";
  else
    cout << s;
}