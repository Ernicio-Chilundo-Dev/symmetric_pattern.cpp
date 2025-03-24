#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

// Função para obter a largura do terminal no Windows
int getTerminalWidth()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int width = 80; // Valor padrão caso falhe

    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
    {
        width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }
    return width;
}

void printPattern(int rows)
{
    int largura_tela = getTerminalWidth();

    for (int i = 1; i <= rows; i++)
    {
        int num_asteriscos = 2 * i - 1;
        int espacos_extras = (largura_tela - num_asteriscos) / 2;
        cout << string(espacos_extras, ' ') << string(num_asteriscos, '*') << endl;
    }

    for (int i = rows - 1; i > 0; i--)
    {
        int num_asteriscos = 2 * i - 1;
        int espacos_extras = (largura_tela - num_asteriscos) / 2;
        cout << string(espacos_extras, ' ') << string(num_asteriscos, '*') << endl;
    }
}

int main()
{
    int rows = 30; // Pode ajustar o número de linhas
    printPattern(rows);
    return 0;
}
