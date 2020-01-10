//! @file    IOCarta.h
//! @brief   Библиотека Самой Гениальной Карты и прочего для Игры не менее Гениального Ивана Орешкова
//! $Version: 1.0

class Map
{
    int i,j,time=0;
    int A[10][10];
    public:
    int var=0;
    HDC DC;
    HDC NPC;
    COLORREF color;
    Map();
    void First();
    void Second();
    void Third();
    void Draw();
    int Get_cell(int x, int y, int step);
    void Set_cell();
    ~Map();
};
void Text();

//-------------------------------------------------------------------------------
void Text() //Меню игры, будет работать пока вы удерживаете TAB
{




    txSetColor(TX_YELLOW);
    txSelectFont("Segoe Script", 30);
    txDrawText  (500, 10, 625, 35, "Меню(TAB)");
    if(GetAsyncKeyState(VK_TAB))
    {
        txClear();
        txSetColor(TX_GRAY);
        txSelectFont("Segoe Script", 40, 15);
        txDrawText  (100, 50, 600, 450, "Управление:\n Вверх: стрелка вверх\n "
        "Вправо: стрелка вправо\n Влево: стрелка влево\n Вниз: стрелка вниз\n Выход: Esc\n\n\n Создатель: Мудрец Шеш");
    }
}

void Speak()
{
    txSetColor(TX_PINK);
    txSelectFont("Segoe Script", 30);
    txDrawText  (10, 505, 700, 600, "Житель города: Здравствуй, наш король!"
    "Слухи в городе в последнее время только о\n том, что вы потеряли свою дочь.\nЕсли это так, то вам стоит её найти"
    " во что бы то ни стало. Таков путь.");
}
void Speak2()
{
    txSetColor(TX_BROWN);
    txSelectFont("Segoe Script", 31);
    txDrawText  (10, 505, 700, 600, "Житель города: Oh. Hi Mark!\n"
    "Если хочешь пройти дальше, берегись серой брусчатки, она проклята колдуном.");
}
void Speak3()
{
    txSetColor(TX_YELLOW);
    txSelectFont("Segoe Script", 31);
    txDrawText  (10, 505, 700, 600, "Её высочество: Милый папочка\n"
    "Это ты! Так как ты всю жизнь держал меня в замке, я не ориентируюсь"
    " на местности. Я очень рада, что ты нашёл меня)\n");
    txSelectFont("Segoe Script", 40);
    txDrawText  (10, 200, 690, 590, "(нажмите ESC, чтобы закончить игру\n или идите изучать карту дальше)");
}
//-------------------------------------------------------------------------------



Map::Map()
{
    color=TX_WHITE;
    DC =txLoadImage("sheet.bmp");
    NPC=txLoadImage("game.bmp");
}

void Map::First()   //0,1 и 2 дороги, 3 и 4 стены
{
    int B[10][10]= {{4,3,4,3,6,4,3,4,4,4},
                    {4,0,0,4,0,4,0,0,0,3},
                    {3,0,0,0,0,0,0,5,0,3},
                    {4,0,0,0,0,0,0,0,0,4},
                    {4,0,0,0,0,0,0,0,0,4},
                    {3,0,0,0,0,0,0,0,0,3},
                    {4,0,0,0,0,0,0,0,0,4},
                    {4,0,0,0,0,0,0,0,0,4},
                    {3,0,0,0,0,0,0,0,0,4},
                    {3,3,3,4,3,4,3,4,3,3}};
    for(i=0; i<10; i++)
        for(j=0; j<10; j++)
                A[i][j]=B[i][j];
}

