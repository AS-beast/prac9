#include <stdio.h>
int min_steps(int x, int y, int i, int j) { // Створюємо функцію для обрахунків, де х початкове число, у кінцеве число, і кількість кроків, j величина крока
    // printf("%d\n", x); // Для перевірки
    if (y == x + 1) { // Випадок, коли y на одиницю більше за x
        i++;
        return i;
    } else if (y >= x + j) { // Випадок, коли y більше або дорівнює x + j
        int k = j; 
        int x1 = x;
        while (x1 <= y && k != 0) { // Перевіряємо чи j набуло максимального, допустимого значення 
            x1 += k;
            k--;
        }
        int z = y - x1; // Різниця між y і x1
        if (y - x1 == 0 && y - x1 <= j) { // Випадок, коли різниця дорівнює 0 і не перевищує j
            i++;
            return min_steps(x + j, y, i, j); // Викликаємо рекурсивно збільшену функцію min_steps з новими значеннями x та i
        } else if (y - x1 < j || z == 1) { // Випадок, коли різниця менша за j або дорівнює 1
            if (j > 1) {
                j--; 
            } else {
                j = j; 
            }
            i++;
            return min_steps(x + j, y, i, j); // Викликаємо рекурсивно збільшену функцію min_steps з новими значеннями x та i
        } else if (y - x1 >= j && y - x1 != 0) { // Випадок, коли різниця більша або дорівнює j і не дорівнює 0
            j++; 
            i++;
            return min_steps(x + j, y, i, j); // Викликаємо рекурсивно збільшену функцію min_steps з новими значеннями x, i та j
        }
    }
    return i;
}

int main() {
    int x, y;
    printf("x=");
    scanf("%d", &x);
    printf("y=");
    scanf("%d", &y);
    printf("Мінімальна кількість кроків=%d\n", min_steps(x, y, 0, 0));
    return 0;
}
