//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "settingsUnit.h"
#include "mainUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TsettingsForm *settingsForm;
//---------------------------------------------------------------------------
__fastcall TsettingsForm::TsettingsForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TsettingsForm::applyButtonClick(TObject *Sender)
{
        MainForm->winingResult=winingScore->Text.ToInt();
        MainForm->yBallVelocityPointer=ballSpeed->Text.ToInt();
        MainForm->xBallVelocityPointer=2*ballSpeed->Text.ToInt();

        settingsForm->Close();
}
//---------------------------------------------------------------------------

void __fastcall TsettingsForm::discardButtonClick(TObject *Sender)
{
        settingsForm->Close();
}
//---------------------------------------------------------------------------

void __fastcall TsettingsForm::ballSpeedTrackBarChange(TObject *Sender)
{
        ballSpeed->Text=ballSpeedTrackBar->Position;
}
//---------------------------------------------------------------------------


