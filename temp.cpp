#include <iostream>
#include <vector>

using namespace std;

struct Booking 
{ 
    int k,s,t;
};

static vector<pair<int,int> > events(const vector<Booking> &s) 
{
    vector<pair<int,int>> e;
    for (int x = 0;x<s.size();x++) 
    {
        e.push_back(make_pair(s[x].s, s[x].k));     
        e.push_back(make_pair(s[x].t, -s[x].k));   
    }
    return e;                                       
}

static vector<Booking> merge(const vector<Booking>& A,const vector<Booking>& B) {
    vector<pair<int,int>> a = events(A);
    vector<pair<int,int>> b = events(B);
    int n1 = a.size(),n2 = b.size();
    int cur = 0;
    int i = 0,j = 0;
    bool hasPrev = false;
    int prevT = -1;
    vector<Booking> out;

    while (i<n1 || j<n2) 
    {
        int t;                                 
        if (i<n1 && (j>=n2 || a[i].first<=b[j].first))
            t = a[i].first;
        else
            t = b[j].first;

        if (hasPrev && cur > 0) 
        {
            if (!out.empty() && out.back().t == prevT && out.back().k == cur) 
            {
                out.back().t = t;
            } 
            else 
            {
                Booking nb;
                nb.k = (int)cur;
                nb.s = prevT;
                nb.t = t;
                out.push_back(nb);
            }
        }
        while (i<n1 && a[i].first == t) 
        {
             cur += a[i].second; 
             i++; 
        }
        while (j<n2 && b[j].first == t) 
        { 
            cur += b[j].second; 
            j++; 
        }

        prevT = t;
        hasPrev = true;
    }
    return out;
}

static vector<Booking> solve(vector<pair<int,int> > &R,int lo,int hi) {
    if (hi-lo == 1) 
    {
        vector<Booking> single;
        Booking b;
        b.k = 1;
        b.s = R[lo].first;
        b.t = R[lo].second;
        single.push_back(b);
        return single;
    }
    int mid = (lo + hi)/2;
    return merge(solve(R,lo,mid), solve(R,mid,hi));
}

vector<Booking> booking(vector<pair<int,int> >& R) {
    if (R.empty()) return vector<Booking>();
    return solve(R, 0, (int)R.size());
}

int main() {
    vector<pair<int,int> > R;
    R.push_back(make_pair(1,3));
    R.push_back(make_pair(15,100));
    R.push_back(make_pair(17,50));
    R.push_back(make_pair(6,19));
    R.push_back(make_pair(24,64));
    R.push_back(make_pair(15,22));
    R.push_back(make_pair(13,74));

    vector<Booking> result = booking(R);
    for (int x = 0;x<result.size();x++)
    {
        cout<<"("<<result[x].k<<","<<result[x].s<<","<<result[x].t<<")"<<endl;
    }

}