void Map::Second()
{
    time++;
    int C[10][10]= {{4,3,4,3,3,4,3,4,4,4},
                    {4,7,3,0,0,0,3,0,3,3},
                    {3,0,3,0,3,0,3,0,0,3},
                    {4,0,0,0,4,0,3,4,0,4},
                    {4,0,4,0,3,0,0,0,0,4},
                    {3,0,4,0,4,3,4,3,0,3},
                    {4,0,3,0,0,3,0,4,0,4},
                    {4,0,4,0,3,4,0,3,0,4},
                    {6,0,4,0,0,0,0,4,0,6},
                    {3,3,3,4,3,4,3,4,3,3}};
    int H[10][10]= {{4,3,4,3,3,4,3,4,4,4},
                    {4,7,3,0,2,0,3,0,3,3},
                    {3,0,3,0,3,0,3,0,0,3},
                    {4,0,2,0,4,0,3,4,2,4},
                    {4,0,4,2,3,2,0,0,0,4},
                    {3,0,4,0,4,3,4,3,0,3},
                    {4,0,3,0,0,3,0,4,0,4},
                    {4,0,4,2,3,4,2,3,2,4},
                    {6,0,4,0,2,0,0,4,0,6},
                    {3,3,3,4,3,4,3,4,3,3}};
    for(i=0; i<10; i++)
        for(j=0; j<10; j++)
            if(time%10<5)
                A[i][j]=H[i][j];
            else
                A[i][j]=C[i][j];
}

void Map::Third()
{
    int F[10][10]= {{4,3,4,3,3,4,3,4,4,4},
                    {4,0,0,0,0,0,3,8,3,3},
                    {3,0,3,0,3,0,3,0,0,3},
                    {4,0,3,0,4,0,3,4,0,4},
                    {4,0,4,0,3,0,0,0,0,4},
                    {3,0,4,0,4,0,4,3,0,3},
                    {4,0,3,0,0,0,0,0,0,4},
                    {4,0,4,0,3,0,0,3,0,4},
                    {4,0,0,0,0,0,0,4,0,3},
                    {3,6,3,4,3,4,3,4,3,3}};
    for(i=0; i<10; i++)
        for(j=0; j<10; j++)
                A[i][j]=F[i][j];
}

void Map::Draw()
{
    COLORREF col=RGB(255,174,201);
    int x=70, s=50;
    for(i=0; i<10; i++)
        for(j=0; j<10; j++)
        {
            if(A[i][j]==0)
                Win32::TransparentBlt (txDC(), 0+s*j, 0+s*i, s, s, DC, 0, 0, x*3, x*3, color);
            if(A[i][j]==1)
                Win32::TransparentBlt (txDC(), 0+s*j, 0+s*i, s, s, DC, x*3, 0, x*3, x*3, color);
            if(A[i][j]==2)
                Win32::TransparentBlt (txDC(), 0+s*j, 0+s*i, s, s, DC, x*6, 0, x*3, x*3, color);
            if(A[i][j]==3)
                Win32::TransparentBlt (txDC(), 0+s*j, 0+s*i, s, s, DC, x*9, x*4, x, x, color);
            if(A[i][j]==4)
                Win32::TransparentBlt (txDC(), 0+s*j, 0+s*i, s, s, DC, x*9, x, x, x, color);
            if(A[i][j]==5)
            {
                Win32::TransparentBlt (txDC(), 0+s*j, 0+s*i, s, s, DC, 0, 0, x*3, x*3, color);
                Win32::TransparentBlt (txDC(), 0+s*j, 0+s*i, 35, 45, NPC, 185, 288, 50, 71, col);
            }
            if(A[i][j]==6)
            {
                Win32::TransparentBlt (txDC(), 0+s*j, 0+s*i, s, s, DC, x*9, x, x, x, color);
                Win32::TransparentBlt (txDC(), 0+s*j, 0+s*i, s, 50, DC, x*10, 0, x, x*2, color);
            }
            if(A[i][j]==7)
            {
                Win32::TransparentBlt (txDC(), 0+s*j, 0+s*i, s, s, DC, 0, 0, x*3, x*3, color);
                Win32::TransparentBlt (txDC(), 0+s*j, 0+s*i, 35, 45, NPC, 185, 0, 50, 71, col);
            }
            if(A[i][j]==8)
            {
                Win32::TransparentBlt (txDC(), 0+s*j, 0+s*i, s, s, DC, 0, 0, x*3, x*3, color);
                Win32::TransparentBlt (txDC(), 0+s*j, 0+s*i, 37, 47, NPC, 330, 0, 50, 71, col);
            }
        }
}
int Map::Get_cell(int x, int y, int step)
{
    return A[y/step][x/step];
}

Map::~Map()
{
    txDeleteDC(DC);
    txDeleteDC(NPC);
}
