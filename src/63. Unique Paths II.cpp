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


int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    int paths[m][n];

    paths[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;

    for (int i = 1; i < m; i++) {
        if (obstacleGrid[i][0] == 1) paths[i][0] = 0; 
        else paths[i][0] = paths[i - 1][0];
    }

    for (int j = 1; j < n; j++) {
        if (obstacleGrid[0][j] == 1) paths[0][j] = 0; 
        else paths[0][j] = paths[0][j - 1];
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[i][j] == 1) paths[i][j] = 0;
            else {
                paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
            }
        }
    }

    return paths[m - 1][n - 1];
}