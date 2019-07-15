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


        settingsForm->Close();
}
//---------------------------------------------------------------------------

