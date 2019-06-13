#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 500005
using namespace std;

class CatAndMice {
public:
    int mob[M], cnt[M], dp[M];
    bool isp[M];
    void init() {
        MSET(isp, true);
        MSET(cnt, 0);
        isp[0] = isp[1] = false;

        REP(i,1,M-1) {
            if (isp[i]) {
                mob[i] = -1;
                for (int j=i*2; j<M; j+=i) {
                    isp[j] = false;
                    if (cnt[j]>=0) cnt[j]++;
                }
                for (long long j=(long long)i*i; j<M; j+=(long long)i*i) {
                    cnt[j] = -1;
                }
            } else {
                if (cnt[i]==-1) mob[i]=0;
                else if(cnt[i]%2) mob[i]=-1;
                else mob[i]=1;
            }
        }

        REP(i,1,M-1) dp[i] = dp[i-1] + mob[i];
    }
    long long getans(int N,int C) {
        int c0 = C;
        C = N/C;
        long long ans = 0;
        int l=1;
        while (l<=C) {
            int c = C/l;
            int r = min(C/c, C);

            ans += (long long)c * c * (dp[r]-dp[l-1]);
            l = r+1;
        }
        if (N>=c0) ans++;
        return ans*4;
    }
    long long countDirections(int N, int C) {
        init();
        return getans(N,C) - getans(N,C+1);
    }
};

// CUT begin
ifstream data("CatAndMice.sample");

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

bool do_test(int N, int C, long long __expected) {
    time_t startClock = clock();
    CatAndMice *instance = new CatAndMice();
    long long __result = instance->countDirections(N, C);
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
        int C;
        from_stream(C);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(N, C, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1560389155;
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
        cout << "CatAndMice (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
