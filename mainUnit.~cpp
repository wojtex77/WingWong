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
        if ((paddleLeft->Top+62)<(table->Top+table->Height)) paddleLeft->Top += 5;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::timerPaddleLeftUpTimer(TObject *Sender)
{
        if ((paddleLeft->Top-2)>table->Top) paddleLeft->Top -= 5;
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Key == 0x41 ) timerPaddleLeftUp->Enabled=true; //a key
        if (Key == 0x5A ) timerPaddleLeftDown->Enabled=true; //z key
        if (Key == VK_UP ) timerPaddleRightUp->Enabled=true;
        if (Key == VK_DOWN ) timerPaddleRightDown->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Key == 0x41 ) timerPaddleLeftUp->Enabled=false; //a key
        if (Key == 0x5A ) timerPaddleLeftDown->Enabled=false; //z key
        if (Key == VK_UP ) timerPaddleRightUp->Enabled=false;
        if (Key == VK_DOWN ) timerPaddleRightDown->Enabled=false;
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::timerPaddleRightDownTimer(TObject *Sender)
{
        if ((paddleRight->Top+62)<(table->Top+table->Height)) paddleRight->Top += 5;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::timerPaddleRightUpTimer(TObject *Sender)
{
        if ((paddleRight->Top-2)>table->Top) paddleRight->Top -= 5;
}
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
        //left paddle initial positioning
        paddleLeft->Left=((MainForm->ClientWidth/2)-300-(paddleLeft->Width)/2);
        paddleLeft->Top=(table->Top+(table->Height/2)-(paddleLeft->Height/2));

        //right paddle initial positioning
        paddleRight->Left=((MainForm->ClientWidth/2)+300-(paddleRight->Width)/2);
        paddleRight->Top=paddleLeft->Top;
}
//---------------------------------------------------------------------------

