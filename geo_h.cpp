#include <bits/stdc++.h>
#define problem "test"
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define ALL(v) (v).begin(),(v).end()
#define UNIQUE(v) (v).resize(unique(ALL(v)) - (v).begin())
#define BIT(x,i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
using namespace std;

struct Point{
    ll x,y;
    Point (ll _x = 0,ll _y = 0){
        x = _x,y = _y;
    }

    friend istream &operator >> (istream &is, Point &pt){
        is>>pt.x>>pt.y;
        return is;
    }
};

struct VecTor{
    ll x,y;
    VecTor (ll _x = 0,ll _y = 0){
        x = _x,y = _y;
    }
    VecTor (Point A,Point B){
        x = B.x - A.x, y = B.y - A.y;
    }

    ll dot(const VecTor &other) const{
        return 1LL*(x*other.x + y*other.y);
    }

    ll cross(const VecTor &other) const{
        return 1LL*(x*other.y - y*other.x);
    }

    double length(){
        return sqrt(x*x + y*y);
    }
};

struct Line{
    ll A,B,C;
    Line (ll _A = 0,ll _B = 0,ll _C = 0){
        A = _A, B = _B, C = _C;
    }
    Line (Point pA,Point pB){
        A = pA.y - pB.y;
        B = pB.x - pA.x;
        C = -1LL*A*pA.x - 1LL*B*pA.y;
    }

    friend istream &operator>>(istream &is,Line &ln){
        return (is>>ln.A>>ln.B>>ln.C);
    }

    int sign(const Point &pt){
        ll val = A*pt.x + B*pt.y + C;
        if (val > 0)    return 1;
        else if (val < 0)   return -1;
        return 0;
    }

    double distance(const Point &pt) const{
        return 1.0*abs(A*pt.x + B*pt.y + C)/sqrt(A*A + B*B);
    }
};

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);

    Point A,B,C;    cin>>A>>B>>C;
    
    cout<<fixed<<setprecision(8);
    if (VecTor(B,A).dot(VecTor(B,C)) > 0 && VecTor(C,A).dot(VecTor(C,B)) > 0)
        cout<<Line(B,C).distance(A);
    else cout<<min(VecTor(B,A).length(),VecTor(C,A).length());
}