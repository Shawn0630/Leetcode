#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <map>
#include <unordered_map>
#include <cctype>
#include <algorithm>

using namespace std;

int uniquePaths(int m, int n) {

    int paths[m][n];
    paths[0][0] = 1;
    for (int i = 1; i < m; i++) {
        paths[i][0] = paths[i - 1][0];
    }
    for (int j = 1; j < n; j++) {
        paths[0][j] = paths[0][j - 1];
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
        }
    }

    return paths[m - 1][n - 1];     
}