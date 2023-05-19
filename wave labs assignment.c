#include <stdio.h>
#include <math.h>
#include <limits.h>

int* networkQuality(int towers[][3], int towersSize, int radius) {
    int maxQuality = 0;
    int maxCoordinate[2] = {INT_MAX, INT_MAX};

    for (int x = 0; x <= 50; x++) {
        for (int y = 0; y <= 50; y++) {
            int quality = 0;
            for (int i = 0; i < towersSize; i++) {
                int tx = towers[i][0];
                int ty = towers[i][1];
                int tq = towers[i][2];
                double d = sqrt((double) (pow(tx - x, 2) + pow(ty - y, 2)));
                if (d <= radius) {
                    quality += tq / (1 + (int)d);
                }
            }

            if (quality > maxQuality) {
                maxQuality = quality;
                maxCoordinate[0] = x;
                maxCoordinate[1] = y;
            }
        }
    }

    static int result[2];
    result[0] = maxCoordinate[0];
    result[1] = maxCoordinate[1];
    return result;
}

int main() {
    int towers[][3] = {{1, 2, 5}, {2, 1, 7}, {3, 1, 9}};
    int towersSize = sizeof(towers) / sizeof(towers[0]);
    int radius = 2;

    int* result = networkQuality(towers, towersSize, radius);
    printf("[%d, %d]\n", result[0], result[1]);

    return 0;
}