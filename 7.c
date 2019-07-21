#include <stdio.h>

typedef struct {
    int value;
    int cnt;
} Item;

Item* search_val(Item* item_array, int size, int n) {
    int i;

    for (i=0; i<size; i++) {
        if (item_array[i].value == n) {
            return item_array+i;
        }
    }
    return NULL;
}

int fill_item_array(Item* item_array, int item_array_allocated_size) {
    int item_array_effective_size = 0; //how many items are actually in array
    int input;
    Item* item_location;

    puts("Enter values");
    while (scanf("%d", &input) == 1) { //legal input
        /* check if number already appeared */
        if (item_location = search_val(item_array, item_array_effective_size, input)) {
            item_location->cnt++;
        } else {
            /* add new number */
            item_array[item_array_effective_size].value = input;
            item_array[item_array_effective_size++].cnt = 1;
        }
    }
    return item_array_effective_size;
}

void print_items(Item* item_array, int size) {
    int i;

    for (i=0; i<size; i++) {
        printf("val: %d\tcnt: %d\n", item_array[i].value, item_array[i].cnt);
    }
}

void print_most_common_item(Item* item_array, int size) {
    if (size <= 0) {
        puts("Array is emtpy!");
        return;
    }
    int max_count = item_array[0].cnt, i;
    Item* most_common = item_array;

    for (i=1; i<size; i++) {
        if (item_array[i].cnt > max_count) {
            max_count = item_array[i].cnt;
            most_common = item_array+i;
        }
    }
    printf("Most common item: %d (appears %d times)\n", most_common->value, most_common->cnt);
}

int main() {
    /* a */
    Item items[] = {
        {3, 1},
        {5, 2},
        {2, 9}
    };
    int to_find = 9;
    printf("The number %d is%s in items\n", to_find,
            search_val(items, sizeof(items)/sizeof(*items), to_find) ? "" : "n't");

    /* b */
    Item uninitialize_items[10];
    int effective_size = fill_item_array(uninitialize_items, 10);
    print_items(uninitialize_items, effective_size);

    /* c */
    print_most_common_item(uninitialize_items, effective_size);

    return 0;
}
