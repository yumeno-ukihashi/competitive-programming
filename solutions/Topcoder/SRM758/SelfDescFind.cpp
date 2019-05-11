#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
using namespace std;

class SelfDescFind {
public:
    int n,cnt[20];
    vector<int> in;
    string ans = "";
    
    void dfs(int dep,int sum) {
        if (dep >= n) {
            auto check = [&]() {
                REP(i,0,9) if (cnt[i]) {
                    int x = cnt[i]-1;
                    REP(j,0,9) if (cnt[j]==i && i!=0) x--;
                    if (x) return false;
                }
                return true;
            };
            if (check()) {
                string tmp = "";
                REP(c,1,9) REP(j,0,9) if (cnt[j]==c) {
                    tmp += (char)('0' + c);
                    tmp += (char)('0' + j);
                }
                if (ans=="" || tmp<ans) ans = tmp;
            }
            return;
        }

        REP(i,1,9) if (sum+i<=2*n) {
            if (in[dep]==0 && i!=1) continue;
            if (dep==n-1 && sum+i!=2*n) continue;
            cnt[in[dep]] = i;
            dfs(dep+1, sum+i);
            cnt[in[dep]] = 0;
        }
    }
    string construct(vector<int> digits) {
        in = digits;
        n = (int)in.size();

        MSET(cnt, 0);
        dfs(0, 0);
        return ans;
    }
};

// CUT begin
ifstream data("SelfDescFind.sample");

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

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
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

bool do_test(vector<int> digits, string __expected) {
    time_t startClock = clock();
    SelfDescFind *instance = new SelfDescFind();
    string __result = instance->construct(digits);
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
        vector<int> digits;
        from_stream(digits);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(digits, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1557500454;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 300 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "SelfDescFind (300 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
