#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
using namespace std;
typedef long long LL;

class EllysTeleport {
public:
  LL h[10005];
  int nxt[10005];
  bool vis[10005];
  vector<int> ps;
  int getMax(int N, int H1, int A, int B, int P, int Q, int M) {
    int res = 0;
    MSET(vis, false);
    h[1] = H1;
    for (int i=2; i<=N; i++) {
      h[i] = (h[i-1]*A+B) % M;
    }
    sort(h+1, h+N+1);
    
    for (int i=1; i<=N; i++) {
      LL nn = (h[i] * P + Q) % M;
      int pos = upper_bound(h+1, h+N+1, nn) - h - 1;
      nxt[i] = pos;
    }

    for (int i=1; i<=N; i++) {
      ps.clear();
      int x = i;
      int cnt = 0;
      while (x!=0 && !vis[x]) {
        ps.push_back(x);
        vis[x] = true;
        cnt ++;
        x = nxt[x];
      }
      res = max(res, cnt);
      for (int j: ps) vis[j] = false;
    }
    return res;
  }
};

// CUT begin
ifstream data("EllysTeleport.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(int N, int H1, int A, int B, int P, int Q, int M, int __expected) {
    time_t startClock = clock();
    EllysTeleport *instance = new EllysTeleport();
    int __result = instance->getMax(N, H1, A, B, P, Q, M);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        int N;
        from_stream(N);
        int H1;
        from_stream(H1);
        int A;
        from_stream(A);
        int B;
        from_stream(B);
        int P;
        from_stream(P);
        int Q;
        from_stream(Q);
        int M;
        from_stream(M);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(N, H1, A, B, P, Q, M, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1556708774;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "EllysTeleport (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
