int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize) {
    int total_time = 0;
    for (int i = 0; i < pointsSize - 1; i++) {
        int dx = abs(points[i + 1][0] - points[i][0]);
        int dy = abs(points[i + 1][1] - points[i][1]);
        total_time += (dx > dy) ? dx : dy;
    }
    return total_time;
}