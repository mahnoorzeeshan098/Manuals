
void setCursor(bool visible, DWORD size)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (size == 0)
        size = 20;
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;   //to make the cursor visible or not
    lpCursor.dwSize = size;   //Adjusts the size of cursor
    SetConsoleCursorInfo(hConsole, &lpCursor);
}

void drawBorder()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 2); // Green Border