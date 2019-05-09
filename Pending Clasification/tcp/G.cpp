#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define repx(i, a, n) for(int i = a; i < n; i++)
#define eb emplace_back

struct Point{
	int x;
	int y;
};


int distance(Point &a, Point &b)
{
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y) * (a.y - b.y); 
}

bool isTriangleRectangle(Point &a, Point &b, Point &c)
{
	int ab = distance(a, b);
	int bc = distance(b, c);
	int ac = distance(a, c);

	return (ab + bc == ac or ab + ac == bc or bc + ac == ab);
}

int main()
{
	int n; cin >> n;
	vector<Point> points;
	rep(i, n)
	{
		Point p;
		cin >> p.x >> p.y;
		points.eb(p);
	}

	int counter = 0;
	rep(i, n)
	{
		repx(j, i + 1, n)
		{
			repx(k, j + 1, n)
			{
				if (isTriangleRectangle(points[i], points[j], points[k]))
					counter++;
			}
		}
	}
	cout << counter << "\n";
}













