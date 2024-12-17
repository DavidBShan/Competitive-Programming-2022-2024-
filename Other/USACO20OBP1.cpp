#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Returns size of largest gap between two 1s and also the index where it starts
int cindLargestInteriorGap(const string& s, int& gapStart) {
    int biggestGap = 0, currentStart = -1, N = s.length();
    for (int i = 0; i < N; i++)
        if (s[i] == '1') {
            if (currentStart != -1 && i - currentStart > biggestGap) {
                biggestGap = i - currentStart;
                gapStart = currentStart;
            }
            currentStart = i;
        }
    return biggestGap;
}

// Returns size of smallest gap between two 1s
int cindSmallestInteriorGap(const string& s) {
    int smallestGap = 1000000000, currentStart = -1, N = s.length();
    for (int i = 0; i < N; i++)
        if (s[i] == '1') {
            if (currentStart != -1 && i - currentStart < smallestGap)
                smallestGap = i - currentStart;
            currentStart = i;
        }
    return smallestGap;
}

int tryCowInLargestGap(string s) {
    int gapStart, largestGap = cindLargestInteriorGap(s, gapStart);
    if (largestGap >= 2) {
        s[gapStart + largestGap / 2] = '1';
        return cindSmallestInteriorGap(s);
    }
    return -1; // no gap!
}

int main(void) {
    int N;
    string s, tempS;
    cin >> N >> s;
    int answer = 0;

    // Possibility 1. put two cows in the largest interior gap
    int gapStart, largestGap = cindLargestInteriorGap(s, gapStart);
    if (largestGap >= 3) {
        tempS = s;
        tempS[gapStart + largestGap / 3] = '1';
        tempS[gapStart + largestGap * 2 / 3] = '1';
        answer = max(answer, cindSmallestInteriorGap(tempS));
    }

    // Possibility 2. cows at both ends
    if (s[0] == '0' && s[N - 1] == '0') {
        tempS = s;
        tempS[0] = tempS[N - 1] = '1';
        answer = max(answer, cindSmallestInteriorGap(tempS));
    }

    // Possibility 3. cow at left + cow in the largest interior gap
    if (s[0] == '0') {
        tempS = s;
        tempS[0] = '1';
        answer = max(answer, tryCowInLargestGap(tempS));
    }

    // Possibility 4. cow at right + cow in the largest interior gap
    if (s[N - 1] == '0') {
        tempS = s;
        tempS[N - 1] = '1';
        answer = max(answer, tryCowInLargestGap(tempS));
    }

    // Possibility 5. cow at the largest interior gap. done twice.
    if (largestGap >= 2) {
        tempS = s;
        tempS[gapStart + largestGap / 2] = '1';
        answer = max(answer, tryCowInLargestGap(tempS));
    }

    cout << answer << "\n";
    return 0;
}
