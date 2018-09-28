#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
class Point
{
private:
public:
  int x, y;
  Point()
  {
    this->x = 0;
    this->y = 0;
  }
  Point(int a, int b)
  {
    this->x = a;
    this->y = b;
  }
  bool operator==(Point other)
  {
    return (this->x == other.x &&
            this->y == other.y);
  }
  static int minx(Point a, Point b)
  {
    return ((a.x < b.x) ? a.x : b.x);
  };
  static int miny(Point a, Point b)
  {
    return ((a.y < b.y) ? a.y : b.y);
  };
  static int maxx(Point a, Point b)
  {
    return ((a.x > b.x) ? a.x : b.x);
  };
  static int maxy(Point a, Point b)
  {
    return ((a.y > b.y) ? a.y : b.y);
  };
  std::string toString()
  {
    return "(" + std::to_string(this->x) + "," + std::to_string(this->y) + ")";
  }
};
class Rect
{
public:
  Point a, b, c, d;

  Rect(Point a, Point b);
  Rect(Point a, Point b, Point c, Point d);
  bool operator==(Rect other)
  {
    return (this->a == other.a || this->b == other.b || this->c == other.c || this->d == other.d);
  }
  bool in(Point p)
  {
    return (p.x > this->a.x && p.x < this->c.x && p.y > this->a.y && p.y < this->b.y);
  }
  bool out(Point p)
  {
    return (p.x < this->a.x || p.x > this->c.x || p.y < this->a.y || p.y > this->b.y);
  }

  bool apart(Rect other)
  {
    return (out(other.a) && out(other.b) && out(other.c) && out(other.d));
  }
  bool inter(Rect other)
  {
    return (in(other.a) || in(other.b) || in(other.c) || in(other.d));
  }
  bool onPoint(Rect other)
  {
    return (other.a == this->c || other.b == this->d || other.c == this->a || other.d == this->b);
  }
  std::string toString()
  {
    return "Rect has point " + this->a.toString() + " " + this->b.toString() + " " + this->c.toString() + " " + this->d.toString() + "";
  }
};

Rect::Rect(Point x, Point y)
{
  this->a = Point(Point::minx(x, y), Point::miny(x, y));
  this->b = Point(Point::minx(x, y), Point::maxy(x, y));
  this->c = Point(Point::maxx(x, y), Point::maxy(x, y));
  this->d = Point(Point::maxx(x, y), Point::miny(x, y));
};
Rect::Rect(Point x, Point y, Point z, Point w)
{
  this->a = w;
  this->b = x;
  this->c = y;
  this->d = z;
};
int pow2(int a)
{
  return a * a;
}
class Circle
{
private:
public:
  int r, x, y;
  Circle(int r, int x, int y)
  {
    this->r = r;
    this->x = x;
    this->y = y;
  }
  bool in(Point p)
  {
    return (pow2(p.x - this->x) + pow2((p.y - this->y)) <= pow2(this->r));
  }
  bool include(Rect r)
  {
    return (in(r.a) && in(r.b) && in(r.c) && in(r.d));
  }
};
int main()
{
  int n;
  scanf("%d", &n);
  while (n--)
  {
    int r, x, y;
    scanf("%d %d %d", &r, &x, &y);
    Circle C(r, x, y);
    int m = 4;
    std::vector<Point> p;
    while (m--)
    {
      int x, y;
      scanf("%d %d", &x, &y);
      p.push_back(Point(x, y));
    }
    Rect A(p[0], p[1], p[2], p[3]);
    C.include(A) ? printf("Yes\n") : printf("No\n");
  }
  return 0;
}