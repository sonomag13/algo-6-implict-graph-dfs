//
// Created by lgao23 on 1/15/24.
//

#pragma once

bool inBoundary(int n, int i, int j) {
    // to check if the (i, j) is in the boundary

    bool cond1 = 0 <= i && i < n;
    bool cond2 = 0 <= j && j < n;

    return cond1 && cond2 ? true : false;

}
