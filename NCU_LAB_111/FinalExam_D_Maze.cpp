#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void copy_ary(bool from[50][50], bool to[50][50])
{
    for (int i = 0; i < 50; i++)
    {
        for (int g = 0; g < 50; g++)
        {
            to[i][g] = from[i][g];
        }
    }
}

void print_path(int *trace, int from, pair<int, int> *path)
{
    if (trace[from] == -1)
    {
        printf("(%d,%d) ", path[from].first, path[from].second);
        return;
    }
    print_path(trace, trace[from], path);
    printf("(%d,%d) ", path[from].first, path[from].second);
}

int main()
{
    bool record[700][50][50] = {0};
    pair<int, int> path[1000];
    int trace[1000];
    int size = 0;
    int ptr = 0;
    int X, Y;
    cin >> X >> Y;
    bool m[Y][X];
    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < Y; j++)
        {
            cin >> m[i][j];
        }
    }
    size = 1;
    int dx[] = {0,1,0,-1};
    int dy[] = {1,0,-1,0};
    path[0] = {0, 0};
    int end = -1;
    trace[0] = -1;
    while (size != ptr)
    {
        pair<int, int> position = path[ptr];
        record[ptr][position.first][position.second] = true;
        if (position.first == (X-1) && position.second == (Y-1))
        {
            end = ptr;
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = position.first + dx[i];
            int ny = position.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= X || ny >= Y) continue;
            if (record[ptr][nx][ny]) continue;
            if (m[nx][ny]) continue;
            copy_ary(record[ptr], record[size]);
            record[size][nx][ny] = 1;
            trace[size] = ptr;
            path[size++] = {nx, ny};
        }
        ptr++;
    }
    if (end == -1)
    {
        cout << "Can't reach the exit!";
    }
    else
    {
        print_path(trace, end, path);
    }
}
