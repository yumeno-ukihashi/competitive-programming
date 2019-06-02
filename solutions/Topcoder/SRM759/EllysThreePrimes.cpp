#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
using namespace std;

class EllysThreePrimes {
public:
    const int MN = 10000;
    const int M = 100000;
    int pw10[5];
    vector<int> p[10];
    vector<int> ps;
    vector<bool> isp;

    void init() {
        isp = vector<bool> (M, true);
        isp[0] = isp[1] = false;
        REP(i,2,M-1) if(isp[i]) {
            if (i>=MN) {
                ps.push_back(i);
                p[i%10].push_back(i);
            }
            for (int j=2*i; j<M; j+=i) isp[j] = false;
        }

        pw10[0] = 1;
        REP(i,1,4) pw10[i] = pw10[i-1] * 10;
    }

    int RAND(int x,int y) {
        int res = rand()*32768 + rand();
        return res % (y-x+1) + x;
    }

    vector<int> getPrimes(vector<int> sums) {
        srand(time(NULL));
        init();
        
        REP(ii,0,9)REP(jj,0,9)REP(kk,0,9) if(ii+jj+kk==sums[0]) {
            REP(i,0,(int)p[ii].size()-1) REP(j,0,(int)p[jj].size()-1) {
                int x = p[ii][i];
                int y = p[jj][j];
                int z = 0;
                REP(tmp,0,4) {
                    int dx = x/pw10[tmp]%10;
                    int dy = y/pw10[tmp]%10;
                    int dz = sums[tmp]-dx-dy;
                    if (dz<0 || dz>9) {
                        z = 0;
                        break;
                    }
                    z += pw10[tmp] * dz;
                }
                if (z>=MN && isp[z] && x!=y && y!=z && x!=z) return {x,y,z};
                //if (isp[z]) return {x,y,z};
            }
        }
        return {};
    }
};

// CUT begin
ifstream data("EllysThreePrimes.sample");

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

template <typename T> string to_string(vector<T> ts) {
    stringstream s;
    s << "[ ";
    for (int i = 0; i < (int)ts.size(); ++i) {
        if (i > 0) s << ", ";
        s << to_string(ts[i]);
    }
    s << " ]";
    return s.str();
}

bool do_test(vector<int> sums, vector<int> __expected) {
    time_t startClock = clock();
    EllysThreePrimes *instance = new EllysThreePrimes();
    vector<int> __result = instance->getPrimes(sums);
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
        vector<int> sums;
        from_stream(sums);
        next_line();
        vector<int> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(sums, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1559127636;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "EllysThreePrimes (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
