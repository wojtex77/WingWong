//---------------------------------------------------------------------------

#ifndef settingsUnitH
#define settingsUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TsettingsForm : public TForm
{
__published:	// IDE-managed Components
        TLabeledEdit *winingScore;
        TButton *applyButton;
        TButton *discardButton;
        TTrackBar *ballSpeedTrackBar;
        TLabeledEdit *ballSpeed;
        void __fastcall applyButtonClick(TObject *Sender);
        void __fastcall discardButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TsettingsForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TsettingsForm *settingsForm;
//---------------------------------------------------------------------------
#endif
