//! @file    IOPers.h
//! @brief   Библиотека Самой Гениальных персонажей и прочего для Игры не менее Гениального Ивана Орешкова
//! $Version: 1.0.1

class Hero
{
    private:
    int q=1;
    public:
    HDC people;
    int x, y, xp, yp, a, b, v, hel=10;
    COLORREF color;
    Hero();
    void WATS();
    void Up();
    void Down();
    void Right();
    void Left();
    void Draw();
    void Change();
    ~Hero();
};


Hero::Hero()
{
    people=txLoadImage("game.bmp");
    x=205; y=200; xp=50; yp=71; a=0; b=3; v=50;
    color=RGB(255,174,201);
}

void Hero::WATS() //Указания всех характеристик персонажа
{
    int  s=2;
    char health[80], sila[80];
    txSetColor(TX_LIGHTGRAY);
    txSelectFont("Bookman Old Style", 23);
    if(!GetAsyncKeyState(VK_TAB))
    {
        txDrawText  (500, 50, 700, 65, "Ваши характеристики:");
        txSetColor(TX_ORANGE);
        txSelectFont("Segoe Script", 33);
        sprintf(health, "Здоровье: %d", hel);
        sprintf(sila, "Сила: %d", s);
        txTextOut(502, 80, health);
        txTextOut(502, 110, sila);
    }
    if(hel<=0)                                        //Если здоровье персонажа падает до нуля, показывается текст о проигрыше
    {
        txClear();
        txSetColor(TX_YELLOW);
        txSelectFont("Segoe Script", 40);
        txDrawText  (10, 200, 690, 590, "ВЫ УМЕРЛИ. Пустошь поглотила вас.\n"
        "Энакин, всё кончено, я стою выше тебя!"
        " Нажми (Esc), чтобы с позором уйти");
    }
}

void Hero::Up()
{
    Change();
    y-=v;
    b=219;
}
void Hero::Down()
{
    Change();
    y+=v;
    b=3;
}
void Hero::Right()
{
    Change();
    x+=v;
    b=147;
}
void Hero::Left()
{
    Change();
    x-=v;
    b=75;
}
void Hero::Draw()
{
    if(!GetAsyncKeyState(VK_TAB))
        Win32::TransparentBlt (txDC(), x, y, 35, 45, people, a, b, xp, yp, color);
}
void Hero::Change()
{
    a+=48*q;
    if(a==0)
        q=1;
    if(a>90)
        q=-1;
}
Hero::~Hero()
{
    txDeleteDC(people);
}
