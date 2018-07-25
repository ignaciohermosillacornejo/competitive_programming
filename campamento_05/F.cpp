#include <bits/stdc++.h>
using namespace std;
#define debugx(x) cerr << #x << ": " << x << endl
#define rep(i, n) for (int i = 0; i < n; ++i)
#define repx(i,x, n) for (int i = x; i < n; ++i)
#define pb push_back
#define eb emplace_back
typedef long long intt;
typedef vector<intt> vi;
typedef pair<intt, intt> par;
typedef vector<par> vp;
typedef vector<vi> vvi;
typedef vector<intt> vll;
typedef vector<vll> vvll;
typedef vector<vi> graph;
typedef vector<vector<par>> wgraph;
typedef vector<par> vpar;


enum{
    tbegin = 0,
    tend = 1,
    th,
    inter
};

struct triangle{
    double I;
    double D;
    double H;
};

struct event{
    int type;
    int ID;
    int ID2;
    double x;
    double y;
    bool operator<(event& e){
        if(x != e.x) return x > e.x;
        if(type != e.type) return type > e.type;
        if(ID != e.ID) return ID > e.ID;
        return false;
    }
};

struct Point
{
    double x, y;
    Point(double x, double y) : x(x), y(y) {}
    bool operator==(Point& B){
        return x==B.x && y==B.y;
    }
};
double cross(Point &a, Point &b, Point &c)
{
    double dx0 = b.x - a.x, dy0 = b.y - a.y;
    double dx1 = c.x - a.x, dy1 = c.y - a.y;
    return dx0 * dy1 - dx1 * dy0;
}
int orientation(Point &a, Point &b, Point &c)
{
    double tmp = cross(a, b, c);
    return tmp < 0 ? -1 : (tmp == 0 ? 0 : 1);
}
struct line
{
    Point A, B;
    line(double x1, double y1, double x2, double y2) : A(x1, y1), B(x2, y2) {}
    line(Point A, Point B) : A(A), B(B){}
    bool operator&(line &o)
    {
        int o11 = orientation(A, o.A, o.B);
        int o12 = orientation(B, o.A, o.B);
        int o21 = orientation(A, B, o.A);
        int o22 = orientation(A, B, o.B);

        return (o11 != o12) and (o21 != o22);
    }
    Point operator^(line &o)
    {
        double m1 = (B.x - A.x) / (B.y - B.y);
        double m2 = (o.B.x - o.A.x) / (o.B.y - o.B.y);
        if(m1 == m2){
            return A;
        }
        double X = A.x - o.A.x + (o.A.y-A.y)/(m1-m2);
        double Y = m1*(X - A.x) + A.y;
        return {X,Y};
    }
};

int main(){
    int n;
    while(cin>>n){
        vector<triangle> trigs(n);
        rep(i,n) cin>>trigs[i].I >> trigs[i].D >> trigs[i].H;
        priority_queue<event> q;
        vi marked(n,0);
        rep(i,n)
        {
            q.push({tbegin, i, 0, trigs[i].I,0});
            q.push({tend, i, 0, trigs[i].D,0});
            q.push({th, i, 0, (trigs[i].I + trigs[i].D)/2,trigs[i].H});
            repx(j,i+1,n){
                if(trigs[i].D == trigs[j].D && trigs[])
            }
            /*repx(j,i+1,n)
            {
                Point P1(trigs[i].I, 0), P2(trigs[i].D, 0), P3((trigs[i].I + trigs[i].D) / 2, trigs[i].H);
                Point Q1(trigs[j].I, 0), Q2(trigs[j].D, 0), Q3((trigs[j].I + trigs[j].D) / 2, trigs[j].H);
                line L1(P1,P2),L2(P2,P3);
                line R1(Q1, Q2), R2(Q1, Q2);
                if (L1 & R1)
                {
                    Point p = L1 ^ R1;
                    q.push({inter, i, j, p.x, p.y});
                }
                if (L1 & R2)
                {
                    Point p = L1 ^ R2;
                    q.push({inter, i, j, p.x, p.y});
                }
                if (L2 & R1)
                {
                    Point p = L2 ^ R1;
                    q.push({inter, i, j, p.x, p.y});
                }
                if (L2 & R2)
                {
                    Point p = L2 ^ R2;
                    q.push({inter, i, j, p.x, p.y});
                }
            }*/
        }
        event e = q.top();q.pop();
        bool goingUp = true;
        int lastID = e.ID;
        double lastx = e.x;
        double lasty = e.y;
        unordered_set<int> currentID;
        currentID.emplace(e.ID);
        while(!q.empty){
            event e = q.top();q.pop();
            if (e.type == tbegin){
                int j = e.ID;
                for(auto& i: currentID)
                {
                    Point P1(trigs[i].I, 0), P2(trigs[i].D, 0), P3((trigs[i].I + trigs[i].D) / 2, trigs[i].H);
                    Point Q1(trigs[j].I, 0), Q2(trigs[j].D, 0), Q3((trigs[j].I + trigs[j].D) / 2, trigs[j].H);
                    line L1(P1, P2), L2(P2, P3);
                    line R1(Q1, Q2), R2(Q1, Q2);
                    if (L1 & R1)
                    {
                        Point p = L1 ^ R1;
                        q.push({inter, i, j, p.x, p.y});
                    }
                    if (L1 & R2)
                    {
                        Point p = L1 ^ R2;
                        q.push({inter, i, j, p.x, p.y});
                    }
                    if (L2 & R1)
                    {
                        Point p = L2 ^ R1;
                        q.push({inter, i, j, p.x, p.y});
                    }
                    if (L2 & R2)
                    {
                        Point p = L2 ^ R2;
                        q.push({inter, i, j, p.x, p.y});
                    }
                }
            }
        }
    }
}