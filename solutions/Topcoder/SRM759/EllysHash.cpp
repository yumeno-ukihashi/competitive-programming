#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
using namespace std;
using LL = long long;

class EllysHash {
public:
    const int M = 30;
    const LL MOD = 1000000000000037LL;
    LL pw[30];
    string a,b,c;

    void dfs(vector<LL> &alls,int l,int r,int pos,LL cur) {
        if (pos>r) {
            alls.push_back(cur);
            return;
        }
        dfs(alls, l,r, pos+1, (cur*127+a[pos])%MOD);
        dfs(alls, l,r, pos+1, (cur*127+b[pos])%MOD);
        dfs(alls, l,r, pos+1, (cur*127+c[pos])%MOD);
    }
    void init () {
        pw[0] = 1;
        REP(i,1,M-1) pw[i] = pw[i-1] * 127 % MOD;
    }
    void getall(vector<LL> &alls,int N,int l,int r) {
        dfs(alls,l,r,l,0LL);

        __int128 tmp;
        int sft = N-1-r;
        if (sft) {
            REP(i,0,(int)alls.size()-1) {
                tmp = alls[i];
                tmp *= pw[sft];
                tmp %= MOD;
                alls[i] = tmp;
            }
        }
        sort(alls.begin(), alls.end());
        alls.resize( unique(alls.begin(), alls.end()) - alls.begin() );
    }
    long long getHash(int N, string A, string B, string C) {
        a=A; b=B; c=C;
        vector<LL> l,r;
        init();
        getall(l, N, 0, N/2);
        getall(r, N, N/2+1, N-1);
        reverse(l.begin(), l.end());

        auto i1 = r.begin();
        LL ans = (1LL<<61);
        for (auto i:l) {
            while (i1!=r.end() && i+*i1<MOD) i1++;
            auto i2 = r.begin();
            if (i1!=r.end()) ans = min(ans, (i+*i1)%MOD);
            if (i2!=r.end()) ans = min(ans, (i+*i2)%MOD);
        }
        if (ans==(1LL<<61)) ans = l[(int)l.size()-1];
        return ans;
    }
};

// CUT begin
ifstream data("EllysHash.sample");

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

bool do_test(int N, string A, string B, string C, long long __expected) {
    time_t startClock = clock();
    EllysHash *instance = new EllysHash();
    long long __result = instance->getHash(N, A, B, C);
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
        string A;
        from_stream(A);
        string B;
        from_stream(B);
        string C;
        from_stream(C);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(N, A, B, C, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1559128788;
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
        cout << "EllysHash (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
