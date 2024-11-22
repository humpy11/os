#include <stdio.h>

void lru(int pages[], int n, int frame_count) {
    int frames[frame_count], page_faults = 0, i, j, found, least_recently_used, least_recent_index;
    int last_used[frame_count];  // Array to store the last used time for each frame

    // Initialize frame array to -1 (empty)
    for (i = 0; i < frame_count; i++) {
        frames[i] = -1;
        last_used[i] = -1;  // Initialize last used times
    }

    // Process each page in the reference string
    for (i = 0; i < n; i++) {
        found = 0;

        // Check if page is already in frame
        for (j = 0; j < frame_count; j++) {
            if (pages[i] == frames[j]) {
                found = 1;
                last_used[j] = i;  // Update last used time for the page
                break;
            }
        }

        // If page is not found in frames, replace the least recently used one
        if (!found) {
            least_recent_index = 0;

            // Find the least recently used page by comparing last used times
            for (j = 1; j < frame_count; j++) {
                if (frames[j] == -1 || last_used[j] < last_used[least_recent_index]) {
                    least_recent_index = j;
                }
            }
            frames[least_recent_index] = pages[i];
            last_used[least_recent_index] = i;  // Update last used time
            page_faults++;
        }

        // Display the current state of frames
        printf("Page: %d -> ", pages[i]);
        for (j = 0; j < frame_count; j++) {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
        }
        printf("\n");
    }

    printf("Total page faults: %d\n", page_faults);
}

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 0, 4};
    int n = sizeof(pages) / sizeof(pages[0]);
    int frame_count = 3; // Number of frames
    lru(pages, n, frame_count);
    return 0;
}
