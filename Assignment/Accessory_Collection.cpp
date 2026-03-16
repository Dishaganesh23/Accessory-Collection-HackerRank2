#include <bits/stdc++.h>
using namespace std;

long long sumrange(long long a, long long b) {
    long long res1 = (b * (b + 1)) / 2;
    long long res2 = (a * (a - 1)) / 2;
    return res1 - res2;
}

long long process(long long L, long long A, long long N, long long D) {

    if (A < D) return -1;

    if (D == 1) return L * A;

    long long upperlimit = (N - 1) / (D - 1);
    long long res = 0;

    for (long long x = 1; x <= upperlimit; x++) {

        long long extra = ((N - 1) - (D - 1) * x);

        if (extra + A * x < L) continue;

        long long temp = extra * A;

        long long num = (L - extra) / x;

        long long subtotal = sumrange(A - num + 1, A);
        temp += subtotal * x;

        if ((L - extra) % x != 0) {
            long long last = (L - extra) % x;
            temp += last * (A - num);
        }

        res = max(res, temp);
    }

    if (res == 0) return -1;
    return res;
}

string acessoryCollection(int L, int A, int N, int D) {

    long long ans = process(L, A, N, D);

    if (ans == -1) return "SAD";

    return to_string(ans);
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(),
        [] (const char &x, const char &y) {
            return x == y && x == ' ';
        });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ')
        input_string.pop_back();

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));
        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i));

    return splits;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string LAND_temp;
        getline(cin, LAND_temp);

        vector<string> LAND = split_string(LAND_temp);

        int L = stoi(LAND[0]);
        int A = stoi(LAND[1]);
        int N = stoi(LAND[2]);
        int D = stoi(LAND[3]);

        string result = acessoryCollection(L, A, N, D);

        fout << result << "\n";
    }

    fout.close();
    return 0;
}
