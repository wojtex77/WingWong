//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "mainUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::timerPaddleLeftDownTimer(TObject *Sender)
{
        paddleLeft->Top += 2;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::timerPaddleLeftUpTimer(TObject *Sender)
{
        paddleLeft->Top -= 2;
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Key == VK_UP) timerPaddleLeftUp->Enabled=true;
        if (Key == VK_DOWN) timerPaddleLeftDown->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Key == VK_UP) timerPaddleLeftUp->Enabled=false;
        if (Key == VK_DOWN) timerPaddleLeftDown->Enabled=false;
}
//---------------------------------------------------------------------------

