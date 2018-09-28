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
private:
  Point a, b, c, d;

public:
  Rect(Point a, Point b);
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

int main()
{
  int n;
  scanf("%d", &n);
  while (n--)
  {
    int x1, x2, x3, x4, y1, y2, y3, y4;
    scanf("%d %d %d %d", &x1, &x2, &x3, &x4);
    Rect A(Point(x1, x2), Point(x3, x4));
    scanf("%d %d %d %d", &y1, &y2, &y3, &y4);
    Rect B(Point(y1, y2), Point(y3, y4));
    // std::cout << A.toString() << std::endl;
    // std::cout << B.toString() << std::endl;
    if (A.apart(B))
      printf("Apart\n");
    else if (A.inter(B) || A == B)
      printf("Rectangle\n");
    else if (A.onPoint(B))
      printf("Point\n");
    else
      printf("Line\n");
  }
  return 0;
}