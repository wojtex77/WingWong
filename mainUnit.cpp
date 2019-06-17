//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "mainUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;

int xBallVelocity=8;
        int yBallVelocity=1;
        int *xBallVelocityPointer=&xBallVelocity;
        int *yBallVelocityPointer=&yBallVelocity;

//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::timerPaddleLeftDownTimer(TObject *Sender)
{
        if ((paddleLeft->Top+paddleLeft->Height)<((table->Height/2)+190)) paddleLeft->Top += 5;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::timerPaddleLeftUpTimer(TObject *Sender)
{
        if ((paddleLeft->Top)>((table->Height/2)-190)) paddleLeft->Top -= 5;
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
        if ((paddleRight->Top+paddleRight->Height)<((table->Height/2)+190)) paddleRight->Top += 5;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::timerPaddleRightUpTimer(TObject *Sender)
{
        if ((paddleRight->Top)>((table->Height/2)-190)) paddleRight->Top -= 5;
}
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
        //left paddle initial positioning
        paddleLeft->Left=((MainForm->ClientWidth/2)-300-(paddleLeft->Width)/2);
        paddleLeft->Top=(table->Top+(table->Height/2)-(paddleLeft->Height/2));

        //right paddle initial positioning
        paddleRight->Left=((MainForm->ClientWidth/2)+300-(paddleRight->Width)/2);
        paddleRight->Top=paddleLeft->Top;

        //ball initial positioning
        ball->Left=(paddleLeft->Left+paddleLeft->Width+2);
        ball->Top=(paddleLeft->Top+(paddleLeft->Height/2)-(ball->Height/2));


}
//---------------------------------------------------------------------------


void __fastcall TMainForm::timerBallTimer(TObject *Sender)
{

        ball->Left+=*xBallVelocityPointer;
        ball->Top+=*yBallVelocityPointer;

        //rightPaddle bounce condition
        if (
        ((ball->Left+ball->Width)>=paddleRight->Left)&&
        ((ball->Top-(ball->Height/2))>=paddleRight->Top)&&
        ((ball->Top+(ball->Height/2))<=(paddleRight->Top+paddleRight->Height))
                                                        ){
                *xBallVelocityPointer=*xBallVelocityPointer*(-1);
                }
        //leftPaddle bounce condition
        if (ball->Left<=(paddleLeft->Left+paddleLeft->Width))
                *xBallVelocityPointer=*xBallVelocityPointer*(-1);

        //top table band bounce condition
        if (ball->Top<=(table->Top))
                *yBallVelocityPointer=*yBallVelocityPointer*(-1);

        //bottom table band bounce condition
        if ((ball->Top+ball->Height)>=((table->Top+table->Height)))
                *yBallVelocityPointer=*yBallVelocityPointer*(-1);




}
//---------------------------------------------------------------------------

