#include<stdio.h>

int main() {
    int n, e;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    // Use fixed size if VLA fails
    int arr[100];  

    printf("Enter the elements of array :\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &e);

    int l = 0, r = n - 1;
    int found = 0;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == e) {
            printf("%d Found at index %d\n", e, mid);
            found = 1;
            break;
        } else if (arr[mid] < e) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    if (!found) {
        printf("Not Found\n");
    }

    return 0;
}
