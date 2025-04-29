#include <stdio.h>
#include <stdbool.h>

#define MAX 300

// This structure is used to represent a point in the grid
typedef struct {
    int x, y;
} Point;

void dfs(char grid[MAX][MAX], int m, int n, int i, int j)
{
    // Stack based DFS implementation
    Point stack[MAX * MAX];
    int top = -1;

    stack[++top] = (Point){i, j};

    // This while loop will run until the stack is empty
    while (top >= 0)
    {
        Point p = stack[top--];
        int x = p.x, y = p.y;

        // This part checks if the current point is out of bounds or not a land cell
        // If it is, we skip to the next iteration
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != '1')
            continue;

        grid[x][y] = '0';  // Marks this as visited

        // This pushes the adjacent cells onto the stack
        stack[++top] = (Point){x + 1, y};
        stack[++top] = (Point){x - 1, y};
        stack[++top] = (Point){x, y + 1};
        stack[++top] = (Point){x, y - 1};
    }
}

int numIslands(char grid[MAX][MAX], int m, int n)
{
    int count = 0;

    // Iterates through the grid
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (grid[i][j] == '1')
            {
                dfs(grid, m, n, i, j);
                count++;
            }
        }
    }

    return count;
}

int main()
{
    // This is a grid of 1's and 0's
    char grid1[MAX][MAX] = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    int m1 = 4, n1 = 5;

    printf("Output (Grid1): %d\n", numIslands(grid1, m1, n1));  // Output: 1

    char grid2[MAX][MAX] = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    int m2 = 4, n2 = 5;

    printf("Output (Grid2): %d\n", numIslands(grid2, m2, n2));  // Output: 3

    return 0;
}
