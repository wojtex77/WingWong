//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "mainUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;





bool TMainForm::checkGameEnd (int redScore, int blackScore){
        if (redScore==winingResult || blackScore==winingResult) return true;
        else return false;
}

void TMainForm::resetPaddlesAndBallPositions (){
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

void TMainForm::setButtonsConditions (){

        //button START
        startButton->Visible=true;
        startButton->Enabled=true;

        //result label
        result->Visible=false;

        //ball stoped
        timerBall->Enabled=false;

}

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

        resetPaddlesAndBallPositions();
        setButtonsConditions ();
        winingResult=5;
        xBallVelocityPointer=4;
        yBallVelocityPointer=2;
        blackResult=0;
        redResult=0;



        Application->MessageBox("Pokonaj swojego przeciwnika i zostañ mistrzem Wing-Wonga! \nDomyœlnie gra toczy siê do 5 wygranych.\nTe i inne parametry mo¿esz zmieniæ w ustawieniach.","Witaj przysz³y Wing-Wongisto!",MB_OK);



}
//---------------------------------------------------------------------------


void __fastcall TMainForm::timerBallTimer(TObject *Sender)
{

        ball->Left+=xBallVelocityPointer;
        ball->Top+=yBallVelocityPointer;

        //rightPaddle bounce condition
        if (
        ((ball->Left+ball->Width)>=paddleRight->Left)&&
        ((ball->Top+(ball->Height/2))>paddleRight->Top) &&
        ((ball->Top-(ball->Height/2))<(paddleRight->Top+paddleRight->Height)))

                                xBallVelocityPointer=xBallVelocityPointer*(-1);

        //leftPaddle bounce condition
        if (
        ((ball->Left<=(paddleLeft->Left+paddleLeft->Width)))&&
        ((ball->Top+(ball->Height/2))>paddleLeft->Top) &&
        ((ball->Top-(ball->Height/2))<(paddleLeft->Top+paddleLeft->Height)))

                                xBallVelocityPointer=xBallVelocityPointer*(-1);

        //top table band bounce condition
        if (ball->Top<=(table->Top))
                yBallVelocityPointer=yBallVelocityPointer*(-1);

        //bottom table band bounce condition
        if ((ball->Top+ball->Height)>=((table->Top+table->Height)))
                yBallVelocityPointer=yBallVelocityPointer*(-1);

        //right paddle loose condition
        if (ball->Left>=(paddleRight->Left+30)){
                blackResult++;
                resultBlack->Caption=blackResult;
                resetPaddlesAndBallPositions();
                setButtonsConditions ();
                resetButton->Visible=true;
                resetButton->Enabled=true;
                if (checkGameEnd(redResult, blackResult)==true) {
                        result->Caption="CZARNY WYGRYWA!";
                        result->Visible=true;
                        startButton->Enabled=false;
                        }
                }


        //left paddle loose condition
        if (ball->Left<=(paddleLeft->Left-30)){
                redResult++;
                resultRed->Caption=redResult;
                resetPaddlesAndBallPositions();
                setButtonsConditions ();
                resetButton->Visible=true;
                resetButton->Enabled=true;
                if (checkGameEnd(redResult, blackResult)==true) {
                        result->Caption="CZERWONY WYGRYWA!";
                        result->Visible=true;
                        startButton->Enabled=false;
                        }
                }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::startButtonClick(TObject *Sender)
{
        timerBall->Enabled=true;
        startButton->Visible=false;
        startButton->Enabled=false;
        resetButton->Visible=false;
        resetButton->Enabled=false;

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::resetButtonClick(TObject *Sender)
{
        blackResult=0;
        redResult=0;
        resultBlack->Caption=blackResult;
        resultRed->Caption=redResult;
        startButton->Enabled=true;
        result->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::settingsButtonClick(TObject *Sender)
{
        settingsForm->winingScore->Text=winingResult;
        settingsForm->ballSpeedTrackBar->Position=yBallVelocityPointer;
        settingsForm->ShowModal();
}
//---------------------------------------------------------------------------

