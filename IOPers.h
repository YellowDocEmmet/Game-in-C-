//! @file    IOPers.h
//! @brief   ���������� ����� ���������� ���������� � ������� ��� ���� �� ����� ����������� ����� ��������
//! $Version: 1.0

class Hero
{
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

void Hero::WATS() //�������� ���� ������������� ���������
{
    int  s=2;
    char health[80], sila[80];
    txSetColor(TX_LIGHTGRAY);
    txSelectFont("Bookman Old Style", 23);
    txDrawText  (500, 50, 700, 65, "���� ��������������:");
    txSetColor(TX_ORANGE);
    txSelectFont("Segoe Script", 33);
    sprintf(health, "��������: %d", hel);
    sprintf(sila, "����: %d", s);
    txTextOut(502, 80, health);
    txTextOut(502, 110, sila);
    if(hel<=0)
    {
        txClear();
        txSetColor(TX_YELLOW);
        txSelectFont("Segoe Script", 40);
        txDrawText  (10, 200, 690, 590, "�� ������. ������� ��������� ���.\n"
        "������, �� �������, � ���� ���� ����!"
        "����� (Esc), ����� � ������� ����");
        txSleep(500);
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
